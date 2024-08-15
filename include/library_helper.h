#ifndef CMARKOV_LIBRARY_HELPER_H
#define CMARKOV_LIBRARY_HELPER_H

#pragma once

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <boost/python/list.hpp>

namespace py = boost::python;

#include "globals.h"

StdVecDouble ListToVector(py::list &p_list);

StdVecVecDouble ListOfListToVector(py::list &list_of_list);

py::list VectorOfVectorToList(StdVecVecDouble &vec_of_vec);

py::list VectorToList(StdVecDouble &vec);

#endif //CMARKOV_LIBRARY_HELPER_H
