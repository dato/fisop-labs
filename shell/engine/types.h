#ifndef TYPES_H
#define TYPES_H

/*** EJEMPLOS DE TIPOS INTERNOS PARA UNA IMPLEMENTACIÓN DEL SHELL ***/

#include <stdint.h>
#include <uthash.h>


// Representa una variable interna del shell; se
// almacenan en una tabla hash (de tipo UTHash).
struct var {
    char *name;
    char *value;
    UT_hash_handle hh;
};


// Ídem alias del shell.
struct alias {
    char *name;
    /* Otros campos */
    UT_hash_handle hh;
};


// Estado interno del shell.
struct shell {
    int8_t status;  // Estado de salida del último comando.
    struct var *vars;
    struct alias *alias;
};


#endif
