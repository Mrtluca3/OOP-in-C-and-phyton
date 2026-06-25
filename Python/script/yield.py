def basic_gen():
    yield "Almost"
    yield "Done"

a = basic_gen()
print(type(a))
print(dir(a))
print(a)
[print(aa) for aa in a]


# Unlike return, which terminates the function,
# yield pauses it and can be called multiple times
def odds(i):
    for i in range(i):
        if i%2==1:
            yield i

for xmax in range(1,5):
    print(f'Odd numbers from 0 to {xmax-1}:')
    x_gen = odds(xmax)
    print(type(x_gen))
    [print(f'   {x}') for x in x_gen]

print("------------FIBONACCI-----------")
# Generators are memory-efficient: they generate values
# on-the-fly instead of storing everything in memory
def fibonacci():
    a, b = 0, 1
    # Endless sequence
    while True:
        yield a
        a, b = b, a + b

# The following does not create an infinite number of Fibonacci numbers and
# store them, but is ready to go through as many as needed (10 in this case)
gen = fibonacci()
[print(next(gen), end=' ') for i in range(7)]
print("")
[print(next(gen), end=' ') for i in range(7)]
print("")
# [print(a, end=' ') for a in gen] This would never stop since yield are infinite
print("")
print("------------Parrot-------------")

# The send() method allows you to send a value to the generator
def parrot():
    # This too is virtually endless
    while True:
        received = yield
        print("Received:", received)


gen = parrot()

# Start the generator
next(gen) #this arrives to yield and stops
#start sending
gen.send("Hello")
gen.send("World")
# while True:
#     gen.send(input())

# The close() method stops the generator
gen.close()
gen.send("Can you hear me?")

