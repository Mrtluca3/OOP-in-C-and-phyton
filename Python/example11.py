# This is my first module

print("==== Running example11.py")

a = 2.3
b = 4.5
c = a/b

def line(x, m=1., q=0.):
    print(f"x: {x}, m: {m}, q: {q}")
    return m*x+q

# Print using ''
print(f'a = {a}, b = {b}, c = {c}')


print(line(2., q=2.3))
print(line(0., q=-1.3))
print("==== End of example11.py")
