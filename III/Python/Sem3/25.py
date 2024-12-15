import matplotlib.pyplot as plt
import numpy as np

def graph(height:list, pulse:list):
    x = np.array(height)
    y = np.array(pulse)
    plt.xlabel("Height")
    plt.ylabel("Pulse")
    plt.title("Height v/s Pulse ")
    plt.plot(x,y,'*g-')
    plt.tight_layout()
    plt.show()

h = eval(input("Enter the Heights (use comma to seaperate) : "))
p = eval(input("Enter the Pulses (use comma to seaperate)  : "))
graph(h,p)