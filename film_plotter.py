import os
import numpy as np
import matplotlib.pyplot as plt

folder = 'res'
# folder = './'
step = 79000000
max_index = 100  # Максимальный индекс файла (h_N.txt)

# Построение графиков
plt.figure(figsize=(10, 6))

field = 'h'
field = 'theta'

filename = os.path.join(folder, f'{field}_{step}.txt')

data = np.loadtxt(filename)
x = data[:, 0]
h = data[:, 1]
plt.plot(x, h, label=f'{field}_{step}')

plt.xlabel('X')
plt.ylabel(f'{field}(X)')
plt.title(f'Графики {field} от {step}')
plt.legend(loc='upper right', fontsize='small', ncol=2)
plt.grid(True)
plt.tight_layout()
# plt.show()
plt.savefig(f'{field}_step={step}.png')