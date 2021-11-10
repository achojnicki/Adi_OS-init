#define PY_SSIZE_T_CLEAN
#include <Python.h>

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int
main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    
    if (exists("/Adi_OS/init.py") == 0) {
	exit(2);
    }

    Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();

    
    FILE* file = fopen("/Adi_OS/init.py", "r");
    PyRun_SimpleFile(file, "/Adi_OS/init.py");


    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
}