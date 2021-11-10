#define PY_SSIZE_T_CLEAN
#define ADIOS_INIT_LOC "/Adi_OS/init.py"
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
    
    if (exists(ADIOS_INIT_LOC) == 0) {
	fprintf(stderr,"Fatal error: init script doesn't exist\n");
	exit(2);
    }

    Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();

    
    FILE* file = fopen(ADIOS_INIT_LOC, "r");
    PyRun_SimpleFile(file, ADIOS_INIT_LOC);


    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
}