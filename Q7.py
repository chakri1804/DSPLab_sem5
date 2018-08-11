import numpy
import scipy

import matplotlib.pyplot as plt
import numpy as np


Fs = 1e4
sample = 1e4
f1 = 1000
f2 = 2000
f3 = 3000
x = np.arange(sample)
a = np.cos(2 * np.pi * f1 * x / Fs) + 10
b = np.cos(2 * np.pi * f1 * x / Fs) + np.cos(2 * np.pi * f2 * x / Fs) + np.sin(2 * np.pi * f3 * x / Fs)
c = x**2 + np.sin(2 * np.pi * f1 * x / Fs)
# d = np.cos(np.pi * ((x*x+1)/139)) + j*np.sin(np.pi * ((x*x+1)/139))
# plt.plot(x,Cw)
# plt.show()
# plt.plot(x,Mw)
# plt.show()
# AMw = (1+Mw)*np.sin(2 * np.pi * fc * x / Fs)
plt.plot(x,a)
plt.show()
plt.plot(x,b)
plt.show()
plt.plot(x,c)
plt.show()
# plt.plot(x,d)
# plt.show()
