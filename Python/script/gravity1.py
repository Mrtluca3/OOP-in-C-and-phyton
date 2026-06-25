# ONLY for Jupyter notebook
#%matplotlib notebook
#%matplotlib inline

# Import modules
import matplotlib.pyplot as plt
import math
import numpy as np

# Gravity on Earth!
g = 9.8   # m/s^2

# Function to test values provided for initial conditions or integration settings
# The 4 parameters that the user will be allowed to customize are:
# 1) the time step (dt)
# 2) the angle at which the bullet is shot (theta)
# 3) the height from which the bullet is shot (h)
# 4) the speed at which the bullet is shot (v0)
# No need for if/elif/else because each logic branch returns its output (specifically, a boolean)
def test_val(var, val):
    # Accept integration steps and initial velocities only if > 0
    if var in ['dt', 'v0']:
        return val>0
    # Accept initial height >= 0
    if var=='h':
        return val>=0
    # Assuming that val can only be 'theta' at this point
    # allow only 0 < theta < 90 [degrees]
    return (val>0 and val<90)

# Function to handle reading in initial conditions and integration settings
def set_param(var):
    # Dictionary of default values
    defaults = {
        'dt':    0.01, # [s] Default value of the time step
        'theta': 23.,  # [deg] Default value of the angle at which the bullet is shot
        'h':     5.,   # [m] Default value of the height from which the bullet is shot
        'v0':    10.,  # [m/s] Default value of the speed at which the bullet is shot
    }
    # Dictionary of info messages to the user
    msgs = {
        'dt': f"Insert dt > 0 in sec (press return for {defaults['dt']} sec): ",
        'theta': f"Insert angle theta in (0,90) degrees (press return for {defaults['theta']} degrees): ",
        'h': f"Insert initial height h in m: (press return for h = {defaults['h']} m): ",
        'v0': f"Insert v_0 > 0 in m/s (press return for {defaults['v0']} m/s): "
    }
    # Start by reading a value and continue until happy with value provided
    while True:
        val_in = input(msgs[var])
        # Allow default value
        if val_in=="":
            val_out = defaults[var]
            break
        # Convert to float...
        try:
            val_out = float(val_in)
        except:
            val_out = -1
        # ...and test value
        if test_val(var, val_out):
            break

    # Convert theta from degrees to radians
    if var=='theta':
        val_out = math.radians(val_out)

    return val_out


# Offer the user the chance to customize values of dt, theta, h, v0
dt = set_param('dt')
theta = set_param('theta')
h = set_param('h')
v0 = set_param('v0')

# Compute initial velocity components
v0x = v0*math.cos(theta)
v0y = v0*math.sin(theta)
print(f"v0_x: {v0x:.3f} m/s \t v0_y: {v0y:.3f} m/s")

# Initial position coordinates
x0 = 0
y0 = h

# "Evolution" functions
def x(t):
    return x0 + v0x*t

def y(t):
    return y0 + v0y*t - 0.5*g*t*t

# Generate list of times for sampling
times = np.arange(0., 1000., dt).tolist()

# Print first 10 elements
print(times[:10])

# Compute x(t_i)
xi = [x(t) for t in times if y(t)>=0.]

# Compute y(t_i)
yi = [y(t) for t in times if y(t)>=0.]

print(f"total steps:\t {len(xi):-4d}")
print(f"last x:\t\t {xi[-1]:.2f}")
print(f"last y:\t\t {yi[-1]:.3f}")

# Plot results...
plt.plot(xi, yi, label='trajectory', color='red', marker='.')
plt.legend()

# ...and make them look good
plt.title('Motion under gravity')
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.grid(True)
plt.xlim(-0.01, max(xi)*1.1)
plt.ylim(-0.01, max(yi)*1.1)

# Only for script
plt.show()
# or use this to save your plot
#plt.savefig("./gravity.png")
