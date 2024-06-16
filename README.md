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

    python -m pip install scikit-build-core pybind11_stubgen 
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




Some more NGSolve addons you can find here:

  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)

## Install methods compatiblity (useful for developers)

### How did you install ngsolve?

1) `pip install ngsolve` (6.2.2304)
2) `pip install --pre ngsolve` (6.2.2304.post2.dev0)
3) Self-compiled (using CMake) (6.2.2304.post2)

You can check that using `python -m pip list` and look for the version number of ngsolve.

### How do you want to install the addon?

1) `pip install ngsolve-addon-template` (only available if addon developer provides wheels)
2) `pip install git+https://github.com/ngsolve/ngsolve-addon-template`
3) `pip install --no-build-isolation git+https://github.com/ngsolve/ngsolve-addon-template`
4) Self-compiled (using CMake)

Note: `pip install git+https://github.com/ngsolve/ngsolve-addon-template` is equivalent to `pip install .` if you have the source code checked out locally.

### Compatibility Matrix

|                                          | `pip install ngsolve-addon-template` [^1] | `pip install .`                      | `pip install --no-build-isolation .` | Addon CMake                           |
|------------------------------------------|-------------------------------------------|--------------------------------------|--------------------------------------|---------------------------------------|
| `pip install ngsolve`                    | ✅                                        | ✅                                   | ✅ [^2]                              | ✅                                    |
| `pip install --pre ngsolve`              | ❌ [^3]                                   | ❌ [^3]                              | ✅ [^2]                              | ✅                                    |
| NGSolve CMake                            | ❌ [^3]                                   | ❌ [^3]                              | ✅ [^2]                              | ✅                                    |

- ✅ this combination is expected to work (check footnotes for prerequisites and side effects)
- ⚠️ might work but is not recommended
[^1]: Only avaialble if the app developer provides wheel packages on pypi (for ngsolve-addon-template, no wheels are provided currently)
[^2]: Make sure that all build-dependencies are installed (`requires` field in the `[build-system]` section of [pyproject.toml](https://github.com/NGSolve/ngsolve-addon-template/blob/advanced/pyproject.toml)). Example: `pip install "scikit-build-core>=0.9.0" pybind11_stubgen cmake toml ngsolve>=6.2.2404`
[^3]: Installation could proceed without errrors but your prerelease/self-compiled ngsolve version will be overwritten by the version used to compile the plugin. Use `--no-build-isolation` if you want to keep your dev ngsolve version.

