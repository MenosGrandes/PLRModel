https://dmtn-013.lsst.io/
from distutils.core import setup

from Cython.Build import cythonize

setup(ext_modules=cythonize("PamplonaAndOliveiraModel.pyx"))