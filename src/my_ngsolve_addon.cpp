#include <comp.hpp>
#include <python_comp.hpp>

#include "my_coefficient.hpp"

float my_function(float x) { return x * x; }

namespace ngcomp {
  void ExploreMesh (shared_ptr<MeshAccess> mesh);
}


PYBIND11_MODULE(my_ngsolve_addon, m) {
  cout << "Loading my_ngsolve_addon" << endl;
  m.def("my_function", &my_function, "A simple function", py::arg("x") = 1.0);


  m.def("ExploreMesh", &ngcomp::ExploreMesh, "exploring the mesh", py::arg("mesh"));
  
  m.def("EigH",
        [](shared_ptr<ngfem::CoefficientFunction> mat) -> shared_ptr<ngfem::CoefficientFunction>
        { return make_shared<ngfem::EigH_CF>(mat); },
        "compute eigenvalues of a symmetric 2x2 matrix coefficient-function",
        py::arg("mat"));
}
