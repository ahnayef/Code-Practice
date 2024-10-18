import math
g = 9.81
m = 68.1
t = 10
v = 40

def f(c):
    return (g * m / c) * (1 - math.exp(-1 * (c / m) * t)) - v

es = 0.5  # Stopping criteria
xl = 12  # Lower bound
xu = 16  # Upper bound
xr = (xl + xu) / 2  # Midpoint


ea = 1  # Approximate error
while ea > es:
    xr_old = xr
    fxl = f(xl)
    fxr = f(xr)
    if fxl * fxr < 0:  # Root lies between xl and xr
        xu = xr
    elif fxl * fxr > 0:  # Root lies between xr and xu
        xl = xr
    xr = (xl + xu) / 2  # New midpoint
    ea = abs((xr - xr_old) / xr) * 100  # Approximate relative error
    print([xr, ea])
