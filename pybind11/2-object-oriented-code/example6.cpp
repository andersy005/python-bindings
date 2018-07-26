
#include <pybind11/pybind11.h>
namespace py = pybind11;

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
    
    std::string name;
};


struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { return "woof!"; }
};

PYBIND11_MODULE(example6, m) {
    py::class_<Pet>(m, "Pet", py::module_local(), py::dynamic_attr())
        .def(py::init<const std::string &>())
        .def_readwrite("name", &Pet::name);
    
    // Method 1: template paramter:
    py::class_<Dog, Pet /* <- specify C++ parent type */>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);
}