cmake_minimum_required(VERSION 3.16)

# change this to your desired addon name
# make sure, that the name matches exactly the argument of PYBIND11_MODULE()
set(addon_name my_ngsolve_addon)

project(${addon_name})
include(ngsolve_addon.cmake)

# change the source file arguments to your source files
add_ngsolve_addon(${addon_name} src/my_ngsolve_addon.cpp src/explore_mesh.cpp)

# install the compiled python module and __init__.py ( don't change this )
set(ADDON_INSTALL_DIR ${python3_library_dir}/${addon_name})
install(TARGETS ${addon_name} DESTINATION ${ADDON_INSTALL_DIR})
install(FILES src/__init__.py DESTINATION ${ADDON_INSTALL_DIR})

# install additional python files/demos/examples
install(FILES demos/exploremesh.py DESTINATION ${ADDON_INSTALL_DIR}/demos)
