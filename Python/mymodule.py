# This is my first module

# This content is accessible upon import
a = 2.3
b = 4.5
c = a/b

def line(x, m=1., q=0.):
    print(f"=== In line === x: {x}, m: {m}, q: {q}")
    return m*x+q

print("__name__ : " +  __name__ + " in " + __file__)


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
