###########################################################
#########################실습 1번###########################
###########################################################
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import numpy as np

#iris 데이터셋 load
iris_df = pd.read_csv("C:\\DeepLearning_Cloud\\data\\iris.csv")

petal_Length = iris_df['Petal.Length'].to_frame()
petal_Width = iris_df['Petal.Width']

train_X, test_X, train_y, test_y = \
        train_test_split(petal_Length, petal_Width, test_size=0.3, random_state=1234)

#모델 훈련
#실습 1-1
model = LinearRegression()
model.fit(train_X, train_y)
pred_y = model.predict(test_X)

#실습 1-2 mean_squared_error와 r2_score
print('Mean squared error: {0:.2f}' \
      .format(mean_squared_error(test_y, pred_y)))

print('Coefficient of determination: {0:.2f}' \
      .format(r2_score(test_y, pred_y)))

#실습 1-3 coefficients와 intercept의 값
print('Coefficients: {0:.2f}, Intercept: {1:.3f}'\
        .format(model.coef_[0], model.intercept_))

#실습 1-4 1.0, 1.2, 1.4일때 꽃잎의 폭을 예측
my_test_X = pd.DataFrame({"Petal.Length" : [1.0, 1.2, 1.4]})
my_pred_y = model.predict(my_test_X)
print('꽃잎의 폭 예측값: ' , my_pred_y)

###########################################################
#########################실습 2번###########################
###########################################################
from sklearn.linear_model import LinearRegression
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
import numpy as np

boston_df = pd.read_csv("C:\\DeepLearning_Cloud\\data\\BostonHousing.csv")
boston_df = boston_df.drop('chas', axis=1)

boston_X = boston_df.drop('medv', axis=1)
boston_y = boston_df['medv']

train_X, test_X, train_y, test_y = \
        train_test_split(boston_X, boston_y, test_size=0.3, random_state=1234)

#실습 2-1
model = LinearRegression()
model.fit(train_X, train_y)

pred_y = model.predict(test_X)

#실습 2-2
print('Mean squared error: {0:.2f}' \
      .format(mean_squared_error(test_y, pred_y)))
print('coefficient of determination: {0:.2f}' \
      .format(r2_score(test_y, pred_y)))


#실습 2-3
coef_list = ["{:.2f}" .format(model.coef_[i]) \
             for i in range(len(boston_X.columns))]
print('Coefficients: ', coef_list, "Intercept {0:.3f}" \
      .format(model.intercept_))

###########################################################
#########################실습 3번###########################
###########################################################
from sklearn import datasets
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
import pandas as pd
from sklearn.model_selection import train_test_split
import numpy as np

X, y = datasets.load_wine(return_X_y=True)

train_X, test_X, train_y, test_y = train_test_split(X, y, test_size=0.3, random_state=1234)

#실습 3-1번
model = LogisticRegression(max_iter=100000)
model.fit(train_X, train_y)

#실습 3-2번
#train set
pred_train_y = model.predict(train_X)
acc_train = accuracy_score(train_y, pred_train_y)
print("train set에 대한 예측 정확도: " , acc_train)

#test set
pred_test_y = model.predict(test_X)
acc_test = accuracy_score(test_y, pred_test_y)
print("test set에 대한 예측 정확도: " ,acc_test)