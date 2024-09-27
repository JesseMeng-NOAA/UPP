#include <Python.h>
#include <stdio.h>

void calslrrf_(double* T1K, double* T2K, double* T05K,
               double* SPD1K, double* SPD2K, double* SPD05K, double* SLR)
{ 
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
    PyObject *pModule = PyImport_ImportModule("CALSLRRF_PY");

    if (!pModule)
    {
     PyErr_Print();
     printf("ERROR in pModule\n");
     exit(1);
    }

    PyObject *pFunc = PyObject_GetAttrString(pModule, "RF");
    PyObject *pArgs = PyTuple_New(6);
    PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble((*T1K)));
    PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble((*T2K)));
    PyTuple_SetItem(pArgs, 2, PyFloat_FromDouble((*T05K)));
    PyTuple_SetItem(pArgs, 3, PyFloat_FromDouble((*SPD1K)));
    PyTuple_SetItem(pArgs, 4, PyFloat_FromDouble((*SPD2K)));
    PyTuple_SetItem(pArgs, 5, PyFloat_FromDouble((*SPD05K)));

    PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
    *SLR   = PyFloat_AsDouble(pValue);
}


