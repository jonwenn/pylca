#ifndef PYLCA_LIBRARY_H
#define PYLCA_LIBRARY_H

#pragma once

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <boost/python/list.hpp>
#include <lca.h>
#include <vector>

using namespace std;
namespace py = boost::python;

class PyLifeCycleAssessment
{
public:
    PyLifeCycleAssessment(py::list &tech_matrix, py::list &emission_matrix, py::list &impact_matrix, py::list &final_demand);

    py::list GetTechnologyMatrix();

    void SetTechnologyMatrix(py::list &tech_matrix);

    py::list GetEmissionMatrix();

    void SetEmissionMatrix(py::list &emission_matrix);

    py::list GetImpactMatrix();

    void SetImpactMatrix(py::list &impact_matrix);

    py::list GetFinalDemandVector();

    void SetFinalDemandVector(py::list &tech_matrix);

    void ProcessToProduct();

    void IntensityOfEmission();

    void EnvironmentalImpacts();

    py::list GetScalingVector();

    py::list GetEmissionInventoryVector();

    py::list GetImpacts();

private:
    LifeCycleAssessment lca;
};

BOOST_PYTHON_MODULE (pylca)
{
    py::class_<PyLifeCycleAssessment>(
            "LifeCycleAssessment", py::init<py::list &, py::list &, py::list &, py::list &>())
            .add_property(
                    "A", &PyLifeCycleAssessment::GetTechnologyMatrix, &PyLifeCycleAssessment::SetTechnologyMatrix)
            .add_property(
                    "B", &PyLifeCycleAssessment::GetEmissionMatrix, &PyLifeCycleAssessment::SetEmissionMatrix)
            .add_property(
                    "Q", &PyLifeCycleAssessment::GetImpactMatrix, &PyLifeCycleAssessment::SetImpactMatrix)
            .add_property(
                    "f", &PyLifeCycleAssessment::GetFinalDemandVector, &PyLifeCycleAssessment::SetFinalDemandVector)
            .add_property("s", &PyLifeCycleAssessment::GetScalingVector)
            .add_property("g", &PyLifeCycleAssessment::GetEmissionInventoryVector)
            .add_property("h", &PyLifeCycleAssessment::GetImpacts)
            .def("process_to_product",
                 &PyLifeCycleAssessment::ProcessToProduct)
            .def("intensity_of_emission",
                 &PyLifeCycleAssessment::IntensityOfEmission)
            .def("impacts",
                 &PyLifeCycleAssessment::EnvironmentalImpacts);

}



#endif //PYLCA_LIBRARY_H
