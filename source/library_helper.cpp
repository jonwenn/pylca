#include "library_helper.h"

StdVecVecDouble ListOfListToVector(py::list &list_of_list) {
    unsigned long rows;
    rows = py::len(list_of_list);
    unsigned long columns;
    columns = py::len(py::extract<py::list>(list_of_list[0]));
    StdVecVecDouble temp;
    for (unsigned long i = 0; i < rows; i++) {
        py::list list_row = py::extract<py::list>(list_of_list[i]);
        StdVecDouble vec_row;
        for (unsigned long j = 0; j < columns; j++) {
            vec_row.push_back(static_cast<double>(py::extract<double>(list_row[j])));
        }
        temp.push_back(vec_row);
    }
    return temp;
}

StdVecDouble ListToVector(py::list &p_list) {
    unsigned long length = py::len(p_list);
    StdVecDouble vec_layer;
    for (unsigned long i = 0; i < length; i++) {
        vec_layer.push_back(static_cast<double>(py::extract<double>(p_list[i])));
    }
    return vec_layer;
}

py::list VectorOfVectorToList(StdVecVecDouble &vec_of_vec) {
    py::list temp;
    StdVecVecDouble::iterator row;
    StdVecDouble::iterator col;
    for (row = vec_of_vec.begin(); row != vec_of_vec.end(); row++) {
        py::list list_row;
        for (col = row->begin(); col != row->end(); col++) {
            list_row.append(*col);
        }
        temp.append(list_row);
    }
    return temp;
}

py::list VectorToList(StdVecDouble &vec) {
    py::list temp;
    StdVecDouble::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        temp.append(*it);
    }
    return temp;
}