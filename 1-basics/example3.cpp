
#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int i = 10, int j = 30) {
    return i + j;
}

PYBIND11_MODULE(example3, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers",
          py::arg("i") = 10, py::arg("j") = 30);
}