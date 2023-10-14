#############################################################################
#HW5
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score
from sklearn.ensemble import StackingClassifier
import numpy as np

df = pd.read_csv("C:\\Users\\young\\OneDrive\\바탕 화면\\ch07_mobile_price.csv")

df_X = df[['ram', 'px_height', 'battery_power', 'px_width', 'mobile_wt']]
df_y = df['price_range']

estimators = [
    ('rf', RandomForestClassifier(random_state=1234)),
    ('dt', DecisionTreeClassifier(random_state=1234)),
    ('svm', SVC(random_state=1234))
]

model = StackingClassifier(estimators=estimators, \
                           final_estimator=LogisticRegression(random_state=1234, max_iter=10000))

scores = cross_val_score(model, df_X, df_y, cv=10)
print("Acc: %.3f" %np.mean(scores))