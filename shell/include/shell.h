#ifndef SHELL_H
#define SHELL_H

/*
 * Tipo opaco que representa el estado interno del shell.
 *
 * Este struct opaco permite a la implementación "backend"
 * mantener estado entre comando y comando (por ejemplo,
 * variables de entorno adicionales).
 */
struct shell;


/*
 * Creación de una instancia de struct shell. Devuelve puntero
 * opaco.
 *
 * Este puntero se pasa a cada una de las primitivas del shell.
 */
struct shell *shell_new(int argc, char *argv[]);


/*
 * Imprime el prompt del shell conforme a la variable PS1.
 *
 * Esta función solo se invoca si el shell se ejecuta en modo interactivo.
 */
void shell_print_prompt(struct shell *sh);


/*
 * Libera todos los recursos asociados con el shell.
 */
void shell_destroy(struct shell *sh);


#endif
