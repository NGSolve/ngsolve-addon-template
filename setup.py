from skbuild import setup

import sys
_cmake_args = []

# if 'win32' in sys.platform:
#    _cmake_args += ['-G', 'MinGW Makefiles']

setup(
    name="my_ngsolve_addon",
    version="0.0.1",
    author="NGSolve",
    license="MIT",
    cmake_args=_cmake_args
)
