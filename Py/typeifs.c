#include <Python.h>
// build an integer
PyObject* pInt = Py_BuildValue("i", 2003);
assert(PyInt_Check(pInt));
int i = PyInt_AsLong(pInt);
Py_DECREF(pInt);
// build a float
PyObject* pFloat = Py_BuildValue("f", 3.14f);
assert(PyFloat_Check(pFloat));
float f = PyFloat_AsDouble(pFloat);
Py_DECREF(pFloat);
// build a string
PyObject* pString = Py_BuildValue("s", "Python");
assert(PyString_Check(pString);
int nLen = PyString_Size(pString);
char* s = PyString_AsString(pString);
Py_DECREF(pString);
