import matplotlib.pyplot as plt
import numpy as np


Fs = 1e6
sample = 1e6
fc = 300000000/323.6
fm = 1000
x = np.arange(sample)
Cw = np.cos(2 * np.pi * fc * x / Fs)
Mw = np.cos(2 * np.pi * fm * x / Fs)
# plt.plot(x,Cw)
# plt.show()
# plt.plot(x,Mw)
# plt.show()
DSB_SCw = 0.5*(np.cos(2 * np.pi * (fc+fm) * x / Fs) + np.cos(2 * np.pi * (fc-fm) * x / Fs))
plt.plot(x,DSB_SCw)
plt.show()
