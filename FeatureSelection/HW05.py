import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\ch07_mobile_price.csv")

df_X = df.drop('price_range', axis=1)
df_y = df['price_range']

model = RandomForestClassifier(random_state=1234)
scores = cross_val_score(model, df_X, df_y, cv=10)
print("basic ACC: %.5f" %scores.mean())

#filter-method
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2

chi2 = SelectKBest(score_func=chi2, k=df_X.shape[1])
fit = chi2.fit(df_X, df_y)

f_order = np.argsort(-fit.scores_)
sorted_columns = df.columns[f_order]

print("###########filter method Use###########")
model = RandomForestClassifier(random_state=1234)
for i in range(1, df_X.shape[1]+1):
    fs = sorted_columns[0:i]
    df_X_selected = df_X[fs]
    scores = cross_val_score(model, df_X_selected, df_y, cv=10)
    print(fs.tolist())
    print(np.round(scores.mean(), 4))

#filter method로  가장 높은 정확도를 가진 features들 선택
df_selected = df_X[['ram', 'px_height', 'battery_power', 'px_width', 'mobile_wt']]
print("filter method - selected features: ", df_selected.columns)

#########################################################################3
#RFE
from sklearn.feature_selection import RFE

print("###########RFE Use###########")
model = RandomForestClassifier(random_state=1234)
for i in range(1, len(df_selected.columns) + 1):
    rfe = RFE(model, n_features_to_select=i)
    fit = rfe.fit(df_selected, df_y)
    print("Num Features: %d" %fit.n_features_)
    fs = df_selected.columns[fit.support_].tolist()
    print("Selected Features: %s" %fs)

    scores = cross_val_score(model, df_X_selected[fs], df_y, cv=10)
    print("Acc: %.4f" %scores.mean())

print("Best features: ['ram', 'px_height', 'battery_power', 'px_width', 'mobile_wt']")
print("Best feature acc: 0.9215")
#########################################################################
#SFS
from mlxtend.feature_selection import SequentialFeatureSelector as SFS

print("###########SFS Use###########")
model = RandomForestClassifier(random_state=1234)
sfs = SFS(model,
          k_features=df_selected.shape[1],
          verbose=2,
          scoring='accuracy',
          cv=10)

sfs = sfs.fit(df_selected, df_y)

print("best features:" ,sfs.k_feature_names_)
scores = cross_val_score(model, df_selected[list(sfs.k_feature_names_)], df_y, cv=10)
print("Best features acc: ", np.round(scores.mean(), 4))



df_final_X = df_X[['ram', 'px_height', 'battery_power', 'px_width', 'mobile_wt']]
print("finally selected features: ", df_final_X.columns)
model = RandomForestClassifier(random_state=1234)
scores = cross_val_score(model, df_final_X, df_y, cv=10)
print("final ACC: %.4f" %np.mean(scores))