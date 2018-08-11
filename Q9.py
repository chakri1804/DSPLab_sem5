import numpy as np
print("Give input number")
N = input()
N = int(N)
x = np.random.normal(0,10**(0.5),N)

mean = np.mean(x)
var = np.var(x)
print(mean)
print(var)

x1 = np.random.normal(0,10**(0.5),N)
x2 = np.random.normal(0,10**(0.5),N)

##########################################
# Two random variables are uncorrelated if
# E(XY)-E(X)E(Y) is zero
##########################################
Corr = np.mean(x1*x2)-(np.mean(x1)*np.mean(x2))
print(Corr)
