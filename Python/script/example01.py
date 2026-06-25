# A first Python program: no preamble, no main, no types
print("++++ executing "+ __file__)

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

################################################
#  This is my first module
###############################################
# This content is accessible upon import
a = 2.3
b = 4.5
c = a/b

def line(x, m=1., q=0.):
    print(f"=== In line === x: {x}, m: {m}, q: {q}")
    return m*x+q

print("__name__ : " +  __name__ + " in " + __file__) #s name=main

# This content is interpreted only if the script is run directly
# It is not, if the module is imported by another script
if __name__ == "__main__":
    print("executing " +  __name__ + " in " + __file__)

    # Print using ''
    print(f'a = {a}, b = {b}, c = {c}')
    print("calling line(): ", line(2., q=2.3))
    print("calling line()", line(0., q=-1.3))

    def p1(x, m=1., q=0.):
        print(f"x: {x}, m: {m}, q: {q}")
        return m*x+q

    print("calling p1(): ", p1(a))
