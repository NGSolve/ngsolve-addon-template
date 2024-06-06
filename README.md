# An minimal NGSolve addon with Python bindings

This project is a template for your own NGSolve add-on project. 
1. git-clone this project
2. fill the project with your C++ and Python files
3. adapt CMakeList.txt
4. adapt project.toml, section ....



Quick install: install the addon package directly with pip:

    pip install git+https://github.com/NGSolve/ngsolve-addon-template.git

Step-by-step installation:

    git clone https://github.com/NGSolve/ngsolve-addon-template.git
    cd ngsolve-addon-template
    mkdir build
    cd build
    cmake ..
    make -j4 install


Some more NGSolve addons you can find here:

  * https://github.com/TUWien-ASC/NGS-myfe (including vs-code instructions)
