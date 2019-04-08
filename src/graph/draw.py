import matplotlib.pyplot as plt
X, Y = [], []
for line in open('data.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[2])

plt.plot(X, Y)
plt.axvline(x=0.22058956)


plt.xlabel('time [ms]')
plt.ylabel('Pupil size [mm]')
plt.grid(True)

plt.show()
