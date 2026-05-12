def fibonacci(unsigned int N):
    """Calculate the Fibonacci series up to N."""
    cdef unsigned int a, b
    a, b = 0, 1
    while b < N:
        a, b = b, a + b
