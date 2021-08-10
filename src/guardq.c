#include <stddef.h>
#include <R.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <R_ext/Lapack.h>
#include <R_ext/Rdynload.h>
#include <Rinternals.h>

int myAdd1(int a, int b) {
  return a+b;
}

static void myAdd2(int *a, int *b) {
  *a = *a+*b;
}

 // static R_NativePrimitiveArgType myC_type[] = {
  // INTSXP, INTSXP
 // };

static const R_CMethodDef CEntries[] = {
    {"myAdd2", (DL_FUNC) &myAdd2, 2},
    {NULL, NULL, 0, NULL}
};

void R_init_guardq(DllInfo *dll) {
  R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}