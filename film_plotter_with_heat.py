import os
import numpy as np
import matplotlib.pyplot as plt

folder = 'res'
step = 1000000

filename_h = os.path.join(folder, f'h_{step}.txt')
data_h = np.loadtxt(filename_h)
x_h = data_h[:, 0]
h = data_h[:, 1]

filename_theta = os.path.join(folder, f'theta_{step}.txt')
data_theta = np.loadtxt(filename_theta)
x_theta = data_theta[:, 0]
theta = data_theta[:, 1]

plt.figure(figsize=(10, 6))
plt.plot(x_h, h, label='h', color='blue')
plt.plot(x_theta, theta, label='theta', color='red')

plt.xlabel('X')
plt.ylabel('Значения')
plt.title(f'Графики h и theta на шаге {step}')
plt.legend(loc='upper right')
plt.grid(True)
plt.tight_layout()
plt.savefig(f'h_theta_step={step}.png')
# plt.show()
