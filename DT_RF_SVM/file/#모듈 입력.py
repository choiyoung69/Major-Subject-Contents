#모듈 입력
import pandas as pd
from sklearn.preprocessing import LabelEncoder
import numpy as np
from sklearn.impute import IterativeImputer
from imblearn.over_sampling import SMOTE
from sklearn.metrics import mean_squared_error
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import r2_score
from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

#filter method dataframe 만드는 함수
def filter_method_df(method, n):
    test = SelectKBest(score_func=method, k=n)
    fit = test.fit(X, y)
    f_order = np.argsort(-fit.scores_)
    return raw_df.columns[f_order]

#k-fold
def average_score(model, X, y):
    mae, mse, rmse, r2 = 0,0,0,0
    smote = SMOTE(k_neighbors= 5, random_state=1234)
    for i in range(10):
        skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=i)
        
        for train_index, test_index in skf.split(X,y):
            train_X, test_X = X.iloc[train_index], X.iloc[test_index]
            train_y, test_y = y.iloc[train_index], y.iloc[test_index]

            #train_X, train_y= smote.fit_resample(train_X, train_y)

            #모델 학습
            model.fit(train_X, train_y)
            pred_y = model.predict(test_X)

            #모델 평가
            mae += mean_absolute_error(test_y, pred_y)
            mse = mean_squared_error(test_y, pred_y)
            rmse += np.sqrt(mse)
            r2 += r2_score(test_y, pred_y)

    return mae/50, rmse/50, r2/50


#filter method
def filter_method_score(model, X, filter_df):
    for i in range(1, X.shape[1] + 1):
        fs = filter_df[0:i]
        X_selected = X[fs]
        mae, rmse, r2 = average_score(model, X_selected, y)
        print(fs.tolist())
        print(np.round(mae, 3), np.round(rmse, 3), np.round(r2, 3))

raw_df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\THRA\\230629_THRA_Raw_data_정리본.csv")

raw_df.shape

#encoding
number = LabelEncoder()
raw_df['Gender'] = number.fit_transform(raw_df['Gender']).astype('int')

raw_df['Gender']
#오류가 나는 열 처리(value!에러와 str 값 섞인 열)
raw_df.loc[123, 'Days(OP-Cause)']
raw_df = raw_df.replace('#VALUE!', np.nan)

for i in range(len(raw_df)):
    raw_df.loc[i, 'Days(OP-Cause)'] = float(raw_df.loc[i, 'Days(OP-Cause)'])

raw_df['Days(OP-Cause)'] = raw_df['Days(OP-Cause)'].astype('float')

raw_df['Days(OP-Cause)']

#NULL 데이터 확인 -- 50% 넘으면 제거하고 filter method 이용한 이용한 다음에 결측값 처리하기
raw_df.isnull().sum()
#null값이 반 이상을 차지하는 column 제거
drop_columns = list()

for i in range(len(raw_df.columns)):
    if raw_df[raw_df.columns[i]].isnull().sum() >= 50:
        drop_columns.append(raw_df.columns[i])

raw_df = raw_df.drop(drop_columns, axis = 1)

#(226, 41)
raw_df

#최종 dataFrame을 위한 raw_df 저장
df = raw_df
df_y = raw_df['Discharge state']

#class가 4, 5, 6, 7이면서 특정 행에 null 값이 하나만 포함되어 있는 경우
for i in range(len(raw_df)):
    if(raw_df.loc[i, 'Discharge state'] == 4 or raw_df.loc[i, 'Discharge state'] == 5 or\
       raw_df.loc[i, 'Discharge state'] == 6 or raw_df.loc[i, 'Discharge state'] == 7) \
        and (raw_df.loc[i, :].isnull().sum() == 1):
        #print(i,"행의 null 값 데이터의 개수는 " , raw_df.loc[i, :].isnull().sum())
        print(raw_df.columns[raw_df.iloc[i].isnull()])

#class 4, 5, 6, 7 이면서 null 값이 하나만 있는 경우
#모두 Date(IA-OP) columns 에서 null 발생
raw_df = raw_df.drop('Date(IA-OP)', axis=1)

#null 있는 데이터 모두 삭제
raw_df = raw_df.dropna()
raw_df


#클래스 불균형 해결
raw_df['Discharge state'].value_counts()

raw_df.columns.get_loc('Discharge state')
#null 데이터를 버리면 6 class 사라짐/4, 5, 7 class 를 모두 4로 합침
for i in range(len(raw_df)):
    if(raw_df.iloc[i, 33] == 5 or raw_df.iloc[i, 33] == 7):
        raw_df.iloc[i, 33] = 4
