import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.metrics import confusion_matrix
import pydot

df = pd.read_csv("C:\\DeepLearning_Cloud\\data\\liver.csv")
print(df.head())
print(df.columns)

df_X = df.loc[:, df.columns != 'category']
df_y = df['category']

train_X, test_X, train_y, test_y = \
        train_test_split(df_X, df_y, test_size=0.3, random_state=1234)

model = DecisionTreeClassifier(random_state=1234)
model.fit(train_X, train_y)

#과적합됨
print('Train Accuracy: ', model.score(train_X, train_y))
print('Test Accuracy: ', model.score(test_X, test_y))

pred_y = model.predict(test_X)
confusion_matrix(test_y, pred_y)

#Define learning model(tuning)
model = DecisionTreeClassifier(max_depth=4, random_state=1234)
model.fit(train_X, train_y)

print('Train accuracy: ', model.score(train_X, train_y))
print('Test accuracy: ', model.score(test_X, test_y))

pred_y = model.predict(test_X)
confusion_matrix(test_y, pred_y)

#결정 크리 만들기
'''
unique = df_y.unique().astype(str)

export_graphviz(model, out_file='tree_model.dot', feature_names=train_X.columns, \
                class_names = unique, rounded=True, \
                proportion=False, precision = 2, filled = True)
(graph, ) = pydot.graph_from_dot_file('tree_model.dot', \
                                      encoding='UTF-8')
graph.write_png("decision_tree.png")
'''

####################################################################
#################################SVM################################
####################################################################
from sklearn import svm

model = svm.SVC()
model.fit(train_X, train_y)

print('Train accuracy: ', model.score(train_X, train_y))
print('Test accuracy: ', model.score(test_X, test_y))

pred_y = model.predict(test_X)
confusion_matrix(test_y, pred_y)

model = svm.SVC(kernel='poly')
model.fit(train_X, train_y)

print('Train accuracy: ', model.score(train_X, train_y))
print('Test accuracy: ', model.score(test_X, test_y))

pred_y = model.predict(test_X)
confusion_matrix(test_y, pred_y)

####################################################################
########################### Random Forest ## #######################
####################################################################
from sklearn.ensemble import RandomForestClassifier

model = RandomForestClassifier(n_estimators=10, random_state=1234)
model.fit(train_X, train_y)

print('Train accuracy: ', model.score(train_X, train_y))
print('Test accuracy: ', model.score(test_X, test_y))

pred_y= model.predict(test_X)
confusion_matrix(test_y, pred_y)

#tuning했을 때
model = RandomForestClassifier(n_estimators=50, random_state=1234)
model.fit(train_X, train_y)

print('Train accuracy: ', model.score(train_X, train_y))
print('Test accuracy: ', model.score(test_X, test_y))

pred_y = model.predict(test_X)
confusion_matrix(test_y, pred_y)


####################################################################
############################# XGBoost ##############################
####################################################################
import xgboost as xgb
import numpy as np
from sklearn.metrics import accuracy_score

D_train = xgb.DMatrix(train_X, label=train_y)
D_test = xgb.DMatrix(test_X, label=test_y)

param = {
    'eta' : 0.2,
    'max_depth' : 3,
    'objective' : 'binary:logistic',
    'eval_emtric' : 'error'}

steps = 20
model = xgb.train(param, D_train, steps)

pred = model.predict(D_test)
round_pred = np.round(pred)

accuracy_score(test_y, round_pred)