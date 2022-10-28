import numpy as np
from sklearn.datasets import make_classification

x, y = make_classification(n_samples = 10000, weights = (0.9, .01))
print(x.shape)

print ("hello")
print("numpy version: " + np.version.version)
import sklearn
print('The scikit-learn version is {}.'.format(sklearn.__version__))