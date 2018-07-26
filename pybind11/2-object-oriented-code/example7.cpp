
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

PYBIND11_MODULE(example7, m) {
    py::class_<Pet> pet(m, "Pet", py::module_local(), py::dynamic_attr());
        pet.def(py::init<const std::string &>())
        .def_readwrite("name", &Pet::name);
    
    // Method 2: pass parent class_ object
    py::class_<Dog>(m, "Dog", pet, py::module_local(), py::dynamic_attr() /* <- specify C++ parent type */)
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);
}