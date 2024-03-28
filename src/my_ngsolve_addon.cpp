#include <comp.hpp>
#include <python_comp.hpp>

float my_function(float x) { return x * x; }

PYBIND11_MODULE(my_ngsolve_addon, m) {
  cout << "Loading my_ngsolve_addon" << endl;
  m.def("my_function", &my_function, "A simple function", py::arg("x") = 1.0);
}
