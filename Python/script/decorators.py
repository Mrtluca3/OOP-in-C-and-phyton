def mass_ratio(x,y):
    print("Original:", x/y)

def decorated_mass_ratio(func):
    def convention(a,b):
        if a < b:
            a,b = b,a
        return func(a,b)
    return convention

mass_ratio(5,10)
decorated_mass_ratio(mass_ratio)(5,10)
new_decorated_mr = decorated_mass_ratio(mass_ratio)
new_decorated_mr(5,10)

@decorated_mass_ratio
def mass_ratio(x,y):
    # "Original:" is replaced with "Decorated:" only for illustrative purposes
    print("Decorated using only for illustrative purposes @:", x/y)

mass_ratio(5, 10)
