import os
import numpy as np
import matplotlib.pyplot as plt

folder = 'res'
step = 27000000
max_index = 100  # Максимальный индекс файла (h_N.txt)

# Построение графиков
plt.figure(figsize=(10, 6))
filename = os.path.join(folder, f'h_{step}.txt')

data = np.loadtxt(filename)
x = data[:, 0]
h = data[:, 1]
plt.plot(x, h, label=f'h_{step}')

plt.xlabel('x')
plt.ylabel('h(x)')
plt.title(f'Графики h от {step}')
plt.legend(loc='upper right', fontsize='small', ncol=2)
plt.grid(True)
plt.tight_layout()
plt.show()
