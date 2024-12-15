import matplotlib.pyplot as plt
import numpy as np
import math

def exponential(x_coordinates: list):
    x_axis = np.array(x_coordinates)
    y_axis = np.exp(x_axis)
    plt.plot(x_axis, y_axis)
    plt.grid()
    plt.title("Exponential Curve")
    plt.show()

def cosine():
    x_axis = np.arange((-4 * math.pi), 4 * math.pi, 0.1)
    y_axis = np.cos(x_axis)
    plt.plot(x_axis, y_axis)
    plt.grid()
    plt.title("Cosine Curve")
    plt.show()

cosine()
exponential([5,3,2])