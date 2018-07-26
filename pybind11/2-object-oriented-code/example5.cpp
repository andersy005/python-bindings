
#include <pybind11/pybind11.h>
namespace py = pybind11;

class Pet {
    
public:
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }
private:  
    std::string name;
};

PYBIND11_MODULE(example5, m) {
    py::class_<Pet>(m, "Pet", py::module_local(), py::dynamic_attr())
        .def(py::init<const std::string &>())
        .def_property("name", &Pet::getName, &Pet::setName)
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("__repr__",
             [](const Pet &a) {
                 return "<example.Pet named '" + a.getName() + "'>";
             }
            );
}