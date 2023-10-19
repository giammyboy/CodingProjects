from setuptools import setup
from Cython.Build import cythonize
import numpy

setup(
    name='integratore app',
    ext_modules=cythonize("pendolo.pyx"),
    include_dirs=[numpy.get_include()]
)

# python3.11 setup.py build_ext --inplace