import matplotlib.pyplot as plt
import numpy as np


Fs = 1e6
sample = 1e6
fc = 300000000/323.6
fm = 1000
print("Give Mod. Index:")
k = input()
k = float(k)
x = np.arange(sample)
Cw = np.sin(2 * np.pi * fc * x / Fs)
Mw = np.sin(2 * np.pi * fm * x / Fs)
# plt.plot(x,Cw)
# plt.show()
# plt.plot(x,Mw)
# plt.show()
AMw = (1+k*Mw)*np.sin(2 * np.pi * fc * x / Fs)
plt.plot(x,AMw)
plt.show()
