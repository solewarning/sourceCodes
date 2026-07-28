Model Name

Description

Code Syntax

Simple linear regression

Purpose: To predict a dependent variable based on one independent variable.

Pros: Easy to implement, interpret, and efficient for small datasets.

Cons: Not suitable for complex relationships; prone to underfitting.

Modeling equation: y = b0 + b1x

from sklearn.linear_model import LinearRegression

model = LinearRegression()

model.fit(X, y)

Polynomial regression

Purpose: To capture nonlinear relationships between variables.

Pros: Better at fitting nonlinear data compared to linear regression.

Cons: Prone to overfitting with high-degree polynomials.

Modeling equation: y = b0 + b1x + b2x2 + ...

from sklearn.preprocessing import PolynomialFeatures

from sklearn.linear_model import LinearRegression

poly = PolynomialFeatures(degree=2)

X_poly = poly.fit_transform(X)

model = LinearRegression().fit(X_poly, y)

Multiple linear regression

Purpose: To predict a dependent variable based on multiple independent variables.

Pros: Accounts for multiple factors influencing the outcome.

Cons: Assumes a linear relationship between predictors and target.

Modeling equation: y = b0 + b1x1 + b2x2 + ...

from sklearn.linear_model import LinearRegression

model = LinearRegression()

model.fit(X, y)

Logistic regression

Purpose: To predict probabilities of categorical outcomes.

Pros: Efficient for binary classification problems.

Cons: Assumes a linear relationship between independent variables and log-odds.

Modeling equation: log(p/(1-p)) = b0 + b1x1 + ...

from sklearn.linear_model import LogisticRegression

model = LogisticRegression()

model.fit(X, y)

