from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import KFold
from sklearn.metrics import accuracy_score
import numpy as np

#데이터 로드
wine_X, wine_y = datasets.load_wine(return_X_y=True)

kf = KFold(n_splits=5, random_state=123, shuffle=True)

model = svm.SVC()

acc = np.zeros(5)
i = 0

#교차검증 직접 구현
for train_index, test_index in kf.split(wine_X) :
    print("fold: ", i)

    train_X, test_X = wine_X[train_index], wine_X[test_index]
    train_y, test_y = wine_y[train_index], wine_y[test_index]

    model.fit(train_X, train_y)
    pred_y = model.predict(test_X)

    acc[i] = accuracy_score(test_y, pred_y)

    print('accuracy: {0:.3f}' .format(acc[i]))
    print('accuracy: {0:.3f}' .format(acc_score[i]))
    i+=1

print("5 fold : ", acc)
print("mean accuracy: ", np.mean(acc))


#####################################################################
#교차검증 cross_val_score 사용
from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import cross_validate
import numpy as np

wine_X, wine_y = datasets.load_wine(return_X_y=True)

model = svm.SVC()

scores = cross_val_score(model, wine_X, wine_y, cv = 5, scoring='accuracy')
scores_2 = cross_validate(model, wine_X, wine_y, cv = 5, 
                          scoring=['accuracy', 'balanced_accuracy'])
print("fold acc", scores)
print("mean accuracy: ", np.mean(scores))

print("mean acc :", np.mean(scores_2['test_accuracy']))
print("mean balanced-acc :", np.mean(scores_2['test_balanced_accuracy']))


##################################################################
#Hypber parameter tuning
from sklearn.model_selection import GridSearchCV
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
import pandas as pd
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\PimaIndiansDiabetes.csv")

df_X = df.loc[:, df.columns != 'diabetes']
df_y = df['diabetes']

base_model = RandomForestClassifier(random_state=123)
scores = cross_val_score(base_model, df_X, df_y, cv = 5)
base_accuracy = np.mean(scores)
base_accuracy

param_grid = {
    'bootstrap' : [True],
    'max_depth' : [80, 90, 100, 110],
    'max_features' : [2, 3, 'sqrt'],
    'min_samples_leaf' : [3, 4, 5],
    'min_samples_split' : [8, 10, 12],
    'n_estimators' : [100, 200, 300]
}

rf = RandomForestClassifier(random_state=1234)

grid_search = GridSearchCV(estimator= rf, param_grid=param_grid,
                           cv = 5, n_jobs=-1, verbose=2)

grid_search.fit(df_X, df_y)

grid_search.best_score_
best_model = grid_search.best_estimator_
best_scores = cross_val_score(best_model, df_X, df_y, cv = 5)

best_accuracy = np.mean(best_scores)
print(best_accuracy)


#############################################################
#Model Comparsion

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score

from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\PimaIndiansDiabetes.csv")

df_X = df.loc[:, df.columns != 'diabetes']
df_y = df['diabetes']

model = []
model.append(('LR', LogisticRegression(max_iter=10000)))
model.append(('KNN', KNeighborsClassifier()))
model.append(('DT', DecisionTreeClassifier()))
model.append(('RF', RandomForestClassifier()))
model.append(('SVM', svm.SVC()))

results = []
names = []
scoring = 'accuracy'

for name, model1 in model:
    cv_results = cross_val_score(model1,df_X,
                                 df_y, cv = 10, scoring=scoring)
    results.append(cv_results)
    names.append(name)
    msg = "%s:%s (%f)" %(name, cv_results.mean(),
                         cv_results.std())
    
    print(msg)

print(results)
for i in range(0, len(results)):
    print(names[i] + "\t" + str(round(np.mean(results[i]), 4)))