raw_df['Discharge state'].value_counts()


#X, y 변수로 나누기
raw_df = raw_df.drop(['Group1', 'Group2', 'Group3', 'Group4',
       'Group5(class)', 'Group6'], axis= 1)
X = raw_df.drop(['Discharge state'], axis= 1)
y = raw_df['Discharge state']

X_columns = X.columns

#표준화
scaler = StandardScaler()
scaler.fit(X)
X = scaler.transform(X)
X = pd.DataFrame(data=X, columns=X_columns)

######################################################################
###########################Feature Selection##########################
######################################################################
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestRegressor
from xgboost import XGBRegressor
from sklearn.svm import SVR
from sklearn.model_selection import StratifiedKFold

###Feature Selection 전####
#LogisticRegression
model = LogisticRegression(solver= 'liblinear',max_iter=10000, random_state=1)

#mae : 0.621, rmse: 0.913, r2: -0.828
mae, rmse, r2 = average_score(model, X, y)
print("mae: %0.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#RandomForestRegression
model = RandomForestRegressor()

#mae: 0.572, rmse: 0.722, r2: -0.127
mae, rmse, r2  = average_score(model, X, y)
print("mae: %0.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#XGBoostClassfier
model = XGBRegressor()

import warnings
warnings.filterwarnings("ignore")

#mae: 0.621, rmse: 0.790, r2:-0.356
mae, rmse, r2  = average_score(model, X, y)
print("mae: %0.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

##### 1.filter method
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import f_regression
from sklearn.feature_selection import mutual_info_regression

#1) LogisticRegression, 둘 다 모든 feature를 넣었을 떄가 가장 성능 좋음
model = LogisticRegression(solver='liblinear', max_iter=10000, random_state=1)

#func = f_regression
df_fregression = filter_method_df(f_regression, X.shape[1])
filter_method_score(model, X, df_fregression)
#func = mutual_info_regression
df_mutual = filter_method_df(mutual_info_regression, X.shape[1])
filter_method_score(model, X, df_mutual)

logi_X = X.loc[:, ['Age', 'Gender', 'Insert', 'Pre_Hip ER_MMT', 'Premorbid status', 'Pre_Hip flex_MMT', \
               'Pre_Hip abd_MMT', 'Pre_Hip extensor_MMT', 'Pre_Hip add_MMT', \
'Post_Hip flex_PROM', 'Post_Hip flex_MMT', 'Post_Hip extensor_MMT', 'Post_Hip add_MMT', \
'Osteoporosis', 'Days(OP-GD)', 'Pre_Hip abd_PROM', 'Cause of THRA', \
'Post_Hip abd_MMT', 'Steroid', 'Traumatic/Non-traumatic', 'Head', 'Pre_Hip add_MMT']]

#2) RandomForestRegression
model = RandomForestRegressor(random_state=1)

#func = f_regression
df_rf_fregression = filter_method_df(f_regression, X.shape[1])
filter_method_score(model, X, df_rf_fregression)
#func = mutual_info_regression
df_rf_mutual = filter_method_df(mutual_info_regression, X.shape[1])
filter_method_score(model, X, df_rf_mutual)

rf_X = X.loc[:,['Age', 'Post_Hip extensor_PROM', 'Pre_Hip flex_MMT', 'Post_Hip extensor_MMT', 'Post_Hip add_PROM', 'Pre_Hip ER_MMT', 'Gender', 'Post_Hip add_MMT', 'Duration of PTx.', 'Post_Hip flex_PROM', 'Pre_Hip add_MMT', 'Post_Hip flex_MMT', 'Pre_Hip abd_MMT', 'Head', 'Post_Hip abd_MMT', 'Steroid', 'Days(OP-GD)', 'Insert', 'Premorbid status', 'Pre_Hip extensor_MMT']]

#3) XGBoost
model = XGBRegressor()

#func = f_regression 
df_xgb_fregression = filter_method_df(f_regression, X.shape[1])
filter_method_score(model, X, df_xgb_fregression)
#func = mutual_info_regression 
df_xgb_mutual = filter_method_df(mutual_info_regression, X.shape[1])
filter_method_score(model, X, df_xgb_mutual)

xgb_X = X.loc[:, ['Age', 'Pre_Hip abd_MMT', 'Post_Hip flex_PROM', 'Pre_Hip add_MMT', 'Pre_Hip ER_MMT', 'Post_Hip flex_MMT', 'Pre_Hip flex_PROM', 'Pre_Hip flex_MMT', 'Traumatic/Non-traumatic', 'Pre_Hip abd_PROM', 'Post_Hip extensor_PROM', 'Duration of PTx.', 'Pre_Hip extensor_MMT', 'Days(OP-GD)', 'Gender', 'Insert', 'Premorbid status', 'Post_Hip extensor_MMT', 'Post_Hip add_MMT', 'Osteoporosis', 'Cause of THRA']]


#2. RFE
from sklearn.feature_selection import RFECV

#1) LogisticRegression 
model = LogisticRegression(solver='liblinear', max_iter=10000, random_state=1)

rfecv = RFECV(estimator=model, step=1, cv=5)
fit = rfecv.fit(logi_X, y)
print("num Features: %d" %fit.n_features_)
fs = logi_X.columns[fit.support_].tolist()
print("selected Features: %s" %fs)

mae, rmse, r2 = average_score(model, X[fs], y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#2) RandomForestRegression 
model = RandomForestRegressor(random_state=1)

rfecv = RFECV(estimator=model, step=1, cv=5)
fit = rfecv.fit(rf_X, y)
print("num Features: %d" %fit.n_features_)
fs = rf_X.columns[fit.support_].tolist()
print("selected Features: %s" %fs)

mae, rmse, r2 = average_score(model, rf_X[fs], y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#3) XGBoost 
model = XGBRegressor(random_state=1)

rfecv = RFECV(estimator=model, step=1, cv=5)
fit = rfecv.fit(xgb_X, y)
print("num Features: %d" %fit.n_features_)
fs = xgb_X.columns[fit.support_].tolist()
print("selected Features: %s" %fs)

mae, rsme, r2 = average_score(model, xgb_X[fs], y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#3. SFS
from mlxtend.feature_selection import SequentialFeatureSelector as SFS

#1) LogisticRegression 
model = LogisticRegression(solver='liblinear', max_iter=10000, random_state=1)
sfs = SFS(model,
        k_features=logi_X.shape[1],
        verbose=2,
        scoring='neg_mean_absolute_error',
        cv = 5)
sfs = sfs.fit(logi_X, y)
sfs.subsets_
X_logi_sfs = logi_X[['Age', 'Gender', 'Pre_Hip ER_MMT', 'Premorbid status', 'Pre_Hip flex_MMT', 'Pre_Hip abd_MMT', 'Pre_Hip extensor_MMT', 'Pre_Hip add_MMT', 'Post_Hip flex_PROM', 'Osteoporosis', 'Days(OP-GD)', 'Pre_Hip abd_PROM', 'Cause of THRA', 'Head', 'Pre_Hip add_MMT']]
mae, rmse, r2 = average_score(model, X_logi_sfs, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)


#2) RandomForestRegression
warnings.filterwarnings("ignore")
model = RandomForestRegressor()
sfs = SFS(model,
        k_features=rf_X.shape[1],
        verbose=2,
        cv = 5,
        scoring='neg_mean_absolute_error')
sfs = sfs.fit(rf_X, y)
sfs.subsets_
X_rf_sfs = X[['Pre_Hip flex_MMT', 'Post_Hip add_PROM', 'Pre_Hip ER_MMT', 'Gender', 'Pre_Hip add_MMT', 'Head', 'Premorbid status']]
mae, rmse, r2 = average_score(model, X_rf_sfs, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#3) XGBoost
model = XGBRegressor(random_state=1)
sfs = SFS(model,
        k_features=xgb_X.shape[1],
        verbose=2,
        scoring='neg_mean_absolute_error',
        cv = 5)
sfs = sfs.fit(xgb_X, y)
sfs.subsets_
X_xgb_sfs = X[['Pre_Hip add_MMT', 'Pre_Hip flex_MMT', 'Gender', 'Premorbid status', 'Osteoporosis']]
mae, rmse, r2 = average_score(model, X_xgb_sfs, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#Permutation 
#Logistic_regression
from sklearn.inspection import permutation_importance
import time

model = LogisticRegression(solver= 'liblinear',max_iter=10000, random_state=1)
model = model.fit(logi_X, y)
result = permutation_importance(model, logi_X, y, n_repeats= 5, random_state= 40, n_jobs = -1)

importances_idx = result.importances_mean.argsort()
importances = pd.DataFrame(
    result.importances_mean[importances_idx].T,
    index = logi_X.columns[importances_idx],
)

for i in range(1, len(logi_X.columns)):
    index = importances[len(importances) - i : len(importances) + 1].index
    df_logi = logi_X[index]
    model = LogisticRegression(solver= 'liblinear',max_iter=10000, random_state=1)
    mae, rmse, r2 = average_score(model, df_logi, y)
    print("{} 개의 {}를 사용했을 때 정확도 : {}" .format(i, index, mae))

logi_final_X = X.loc[:, ['Cause of THRA', 'Steroid', 'Days(OP-GD)', 'Pre_Hip abd_MMT',
       'Premorbid status', 'Pre_Hip add_MMT', 'Pre_Hip add_MMT',
       'Pre_Hip flex_MMT', 'Pre_Hip abd_PROM', 'Post_Hip flex_PROM',
       'Pre_Hip extensor_MMT', 'Gender', 'Age']]

mae, rmse, r2 = average_score(model, logi_final_X, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#RandomForest Forest
from sklearn.inspection import permutation_importance

model = RandomForestRegressor()
model = model.fit(rf_X, y)
result = permutation_importance(model, rf_X, y, n_repeats= 5, random_state= 40, n_jobs = -1)

importances_idx = result.importances_mean.argsort()
importances = pd.DataFrame(
    result.importances_mean[importances_idx].T,
    index = rf_X.columns[importances_idx],
)

for i in range(1, len(rf_X.columns)):
    index = importances[len(importances) - i : len(importances) + 1].index
    df_rf = rf_X[index]
    model = RandomForestRegressor()
    mae, rmse, r2 = average_score(model, df_rf, y)
    print("{} 개의 {}를 사용했을 때 정확도 : {}" .format(i, index, mae))

rf_final_X = X.loc[:, ['Pre_Hip abd_MMT', 'Post_Hip add_MMT', 'Pre_Hip add_MMT',
       'Post_Hip abd_MMT', 'Premorbid status', 'Post_Hip extensor_PROM',
       'Post_Hip add_PROM', 'Post_Hip flex_MMT', 'Insert',
       'Post_Hip flex_PROM', 'Pre_Hip ER_MMT', 'Days(OP-GD)', 'Gender', 
       'Duration of PTx.', 'Age']]

mae, rmse, r2 = average_score(model, rf_final_X, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#XGBoost
model = XGBRegressor(random_state=1)
model = model.fit(xgb_X, y)
result = permutation_importance(model, xgb_X, y, n_repeats= 5, random_state= 40, n_jobs = -1)

importances_idx = result.importances_mean.argsort()
importances = pd.DataFrame(
    result.importances_mean[importances_idx].T,
    index = xgb_X.columns[importances_idx],
)

for i in range(1, len(xgb_X.columns)):
    index = importances[len(importances) - i : len(importances) + 1].index
    df_xgb = xgb_X[index]
    model = XGBRegressor(random_state=1)
    mae, rmse, r2 = average_score(model, df_xgb, y)
    print("{} 개의 {}를 사용했을 때 정확도 : {}" .format(i, index, mae))

xgb_final_X = X.loc[:, ['Cause of THRA', 'Days(OP-GD)', 'Post_Hip flex_PROM',\
'Post_Hip flex_MMT', 'Pre_Hip flex_PROM', 'Gender', 'Duration of PTx.',\
'Age']]

mae, rmse, r2 = average_score(model, xgb_final_X, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

###############################################################################
#최종
###############################################################################
model = LogisticRegression(solver='liblinear', max_iter=10000, random_state=10)

X_logi_final = X[['Age', 'Gender', 'Premorbid status', 'Pre_Hip flex_MMT', \
'Pre_Hip extensor_MMT', 'Post_Hip flex_PROM']]

mae, rmse, r2 = average_score(model, X_logi_final, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

#########################
#null 값 제거 전 dataframe
logi_df = df[['Age', 'Gender', 'Premorbid status', 'Pre_Hip flex_MMT', \
'Pre_Hip extensor_MMT', 'Post_Hip flex_PROM']]

logi_df.isnull().sum()

#mice null 값 처리
mice = IterativeImputer(random_state=123) 
logi_df = pd.DataFrame(mice.fit_transform(logi_df), columns=logi_df.columns)

from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

model = LogisticRegression(solver='liblinear', max_iter=10000, random_state=10)

param = {
    'penalty' : ['l1', 'l2'],
    'C' : [0.1, 0.5, 1, 5,  10],
    'solver' : ['lbfgs', 'liblinear', 'sag']
}

grid_search = GridSearchCV(estimator=model, param_grid=param,
                           cv=5, n_jobs=-1, verbose=2)
grid_search.fit(logi_df, df_y)
best_lg_model = grid_search.best_estimator_
mae, rmse, r2 = average_score(best_lg_model, logi_df, df_y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

train_X, test_X, train_y, test_y = train_test_split(logi_df, df_y, test_size=0.3,
                                                    random_state=1)
best_lg_model.fit(train_X, train_y)
pred_y = best_lg_model.predict(test_X)
print(pred_y)
acc = accuracy_score(test_y, pred_y)
print("Logistic Regression acc: %.3f" %acc)


################################################################################
#Random Forest
################################################################################
model = RandomForestRegressor()
X_rf= X[['Age', 'Gender', 'Duration of PTx.', 'Pre_Hip flex_MMT', 'Post_Hip add_PROM', 'Pre_Hip ER_MMT']]
mae, rmse, r2 = average_score(model, X_rf, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)


######################
#null 값 처리
rf_df = df[['Age', 'Gender', 'Duration of PTx.', 'Pre_Hip flex_MMT', 'Post_Hip add_PROM', 'Pre_Hip ER_MMT']]

rf_df.isnull().sum()

#mice null 값 처리
mice = IterativeImputer(random_state=123) 
rf_df = pd.DataFrame(mice.fit_transform(rf_df), columns=rf_df.columns)

from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

model = RandomForestRegressor(random_state=10)

param = {
'bootstrap': [True],
'max_depth': [80, 90, 100, 110],
'max_features': [2, 3, 'sqrt'],
'min_samples_leaf': [3, 4, 5],
'min_samples_split': [8, 10, 12],
'n_estimators': [100, 200, 300, 1000]
}

grid_search = GridSearchCV(estimator=model, param_grid=param,
                           cv=5, n_jobs=-1, verbose=2)
grid_search.fit(rf_df, df_y)
best_rf_model = grid_search.best_estimator_
mae, rmse, r2 = average_score(best_rf_model, rf_df, df_y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

train_X, test_X, train_y, test_y = train_test_split(rf_df, df_y, test_size=0.3,
                                                    random_state=1)
best_rf_model.fit(train_X, train_y)
pred_y = best_rf_model.predict(test_X)
print(pred_y)
pred_y = np.round(pred_y)
acc = accuracy_score(test_y, pred_y)
print("RandomForest Regression acc: %.3f" %acc)

###########################################################################
#XGBoost
###########################################################################
model = XGBRegressor()
X_xgb = X[['Age', 'Gender', 'Duration of PTx.', 'Pre_Hip flex_PROM', 'Post_Hip flex_MMT', 'Osteoporosis']]
mae, rmse, r2 = average_score(model, X_xgb, y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)
######################
#null 값 처리
rf_df = df[['Age', 'Gender', 'Duration of PTx.', 'Pre_Hip flex_MMT', 'Post_Hip add_PROM', 'Pre_Hip ER_MMT']]

rf_df.isnull().sum()

#mice null 값 처리
mice = IterativeImputer(random_state=123) 
rf_df = pd.DataFrame(mice.fit_transform(rf_df), columns=rf_df.columns)

from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score

model = RandomForestRegressor(random_state=10)

param = {
'bootstrap': [True],
'max_depth': [80, 90, 100, 110],
'max_features': [2, 3, 'sqrt'],
'min_samples_leaf': [3, 4, 5],
'min_samples_split': [8, 10, 12],
'n_estimators': [100, 200, 300, 1000]
}

grid_search = GridSearchCV(estimator=model, param_grid=param,
                           cv=5, n_jobs=-1, verbose=2)
grid_search.fit(rf_df, df_y)
best_rf_model = grid_search.best_estimator_
mae, rmse, r2 = average_score(best_rf_model, rf_df, df_y)
print("MAE: %.3f" %mae)
print("rmse: %.3f" %rmse)
print("R2: %.3f" %r2)

train_X, test_X, train_y, test_y = train_test_split(rf_df, df_y, test_size=0.3,
                                                    random_state=1)
best_rf_model.fit(train_X, train_y)
pred_y = best_rf_model.predict(test_X)
print(pred_y)
pred_y = np.round(pred_y)
acc = accuracy_score(test_y, pred_y)
print("RandomForest Regression acc: %.3f" %acc)
