cmake_minimum_required(VERSION 3.16)

###############################################################################
# Edit here
###############################################################################

# make sure the module_name matches the first argument of PYBIND11_MODULE
set(module_name my_ngsolve_addon)
set(source_files src/my_ngsolve_addon.cpp src/explore_mesh.cpp)

###############################################################################
# STOP editing here
###############################################################################

# Don't change this
project(${module_name})
include(ngsolve_addon.cmake)
