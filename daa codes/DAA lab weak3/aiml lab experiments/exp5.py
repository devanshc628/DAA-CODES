# ------------------------------------------
# STEP 1: Import libraries
# ------------------------------------------
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.impute import SimpleImputer

# ------------------------------------------
# STEP 2: Load Dataset
# ------------------------------------------
# Titanic dataset (from seaborn library)
df = sns.load_dataset("titanic")
print("First 5 rows of dataset:\n")
print(df.head())

# ------------------------------------------
# STEP 3: Check Missing Values
# ------------------------------------------
print("\nMissing values before handling:\n")
print(df.isnull().sum())

# ------------------------------------------
# STEP 4: Handle Missing Values
# ------------------------------------------

# Fill numerical missing values with mean
num_imputer = SimpleImputer(strategy='mean')
df[['age', 'fare']] = num_imputer.fit_transform(df[['age', 'fare']])

# Fill categorical missing values with mode
cat_imputer = SimpleImputer(strategy='most_frequent')
df[['embarked', 'class', 'deck']] = cat_imputer.fit_transform(df[['embarked', 'class', 'deck']])

print("\nMissing values after handling:\n")
print(df.isnull().sum())

# ------------------------------------------
# STEP 5: Detect Outliers using IQR (on 'age' and 'fare')
# ------------------------------------------

def detect_outliers_iqr(data, column):
    Q1 = data[column].quantile(0.25)
    Q3 = data[column].quantile(0.75)
    IQR = Q3 - Q1
    lower_limit = Q1 - 1.5 * IQR
    upper_limit = Q3 + 1.5 * IQR
    outliers = data[(data[column] < lower_limit) | (data[column] > upper_limit)]
    return outliers, lower_limit, upper_limit

# Detect outliers in 'age'
outliers_age, lower_age, upper_age = detect_outliers_iqr(df, 'age')
print(f"\nNumber of outliers in Age: {len(outliers_age)}")

# Detect outliers in 'fare'
outliers_fare, lower_fare, upper_fare = detect_outliers_iqr(df, 'fare')
print(f"Number of outliers in Fare: {len(outliers_fare)}")

# ------------------------------------------
# STEP 6: Handle Outliers (Capping Method)
# ------------------------------------------

df['age'] = np.where(df['age'] > upper_age, upper_age,
                     np.where(df['age'] < lower_age, lower_age, df['age']))

df['fare'] = np.where(df['fare'] > upper_fare, upper_fare,
                      np.where(df['fare'] < lower_fare, lower_fare, df['fare']))

# ------------------------------------------
# STEP 7: Verify After Handling
# ------------------------------------------

print("\nSummary statistics after handling missing values & outliers:\n")
print(df[['age', 'fare']].describe())

# Boxplots to check outliers before/after
plt.figure(figsize=(12,5))

plt.subplot(1,2,1)
sns.boxplot(y=outliers_age['age'])
plt.title("Age - Outliers Detected")

plt.subplot(1,2,2)
sns.boxplot(y=df['age'])
plt.title("Age - After Outlier Handling")

plt.show()
