# import numpy as np
# import matplotlib.pyplot as plt

# x, y, z, vx, vy, vz = np.loadtxt("sim.dat", unpack=True)
# t = np.arange(len(x))

# fig, axes = plt.subplots(2, 3, figsize=(8, 6))
# data = [x, y, z, vx, vy, vz]
# labels = ['$x$', '$y$', '$z$', '$v_x$', '$v_y$', '$v_z$']

# for ax, d, label in zip(axes.flat, data, labels):
#     ax.plot(t, d, color='darkcyan')
#     ax.set_title(f'Evolution of {label}')
#     ax.set_xlabel('Time step')
#     ax.set_ylabel(label)
#     ax.grid(True, linestyle='--', alpha=0.7)

# plt.tight_layout()

# import numpy as np
# import matplotlib.pyplot as plt

# x, y, z, vx, vy, vz = np.loadtxt("sim.dat", unpack=True)
# idx = np.arange(0, len(x), max(1, len(x) // 20))

# fig, ax = plt.subplots(figsize=(8, 6))

# ax.plot(x, y, color='steelblue', alpha=0.6, label='Trajectory')

# # Decrease 'scale' to make arrows longer.
# # Increase 'width' to make the lines thicker (easier to see).
# ax.quiver(x[idx], y[idx], vx[idx], vy[idx], 
#           color='red', alpha=1, label='Velocity',
#           angles='xy', scale_units='xy', scale=0.5, 
#           width=0.005, headwidth=3, headlength=4)

# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_aspect('equal')

# ax.legend()
# plt.show()

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

x, y, z, vx, vy, vz = np.loadtxt("sim.dat", unpack=True)
t = np.arange(len(x)) * 0.01  # dt fisico = 0.01

def parabola(t, a, b, c):
    return a * t**2/2 + b * t + c

popt_x, _ = curve_fit(parabola, t, x)
popt_y, _ = curve_fit(parabola, t, y)

x_fit = parabola(t, *popt_x)
y_fit = parabola(t, *popt_y)

fig, axes = plt.subplots(1, 2, figsize=(12, 5))

axes[0].plot(t, x, label='Data', color='steelblue', alpha=0.5)
axes[0].plot(t, x_fit, label=f'Fit: {popt_x[0]:.2}t²/2 + {popt_x[1]:.2}t + {popt_x[2]:.2}', color='red')
axes[0].set_title('X vs Time'); axes[0].set_xlabel('t'); axes[0].legend()

axes[1].plot(t, y, label='Data', color='steelblue', alpha=0.5)
axes[1].plot(t, y_fit, label=f'Fit: {popt_y[0]:.2}t²/2 + {popt_y[1]:.2}t + {popt_y[2]:.2}', color='red')
axes[1].set_title('Y vs Time'); axes[1].set_xlabel('t'); axes[1].legend()

plt.tight_layout()
plt.show()
