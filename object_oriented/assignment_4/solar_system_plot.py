import matplotlib.pyplot as plt
import numpy as np

nlines=3650000

sun = np.loadtxt("sun.txt")
x_sun=np.zeros(shape=(nlines))
y_sun=np.zeros(shape=(nlines))

earth = np.loadtxt("earth.txt")
x_e=np.zeros(shape=(nlines))
y_e=np.zeros(shape=(nlines))

neptune = np.loadtxt("neptune.txt")
x_n=np.zeros(shape=(nlines))
y_n=np.zeros(shape=(nlines))

mars = np.loadtxt("mars.txt")
x_ma=np.zeros(shape=(nlines))
y_ma=np.zeros(shape=(nlines))

venus = np.loadtxt("venus.txt")
x_v=np.zeros(shape=(nlines))
y_v=np.zeros(shape=(nlines))

moon = np.loadtxt("moon.txt")
x_mo=np.zeros(shape=(nlines))
y_mo=np.zeros(shape=(nlines))

mercury = np.loadtxt("merc.txt")
x_me=np.zeros(shape=(nlines))
y_me=np.zeros(shape=(nlines))

jupiter = np.loadtxt("jupiter.txt")
x_j=np.zeros(shape=(nlines))
y_j=np.zeros(shape=(nlines))

saturn = np.loadtxt("saturn.txt")
x_s=np.zeros(shape=(nlines))
y_s=np.zeros(shape=(nlines))

uranus = np.loadtxt("uranus.txt")
x_u=np.zeros(shape=(nlines))
y_u=np.zeros(shape=(nlines))

for i in range(nlines):
    x_sun[i]=sun[i,1]
    y_sun[i]=sun[i,2]
    
    x_e[i]=earth[i,1]
    y_e[i]=earth[i,2]

    x_n[i]=neptune[i,1]
    y_n[i]=neptune[i,2]

    x_ma[i]=mars[i,1]
    y_ma[i]=mars[i,2]

    x_v[i]=venus[i,1]
    y_v[i]=venus[i,2]

    x_mo[i]=moon[i,1]
    y_mo[i]=moon[i,2]

    x_me[i]=mercury[i,1]
    y_me[i]=mercury[i,2]

    x_j[i]=jupiter[i,1]
    y_j[i]=jupiter[i,2]

    x_s[i]=saturn[i,1]
    y_s[i]=saturn[i,2]

    x_u[i]=uranus[i,1]
    y_u[i]=uranus[i,2]
    
plt.plot(x_sun,y_sun)
plt.plot(x_e,y_e)
plt.plot(x_n,y_n)
plt.plot(x_ma,y_ma)
plt.plot(x_v,y_v)
plt.plot(x_me,y_me)
plt.plot(x_j,y_j)
plt.plot(x_s,y_s)
plt.plot(x_u,y_u)
plt.plot(x_mo,y_mo)
plt.show()
