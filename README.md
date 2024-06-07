# An minimal NGSolve addon with Python bindings

## using the project template
To create your own NGSolve addon project you perfrom the following steps:

1. git-fork this project
2. fill the project with your C++ and Python files
3. adapt CMakeList.txt (addon_name, C++ and Python files)
4. adapt file pyproject.toml, section [project]
5. adapt src/__init__.py file 

## installing the template project

Quick install: install the addon package directly with pip:

    python -m pip install git+https://github.com/NGSolve/ngsolve-addon-template.git

test it:

    python -m my_ngsolve_addon.demos.exploremesh

Step-by-step installation:

    git clone https://github.com/NGSolve/ngsolve-addon-template.git
    cd ngsolve-addon-template
    mkdir build
    cd build
    cmake ..
    make -j4 install


Some more NGSolve addons you can find here:

  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)
