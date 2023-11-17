import numpy as np
from keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from keras.layers import Flatten
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
import os

def cnn_model():
    model = Sequential()
    model.add(Convolution2D(32, kernel_size=(5, 5), 
                            padding = 'valid',
                            strides = (1, 1),
                            input_shape = (28, 28, 3),
                            activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.2))
    model.add(Flatten())
    model.add(Dense(127, activation='relu'))
    model.add(Dense(10, activation='softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer='adam',
                  metrics = ['accuracy'])
    return model


img_dir_train = "C:\\Users\\young\\OneDrive\\바탕 화면\\data\\mnist_png\\training"
img_dir_test = "C:\\Users\\young\\OneDrive\\바탕 화면\\data\\mnist_png\\testing"

flist_train = os.listdir(img_dir_train)
flist_test = os.listdir(img_dir_test)

from keras.preprocessing import image

X_train = np.zeros(shape=(len(flist_train), 28, 28, 3))
y_train = np.zeros(shape=(len(flist_train)))

for idx, fname in enumerate(flist_train):
    img_path = os.path.join(img_dir_train, fname)
    img = image.load_img(img_path, target_size=(28, 28))
    img_array_train = image.img_to_array(img)
    img_array_train = np.expand_dims(img_array_train, axis=0)
    X_train[idx] = img_array_train
    y_train[idx] = flist_train

X_test = np.zeros(shape=(len(flist_test), 28, 28, 3))
y_test = np.zeros(shape=(len(flist_test)))

for idx, fname in enumerate(flist_test):
    img_path = os.path.join(img_dir_test, fname)
    img = image.load_img(img_path, target_size=(28, 28))
    img_array_test = image.img_to_array(img)
    img_array_test = np.expand_dims(img_array_test, axis=0)
    X_test[idx] = img_array_test
    y_test[idx] = flist_test

X_train = X_train / 255.0
X_train = X_train.reshape(X_train.shape[0], 28, 28, 3)
y_train = to_categorical(y_train)

X_test = X_test / 255.0
X_test = X_test.reshape(X_test.shape[0], 28, 28, 3)
y_test = to_categorical(y_test)


seed = 100
np.random.seed(seed)
num_classes = 10

model = cnn_model()
disp = model.fit(X_train, y_train,
                 validation_data = (X_test, y_test),
                 epochs = 10,
                 batch_size = 200,
                 verbose= 1)


scores = model.evaluate(X_test, y_test, verbose= 0)
print("loss: %.2f" %scores[0])
print("acc: %.2f" %scores[1])



