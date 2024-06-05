cmake_minimum_required(VERSION 3.16)

set(BUILD_STUB_FILES ON CACHE BOOL "Build stub files for IDEs")

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

# build and install stub files
if(BUILD_STUB_FILES)
  execute_process(COMMAND ${NETGEN_PYTHON_EXECUTABLE} -c "import pybind11_stubgen; print(pybind11_stubgen.__file__)" OUTPUT_VARIABLE stubgen_path RESULT_VARIABLE pybind11_stubgen)
if(pybind11_stubgen AND NOT ${pybind11_stubgen} EQUAL 0)
  message(WARNING "pybind11-stubgen not found, if you want to create stub files
for better autocompletion support install it with pip.")
else()
  message("-- Found pybind11-stubgen: ${stubgen_path}")
  install(CODE "execute_process(COMMAND ${NETGEN_PYTHON_EXECUTABLE} -m pybind11_stubgen --ignore-all-errors ${addon_name})")
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/stubs/${addon_name}.pyi DESTINATION ${ADDON_INSTALL_DIR})
endif()
endif(BUILD_STUB_FILES)
