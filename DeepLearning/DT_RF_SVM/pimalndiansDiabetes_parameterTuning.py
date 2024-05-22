import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn import svm
from sklearn.ensemble import RandomForestClassifier
import xgboost as xgb
from xgboost import XGBClassifier
from sklearn.model_selection import GridSearchCV
import random

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\PimaIndiansDiabetes.csv")
print(df.head())
print(df.columns)

df_X = df.loc[:, df.columns != 'diabetes']
df_y = df['diabetes']

train_X, test_X, train_y, test_y = \
    train_test_split(df_X, df_y, test_size=0.3, random_state=1234)

###############################################################
#1) decision Tree
decisionTree_model = DecisionTreeClassifier(random_state=1234)
decisionTree_model.fit(train_X, train_y)

#1.000
print('Train accuracy: %.3f' %decisionTree_model.score(train_X, train_y))
#0.701
print('Test accuracy: %.3f'%decisionTree_model.score(test_X, test_y))

decisionTree_model.get_params()
decision_params = {
    'min_samples_split' : [2, 4, 8, 16],
    'min_samples_leaf' : [1, 2, 4, 8],
    'max_depth' : [None, 5, 10, 20],
    'max_leaf_nodes' : [None, 2, 4, 8, 10]
}

grid_dt = GridSearchCV(decisionTree_model, 
                       param_grid=decision_params, cv = 5,
                       n_jobs=-1)

grid_dt.fit(train_X, train_y)
grid_dt.get_params()
grid_dt
#0.765
print('Train accuracy: %.3f' %grid_dt.score(train_X, train_y))
#0.714
print('Test accuracy: %.3f' %grid_dt.score(test_X, test_y))
#################################################################
#2) SVM
svm_model = svm.SVC(random_state=1234)
svm_model.fit(train_X, train_y)

#0.775
print('Train accuracy: %.3f' %svm_model.score(train_X, train_y))
#0.740
print('Test accuracy: %.3f' %svm_model.score(test_X, test_y))

svm_params = {
    'kernel' : ['rbf', 'sigmoid'],
    'C' : [1.0, 4.5, 5.0],
    'gamma' : ['scale', 0.5]
}

grid_svm = GridSearchCV(svm_model,
                        param_grid=svm_params,
                        cv = 5,
                        n_jobs=-1)
grid_svm.fit(train_X, train_y)
grid_svm.best_params_

#0.797
print('Train accuracy: %.3f' %grid_svm.score(train_X, train_y))
#0.745
print('Test accuracy: %.3f' %grid_svm.score(test_X, test_y))

####################################################################
#3) randomForest 
randomForest_model = RandomForestClassifier(random_state=1234)
randomForest_model.fit(train_X, train_y)

#1.0
print('Train accuracy: %.3f' %randomForest_model.score(train_X, train_y))
#0.753
print('Test accuracy: %.3f' %randomForest_model.score(test_X, test_y))

rf_params = {
    'n_estimators' : [200, 500, 1000],
    'max_features' : ['sqrt', 'log2', None],
    'min_samples_leaf' : [3, 5, 7],
    'min_samples_split' : [2, 3, 5]
}

grid_rf = GridSearchCV(randomForest_model,
                       param_grid=rf_params,
                       cv = 5,
                       n_jobs =-1)

grid_rf.fit(train_X, train_y)
grid_rf.best_params_
#0.957
print('Train accuracy: %.3f' %grid_rf.score(train_X, train_y))
#0.766
print('Test accuracy: %.3f' %grid_rf.score(test_X, test_y))

##################################################################
#4) XGBoost
from sklearn.preprocessing import LabelEncoder

number = LabelEncoder()
train_xgb_y = number.fit_transform(train_y).astype('int')
test_xgb_y = number.fit_transform(test_y). astype('int')

xgb_model = XGBClassifier(random_state=1234)
xgb_model.fit(train_X, train_xgb_y)

#1.0
print('Train accuracy: %.3f' %xgb_model.score(train_X, train_xgb_y))
#0.745
print('Test accuracy: %.3f' %xgb_model.score(test_X, test_xgb_y))

xgb_param = {
    'n_estimators' : [100, 200, 500, 1000],
    'eta' : [0.3, 0.448, 0.5],
    'max_depth' : [6, 9], 
    'gamma' : [1, 2, 3, 4]
}

grid_xgb = GridSearchCV(xgb_model,
                        param_grid=xgb_param,
                        cv = 5,
                        n_jobs=-1,
                        refit=True)
grid_xgb.fit(train_X, train_xgb_y)
grid_xgb.best_params_

#0.860
print('Train accuracy: %.3f' %grid_xgb.score(train_X, train_xgb_y))
#0.758
print('Test accuracy: %.3f' %grid_xgb.score(test_X, test_xgb_y))

#######################################################################

print("[Algorithm: Decision Tree]")
print('Train accuracy: %.3f' %grid_dt.score(train_X, train_y))
print('Test accuracy: %.3f' %grid_dt.score(test_X, test_y)) 
print('\n')
print("[Algorithm: SVM]")
print('Train accuracy: %.3f' %grid_svm.score(train_X, train_y))
print('Test accuracy: %.3f' %grid_svm.score(test_X, test_y))
print('\n')
print("[Algorithm: RandomForest]")
print('Train accuracy: %.3f' %grid_rf.score(train_X, train_y))
print('Test accuracy: %.3f' %grid_rf.score(test_X, test_y))
print('\n')
print("[Algorithm: XGBoost]")
print('Train accuracy: %.3f' %grid_xgb.score(train_X, train_xgb_y))
print('Test accuracy: %.3f' %grid_xgb.score(test_X, test_xgb_y))