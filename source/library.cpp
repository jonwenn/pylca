#include "library.h"
#include "library_helper.h"

PyLifeCycleAssessment::PyLifeCycleAssessment() = default;

PyLifeCycleAssessment::PyLifeCycleAssessment(
        py::list &tech_matrix, py::list &emission_matrix, py::list &impact_matrix, py::list &final_demand)
        : lca(ListOfListToVector(tech_matrix), ListOfListToVector(emission_matrix), ListOfListToVector(impact_matrix),
              ListToVector(final_demand)) {
}

py::list PyLifeCycleAssessment::GetTechnologyMatrix() {
    StdVecVecDouble tech_matrix = lca.GetTechnologyMatrix();
    return VectorOfVectorToList(tech_matrix);
}

void PyLifeCycleAssessment::SetTechnologyMatrix(py::list &p_tech_matrix) {
    lca.SetTechnologyMatrix(ListOfListToVector(p_tech_matrix));
}

py::list PyLifeCycleAssessment::GetEmissionMatrix(){
    StdVecVecDouble emission_matrix = lca.GetEmissionMatrix();
    return VectorOfVectorToList(emission_matrix);
}

void PyLifeCycleAssessment::SetEmissionMatrix(py::list &emission_matrix){
    lca.SetEmissionMatrix(ListOfListToVector(emission_matrix));
}

py::list PyLifeCycleAssessment::GetImpactMatrix(){
    StdVecVecDouble impact_matrix = lca.GetImpactMatrix();
    return VectorOfVectorToList(impact_matrix);
}
void PyLifeCycleAssessment::SetImpactMatrix(py::list &impact_matrix){
    lca.SetImpactMatrix(ListOfListToVector(impact_matrix));
}

py::list PyLifeCycleAssessment::GetFinalDemandVector() {
    StdVecDouble demand_vector = lca.GetFinalDemandVector();
    return VectorToList(demand_vector);
}

void PyLifeCycleAssessment::SetFinalDemandVector(py::list &tech_matrix) {
    lca.SetFinalDemandVector(ListToVector(tech_matrix));
}

void PyLifeCycleAssessment::ProcessToProduct() {
    lca.ProcessToProductionSystem();
}

void PyLifeCycleAssessment::ProductProcess() {
    lca.ProductProcesses();
}

void PyLifeCycleAssessment::IntensityOfEmission() {
    lca.IntensityOfEmission();
}

void PyLifeCycleAssessment::EnvironmentalImpacts() {
    lca.EnvironmentalImpacts();
}

py::list PyLifeCycleAssessment::GetScalingVector() {
    StdVecDouble scaling_vector = lca.GetScalingVector();
    return VectorToList(scaling_vector);
}

py::list PyLifeCycleAssessment::GetProductProcesses() {
    StdVecVecDouble product_processes = lca.GetProductProcesses();
    return VectorOfVectorToList(product_processes);
}

py::list PyLifeCycleAssessment::GetEmissionInventoryVector() {
    StdVecDouble emission_inventory_vector = lca.GetEmissionInventoryVector();
    return VectorToList(emission_inventory_vector);
}

py::list PyLifeCycleAssessment::GetImpacts() {
    StdVecDouble impact_vector = lca.GetImpacts();
    return VectorToList(impact_vector);
}




