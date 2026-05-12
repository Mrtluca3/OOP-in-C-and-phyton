# A first Python program: no preamble, no main, no types
a = 2.3
b = 4.5
c = a/b

# Plain print
print(a, b, c)

# Plain print of more variable types
print('c = a/b = ', c)

# printf style works, but Python introduced the power of f-strings!
# A literal string, prefixed with 'f', containing expressions within {}
print(f'c = a/b = {c}')

# Print using single or double quotation marks
print(f"a = {a}, b = {b}, c = {c}")
print(f'a = {a}, b = {b}, c = {c}')

# Python style formatted output: {position:format}
# format syntax: minimum width . significant digits (for g), digits after the point (for f)
print(f'a = {b:.3f}, b = {c:.3g}, c = {a:2.4g}')

# Woah... calculate on the fly without separate declarations
print(f'value = {a:.3f}, error = {a/b:.3g}, # measurements = {int(b*1000):3d}')
