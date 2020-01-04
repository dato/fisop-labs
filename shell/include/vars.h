#ifndef VARS_H
#define VARS_H

#include "shell.h"


/*
 * Representa cada una de las acciones posibles sobre las variables del shell.
 */
enum var_action {
    VAR_SET,        // A=1
    VAR_UNSET,      // unset B
    VAR_EXPORT,     // export C
    VAR_SET_EXPORT, // export D=2
};


/*
 * Representa un comando que manipula las variables del shell.
 */
struct var_command {
    enum var_action action;
    const char *var_name;
    const char *var_value; // Solo si action es VAR_SET o VAR_SET_EXPORT.
};


/*
 * Manipula las variables del shell (internas y de entorno).
 *
 * Pre-condiciones:
 *
 *  - cmd->action dentro del rango de enum var_action.
 *  - cmd->var_name != NULL.
 *  - cmd->var_value != NULL si cmd->action es VAR_SET o VAR_SET_EXPORT.
 *
 */
void shell_var_command(struct shell *sh, struct var_command *cmd);

#endif
