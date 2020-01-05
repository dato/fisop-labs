#define _POSIX_C_SOURCE 200809L

#include "vars.h"
#include "types.h"

#include <assert.h>


static struct var *var_new(const char *name, const char *value) {
    // TODO: Implement.
    return NULL;
}


static void var_free(struct var *var) {
    // TODO: Implement.
}


void shell_var_command(struct shell *sh, struct var_command *cmd) {
    struct var *var;

    // Tener a mano la variable en el hash, por si ya existe.
    HASH_FIND_STR(sh->vars, cmd->var_name, var);

    // Invariante: la variable o es interna o es de entorno, pero no ambas.
    assert((var == NULL) != (getenv(cmd->var_name) == NULL));

    switch (cmd->action) {
    case VAR_SET:
        // TODO:
        // (1) Si la variable ya existe en el hash, actualizar su valor.
        // (2) Si la variable ya existe en el entorno, actualizar su valor.
        // (3) Crear una nueva variable con var_new(), y guardarla.
        break;
    case VAR_SET_EXPORT:
        // TODO:
        // (1) Actualizar la variable en el entorno con setenv.
        // (2) Si la variable existía en el hash, eliminarla.
        break;
    case VAR_UNSET:
        // TODO:
        // Llamar a HASH_DEL()/var_free() o unsetenv(3) según sea necesario.
        break;
    case VAR_EXPORT:
        // TODO
        // (Pueden darse dos casos: que la variable esté en el hash, en cuyo
        // casos hay que moverla al entorno; o que no lo esté, en cuyo caso hay
        // que _marcarla_ para exportar en el próximo VAR_SET. Para esto último,
        // quizás se haga necesario modificar el struct var.)
        break;
    }
}
