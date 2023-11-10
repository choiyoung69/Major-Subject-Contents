from keras.models import Sequential
from keras.layers import Dense
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\liver.csv")
X = df.drop('category',axis = 1).astype('float')
y = df['category']

train_X , test_X, train_y, test_y = train_test_split(X, y, test_size=0.4, random_state=1234)


#define model
epochs = 50
batch_size = 8

model = Sequential()
model.add(Dense(8, input_dim = 6, activation='relu'))
model.add(Dense(8, activation='sigmoid'))
model.add(Dense(8, activation='sigmoid'))
model.add(Dense(1, activation='sigmoid'))


model.summary()

model.compile(loss='binary_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])

disp = model.fit(train_X, train_y,
                 batch_size=batch_size,
                 epochs=epochs,
                 verbose=1,
                 validation_data=(test_X, test_y))

pred = model.predict(test_X)
print(pred)

score = model.evaluate(test_X, test_y, verbose=0)
print('Test loss: ', score[0])
print('test accuracy: ', score[1])