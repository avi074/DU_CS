import matplotlib.pyplot as plt
import numpy as np

def hist_graph(a:list):
    x = np.array(a)
    fig, ax = plt.subplots(figsize=(10, 8), tight_layout = True)
    ax.hist(x, bins=20)
    plt.title('Simple Histogram')
    plt.show()

# Creating dataset
np.random.seed(23685752)
a = np.random.randn(10000)
hist_graph(a)

