#1번 문제
import pandas as pd
from sklearn import svm
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\liver.csv")

X = df.drop('category', axis=1)
y = df['category']

#hyper parameter - default value
model = svm.SVC(random_state=1234)

#10 fold
roc_aucs = cross_val_score(model, X, y, cv = 10, scoring='roc_auc')
print("mean roc_auc: ", np.mean(roc_aucs))


#2번 문제
import pandas as pd
from sklearn.model_selection import GridSearchCV
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\liver.csv")

X = df.drop('category', axis=1)
y = df['category']

model = RandomForestClassifier(random_state=1234)

param_grid = {
    'bootstrap' : [True],
    'max_depth' : [80, 90, 100, 110],
    'max_features' : [2, 3, 'sqrt'],
    'min_samples_leaf' : [3, 4, 5],
    'min_samples_split' : [8, 10, 12],
    'n_estimators' : [100, 200, 300, 1000]
}

grid_search_rf = GridSearchCV(estimator=model, param_grid=param_grid,
                              cv = 10, n_jobs=-1, verbose=2)
grid_search_rf.fit(X, y)

best_model = grid_search_rf.best_estimator_
print(best_model)
best_scores = cross_val_score(best_model, X, y, cv = 10, scoring='f1')
print(best_scores)
print("mean f1 : ", np.mean(best_scores))


#3번 문제
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn import svm
from sklearn.model_selection import cross_val_score
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\liver.csv")

X = df.drop('category', axis=1)
y = df['category']

models = []
models.append(('LR', LogisticRegression(random_state=1234)))
models.append(('DT', DecisionTreeClassifier(random_state=1234)))
models.append(('RF', RandomForestClassifier(random_state=1234)))
models.append(('SVM', svm.SVC(random_state=1234)))

results = []
names = []
scoring='roc_auc'

for name, model in models:
    cv_result = cross_val_score(model,
                                X, y, cv = 10, scoring=scoring)
    results.append(cv_result)
    names.append(name)
    msg = "%s: %f (%f)" %(name, cv_result.mean(),
                          cv_result.std())
    print(msg)

for i in range(len(results)):
    print(names[i] + str(round(np.mean(results[i]), 4)))

fig = plt.figure()
fig.suptitle('Algorithm Comparison')
ax = fig.add_subplot(111)
plt.boxplot(results)
ax.set_xticklabels(names)
plt.show()

#4번 문제
import pandas as pd
from xgboost import XGBClassifier
from sklearn.model_selection import cross_validate
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\liver.csv")

X = df.drop('category', axis=1)
y = df['category']

model = XGBClassifier(random_state=1234)

scores = cross_validate(model, X, y, cv = 10,
                        scoring=['accuracy', 'balanced_accuracy', 'roc_auc', 'f1'])

print("mean acc: ", np.round(np.mean(scores['test_accuracy']), 3))
print("mean balanced_acc: ", np.round(np.mean(scores['test_balanced_accuracy']), 3))
print("mean roc_acc: ", np.round(np.mean(scores['test_roc_auc']), 3))
print("mean f1: ", np.round(np.mean(scores['test_f1']), 3))
