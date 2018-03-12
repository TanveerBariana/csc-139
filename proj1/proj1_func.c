/* Project 1
 * Authored by Prof. Don Heller and Prof. Bhuvan Urgaonkar
 * Files:  proj1.h proj1.c proj1_var.c proj1_func.c makefile
 */

/*----------------------------------------------------------------------*/

#include "proj1.h"        /* for macros show...() */

/*----------------------------------------------------------------------*/

void extern_func(void)
{
  int local_ef_var_1, local_ef_var_2;
  static int static_local_ef_var_1, static_local_ef_var_2;

  show_int(local_ef_var_1);
  show_int(local_ef_var_2);

  show_int(static_local_ef_var_1);
  show_int(static_local_ef_var_2);

  return; 
}
/*----------------------------------------------------------------------*/

