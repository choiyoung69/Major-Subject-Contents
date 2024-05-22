from keras.models import Sequential
from keras.layers import Dense
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\iris.csv")
dataset = df.values
X = dataset[:, 0:4].astype('float')
y = dataset[:, 4]

#encoder
encoder = LabelEncoder()
encoder_y = encoder.fit_transform(y)
dummy_y = pd.get_dummies(encoder_y).values

train_X , test_X, train_y, test_y = train_test_split(X, dummy_y, test_size=0.4, random_state=1234)

#define model
epochs = 50
batch_size = 10

model = Sequential()
model.add(Dense(10, input_dim = 4, activation='relu'))
model.add(Dense(10, activation='relu'))
model.add(Dense(3, activation='softmax'))


model.summary()

model.compile(loss='categorical_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])

disp = model.fit(train_X,train_y,
                 batch_size=batch_size,
                 epochs=epochs,
                 verbose=1,
                 validation_data=(test_X, test_y))

pred = model.predict(test_X)
print(pred)
y_classes = [np.argmax(y, axis=None, out=None) for y in pred]
print(y_classes)

score = model.evaluate(test_X, test_y, verbose=0)
print('Test loss: ', score[0])
print('test accuracy: ', score[1])

plt.plot(disp.history['accuracy'])
plt.plot(disp.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.show()