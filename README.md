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




Some more NGSolve addons you can find here:

  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)
