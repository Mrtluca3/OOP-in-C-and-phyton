import timeit

command = '''fib.fibonacci(100000)'''
its = 100

# Measure the performance of the pure Python calculation
py = timeit.timeit(command,
                   setup='import fib_orig as fib',
                   number=its)

# Measure the performance of the Cythonized calculation
cy = timeit.timeit(command,
                   setup='import fib_cython as fib',
                   number=its, )

# Report comparison 
print(f'Cython is {py/cy} times faster')
