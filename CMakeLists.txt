cmake_minimum_required(VERSION 3.16)

# change this to your desired addon name
# make sure, that the name matches exactly the argument of PYBIND11_MODULE()
set(addon_name my_ngsolve_addon)

project(${addon_name})
include(ngsolve_addon.cmake)

# change the source file arguments to your source files
add_ngsolve_addon(${addon_name} src/my_ngsolve_addon.cpp src/explore_mesh.cpp)

# install the compiled python module and __init__.py ( don't change this )
install(TARGETS ${addon_name} DESTINATION ${addon_name})
install(FILES src/__init__.py DESTINATION ${addon_name})

# install additional python files/demos/examples
install(FILES demos/exploremesh.py DESTINATION ${addon_name}/demos)

# generate stub files for autocomplete in IDEs
# this must be done at the very end (such that the stubgen generation happens after the python modules are installed)
install(CODE ${stubgen_generation_code})
install(DIRECTORY ${stubgen_directory} DESTINATION ${addon_name})
