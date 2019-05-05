import matplotlib.pyplot as plt
import os
X, Y= [], []

for line in open('data.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[2])

plt.plot(X, Y)
#plt.plot(X,Y,'b+',color='g')


plt.xlabel('time [ms]')
plt.ylabel('Pupil size [mm]')
plt.grid(True)

plt.show()


