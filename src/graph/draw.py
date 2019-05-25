import matplotlib.pyplot as plt
import os

class PointBuilder:
    def __init__(self, line):
        self.line = line
        self.xs = list(line.get_xdata())
        self.ys = list(line.get_ydata())
        self.cid = line.figure.canvas.mpl_connect('button_press_event', self)
        self.cid = line.figure.canvas.mpl_connect('key_press_event', self)

    def __call__(self, event):
        if event.inaxes!=self.line.axes: return
        if event.name == 'button_press_event':
            if event.key == 'f2':
                self.xs=list()
                self.ys=list()
                for line in open('realData.txt', 'r'):
                    values = [float(s) for s in line.split()]
                    self.xs.append(values[0])
                    self.ys.append(values[1])
                print("loaded")
                self.line.set_data(self.xs, self.ys)
                self.line.figure.canvas.draw()

                return

X, Y= [], []

for line in open('data.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[2])

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xlabel('time [ms]')
ax.set_ylabel('Pupil size [mm]')
ax.grid()
line, = ax.plot(X[0], Y[0],marker='x', color='r', markersize=5, linestyle= '')  # empty line
ax.plot(X,Y)
linebuilder = PointBuilder(line)

plt.show()
