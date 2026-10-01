# An minimal NGSolve addon with Python bindings

## using the project template
To create your own NGSolve addon project you perfrom the following steps:

1. git-fork this project
2. fill the project with your C++ and Python files
3. adapt CMakeList.txt (addon_name, C++ and Python files)
4. adapt file pyproject.toml, section [project]
5. adapt `src/__init__.py` file
6. adapt `README.md` for installation instructions for your addon-project

## installing the addon project

Quick install: install the addon package directly with pip from git:

    python -m pip install  git+https://github.com/NGSolve/ngsolve-addon-template.git


**Alternative** needed for self-compiled NGSolve

    python -m pip install scikit-build-core pybind11_stubgen toml
    python -m pip install --no-build-isolation git+https://github.com/NGSolve/ngsolve-addon-template.git


test it:

    python -m ngsolve_addon_template.demos.exploremesh

Step-by-step installation:

simple step-by-step installation using pip:

    git clone https://github.com/NGSolve/ngsolve-addon-template.git
    cd ngsolve-addon-template
    python -m pip install --no-build-isolation .

alternative step-by-step installation using `cmake`:

    git clone https://github.com/NGSolve/ngsolve-addon-template.git
    cd ngsolve-addon-template
    mkdir build
    cd build
    cmake ..
    make -j4 install

## Troubleshooting

### Problem
Error in gihub actions when building Linux package:

```
    ImportError: /lib64/libstdc++.so.6: version `GLIBCXX_3.4.20' not found
```

### Solution
Update `pyproject.toml` by adding the following line to the `[tool.cibuildwheel]` section:

```toml
[tool.cibuildwheel]
manylinux-x86_64-image = "manylinux_2_28"
```

Some more NGSolve addons you can find here:
  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)

## Optional C++ library

To export a shared C++ library, splitting the addon into a core library and a Python module, you can use the following CMake code.
This will install the library, headers, and relocatable CMake files with the Python package.
First, create a library with the C++ sources and headers.

```cmake
add_ngsolve_addon_library(myaddon_core
  PACKAGE myaddon
  EXPORT_NAME core
  SOURCES src/core.cpp
  PUBLIC_HEADERS src/core.hpp)
```

Then, create a Python module that links to the core library. 

```cmake
add_ngsolve_addon(_pymyaddon src/python.cpp)
target_link_libraries(_pymyaddon PRIVATE myaddon_core)
ngsolve_addon_set_relative_rpath(_pymyaddon ".")
```

The `ngsolve_addon_set_relative_rpath` function ensures that the shared library can be found at runtime and is the relative path to the Python module from your addon package at the installation location.

Consumers use `find_package(myaddon CONFIG REQUIRED)` and link `myaddon::core`.
A `myaddon.config` Python module can print the CMake directory, as `ngsolve.config` does. 
Normal and post-release CMake package versions come from the Python package metadata automatically.
