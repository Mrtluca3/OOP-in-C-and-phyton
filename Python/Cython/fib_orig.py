def fibonacci(N):
    """Calculate the Fibonacci series up to N."""
    a, b = 0, 1
    while b < N:
        a, b = b, a + b
