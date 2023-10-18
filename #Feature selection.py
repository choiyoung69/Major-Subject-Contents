#Feature selection 

import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\data\\PimaIndiansDiabetes.csv")
print(df.head())
print(df.columns)

df_X = df.loc[:, df.columns != 'diabetes']
df_y = df['diabetes']

model = LogisticRegression(solver='lbfgs', max_iter=500)
scores = cross_val_score(model, df_X, df_y, cv=5)
print("mean Acc: ", scores.mean())


############################################################################
#                    feature selection by filter method
############################################################################
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2

test = SelectKBest(score_func=chi2, k=df_X.shape[1])
fit = test.fit(df_X, df_y)

print(np.round(fit.scores_, 3))

f_order = np.argsort(-fit.scores_)
sorted_columns = df.columns[f_order]

model = LogisticRegression(solver='lbfgs', max_iter=500)
for i in range(1, df_X.shape[1]+1):
    fs = sorted_columns[0: i]
    df_X_selected = df_X[fs]
    scores = cross_val_score(model, df_X_selected, df_y, cv=5)
    print(fs.tolist())
    print(np.round((scores.mean()), 4))

#############################################################################
#RFE
#############################################################################
from sklearn.feature_selection import RFE
from sklearn.linear_model import LogisticRegression

model = LogisticRegression(solver='lbfgs', max_iter=500)
rfe = RFE(model, n_features_to_select=4)
fit = rfe.fit(df_X, df_y)

print("Num features: %d" %fit.n_features_)
fs = df_X.columns[fit.support_].tolist()
print("Seleted Features: %s" %fs)

scores = cross_val_score(model, df_X[fs], df_y, cv=5)
print("Acc: ", scores.mean())


#############################################################################
#Forward selection
#############################################################################
from mlxtend.feature_selection import SequentialFeatureSelector as SFS

model = LogisticRegression(solver='lbfgs', max_iter=500)
sfs = SFS(model, 
          k_features=5,
          verbose=2,
          scoring='accuracy',
          cv=5)

sfs = sfs.fit(df_X, df_y)
sfs.subsets_
sfs.k_feature_idx_
sfs.k_feature_names_

scores = cross_val_score(model, df_X[list(sfs.k_feature_names_)], df_y, cv=5)
print("Acc: ", scores.mean())

#############################################################################
#Voting Classfier
#############################################################################
from sklearn.ensemble import VotingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import StandardScaler
import numpy as np

df_X, df_y = load_breast_cancer(return_X_y=True)

sc_data = StandardScaler().fit(df_X)
df_X = sc_data.transform(df_X)

clf_lr = LogisticRegression()
clf_kn = KNeighborsClassifier(n_neighbors=1)
clf_dt = DecisionTreeClassifier(random_state=1)

clf_voting = VotingClassifier(

)

#############################################################################
#Model stacking
#############################################################################
from sklearn.datasets import load_breast_cancer
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import LinearSVC
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
from sklearn.ensemble import StackingClassifier
from sklearn.model_selection import cross_val_score
import numpy as np

df_X, df_y = load_breast_cancer(return_X_y=True)
estimators = [
    ('rf', RandomForestClassifier(n_estimators=10,
                                  random_state=42)),
    ('svr', make_pipeline(StandardScaler(),
                          LinearSVC(random_state=42)))
]

model_1 = StackingClassifier(
    estimators=estimators,
    final_estimator=LogisticRegression())

scores_1 = cross_val_score(model_1, df_X, df_y, cv=5)
print(np.mean(scores_1))

model_2 = StackingClassifier(
    estimators=estimators,
    final_estimator=LogisticRegression(max_iter=500),
    passthrough=True
)

scores_2 = cross_val_score(model_2, df_X, df_y, cv=5)
print(np.mean(scores_2))

estimators = [
    ('rf', RandomForestClassifier(n_estimators=10,
                                  random_state=42)),
    ('svr', make_pipeline(StandardScaler(),
                          LinearSVC(random_state=42))),
    ('lr', LogisticRegression(max_iter=500))
]
from xgboost import XGBClassifier

model_3 = StackingClassifier(
    estimators=estimators,
    final_estimator=XGBClassifier(use_label_encoder=False,
                                  eval_metric='logloss',
                                  random_state=42),

)










