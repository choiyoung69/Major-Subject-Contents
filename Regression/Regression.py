import pandas as pd
##
############iris 데이터셋 확인 ###############
##
iris_data = pd.read_csv("C:\\Users\\young\\Downloads\\Iris.csv")

iris_data.head()
iris_data.head(10)
iris_data.tail()
iris_data.tail(15)

iris_data.shape
type(iris_data)
iris_data.columns
iris_data.columns[:4]

iris_data['Species']
iris_data[['SepalLengthCm', 'SepalWidthCm']]

iris_data.iloc[90,4]
iris_data.iloc[50,0]

iris_data.iloc[10:50, 0:4]
iris_data.iloc[10:50, :]

iris_data.loc[10:50, 'SepalWidthCm']
iris_data.loc[10:50, ['SepalWidthCm', 'SepalLengthCm']]

iris_data.loc[iris_data['Species'] == 'setosa', :]

############################################################################
########################Simple Linear Regression############################
############################################################################
#필요한 모듈 import
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

#단순선형회귀 모델 import
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split

cars = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\대학\\학부연구생\\머신러닝 스터디\\data\\cars.csv")
print(cars)
cars.columns
speed = cars['speed'].to_frame()
speed
dist = cars['dist']

train_X, test_X, train_y, test_y = \
                    train_test_split(speed, dist, test_size=0.2, random_state=12)

model = LinearRegression()
model.fit(train_X, train_y)

pred_y = model.predict(test_X)
print(pred_y)

print(model.predict([[13]]))
print(model.predict([[20]]))

print('Coefficients: {0:.2f}, Intercept {1:.3f}' \
      .format(model.coef_[0], model.intercept_))

#Model evaluation 
print('Mean square error: {0:.2f}' \
      .format(mean_squared_error(test_y, pred_y)))

print('Coefficient of determination: %.2f' 
      % r2_score(test_y, pred_y))

#모델 시각화
plt.scatter(test_X, test_y, color='black')
plt.plot(test_X, pred_y, color='blue', linewidth=3)

plt.xlabel('speed')
plt.ylabel('dist')

plt.show()

###########################################################################
######################  Multiple linear Regression  #######################
###########################################################################
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\대학\\학부연구생\\머신러닝 스터디\\data\\prestige.csv")
print(df)

df_X = df[['education', 'women', 'prestige']]
df_y = df['income']

train_X, test_X, train_y, test_y = \
                    train_test_split(df_X, df_y, test_size=0.2, random_state=123)

model = LinearRegression()
model.fit(train_X, train_y)
pred_y = model.predict(test_X)
print(pred_y)

print('Coefficients: {0:.2f}, {1:.2f}, {2:.2f} Intercept {3:.3f}' \
      .format(model.coef_[0], model.coef_[1], model.coef_[2], \
              model.intercept_))

print('Mean squared error: {0:.2f}' .\
      format(mean_squared_error(test_y, pred_y)))

print('Coefficient of determination: %.2f'
      % r2_score(test_y, pred_y))

my_test_x = np.array([11.44, 8.13, 54.1]).reshape(1, -1)
my_pred_y = model.predict(my_test_x)
print(my_pred_y)
###########################################################################
##########################  Logistic Regression  ##########################
###########################################################################
from sklearn import datasets
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

iris_X, iris_y = datasets.load_iris(return_X_y=True)
print(iris_X.shape)

train_X, test_X, train_y, test_y = \
    train_test_split(iris_X, iris_y, test_size=0.3, random_state=1234)

model = LogisticRegression()

model.fit(train_X, train_y)
pred_y = model.predict(test_X)
print(pred_y)

acc = accuracy_score(test_y, pred_y)
print('Accurancy: {0:.3f}' .format(acc))


