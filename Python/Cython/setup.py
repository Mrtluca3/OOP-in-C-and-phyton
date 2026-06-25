from setuptools import setup  # Import setup to handle the package configuration and build process
from Cython.Build import cythonize  # Import cythonize to compile Cython code into standard C code

# Configure the build extension using cythonize on the target source file
setup(
    ext_modules=cythonize("fib_cython.pyx")  # Convert the .pyx file into a C extension module
)