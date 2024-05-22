from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from keras.layers import Flatten
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
from keras.utils import to_categorical
import numpy as np
import matplotlib.pyplot as plt

def cnn_model():
    model = Sequential()
    model.add(Convolution2D(32, kernel_size=(5, 5), 
                            padding = 'valid',
                            strides = (1, 1),
                            input_shape = (img_rows, img_cols, 1),
                            activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.2))
    model.add(Flatten())
    model.add(Dense(127, activation='relu'))
    model.add(Dense(num_classes, activation='softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer='adam',
                  metrics = ['accuracy'])
    return model
img_rows = 28
img_cols = 28

(X_train, y_train), (X_test, y_test) = mnist.load_data()
X_train, X_test = X_train / 255.0, X_test / 255.0

X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols, 1)
X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols, 1)

y_train = to_categorical(y_train)
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

plt.plot(disp.history['accuracy'])
plt.plot(disp.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'validation'], loc='upper left')
plt.show()