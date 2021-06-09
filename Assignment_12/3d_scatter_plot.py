from matplotlib import pyplot
from matplotlib.animation import FuncAnimation
from mpl_toolkits.mplot3d import Axes3D
import numpy as np



def parse_file():
    with open("simulation.out") as f:
        data = list()
        axies = list() 
        content = f.readlines()
        for line in content:
            if line == '\n':
                data.append(axies)
                axies = list()
                continue
            numbers=line.split(" ")
            axe = list()
            for number in numbers[0:-1]: #because of \n at line end
                axe.append(float(number))
            axies.append(axe)
    return data

def plot():
    data = parse_file()
    f = pyplot.figure()
    ax1 = pyplot.subplot(projection='3d')
    scat = ax1.scatter(data[0][0],data[0][1],data[0][2])
    title = ax1.set_title('3D Test')

    def anim(i):
        j = i % len(data)
        scat._offsets3d = (data[j][0],data[j][1],data[j][2])
        title.set_text('iteration={}'.format(j))

    anim = FuncAnimation(f, anim, interval=50)
    anim.save("test.gif")
    pyplot.show()

plot()