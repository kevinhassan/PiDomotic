//gcc -I/usr/include/python2.7 -lpython2.7 main2.c -o call

#include <Python.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    	PyObject *pName, *pModule, *pDict, *pFunc;
	PyObject *pArgs, *pValue;

	Py_SetProgramName("Domotick");  /* optional but recommended */
	Py_Initialize();
	PySys_SetPath(".");
	pModule = PyImport_ImportModule("./test.py");	
	pFunc = PyObject_GetAttrString(pModule, "printFunction");
	pValue = PyEval_CallObject(pFunc,pArgs);
	//system("python pi_surveillance.py -c conf.json");	
	Py_Finalize();	
	return 0;
}

