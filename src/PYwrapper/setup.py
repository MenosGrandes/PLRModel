from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize


ext_modules = [
    Extension('PupilDynamicsModel_wrapper', ['PupilDynamicsModel_wrapper.pyx'], language="c++",),
]
setup(
    name='PLR',
    ext_modules=ext_modules,
    include_dirs=["../"],
    cmdclass={'build_ext': build_ext},
)