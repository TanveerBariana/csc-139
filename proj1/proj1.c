/* Project 1
 * Authored by Prof. Don Heller and Prof. Bhuvan Urgaonkar
 * Files:  proj1.h proj1.c proj1_var.c proj1_func.c makefile
 */

/*----------------------------------------------------------------------*/

#include <stdio.h>      /* for printf() */
#include <stdlib.h>     /* for malloc(), putenv(), setenv() */
#include <string.h>     /* for strlen() */
#include <math.h>       /* for sqrt() */

#include "proj1.h"      /* for macros show...() */

char foobar[] = "FOO=BAR";      /* for use with putenv() */

/*----------------------------------------------------------------------*/

/* These should be at various locations in the address space. */

int global_var_1, global_var_2;

static int badman;
static int static_global_var_1, static_global_var_2;

extern int extern_var_1, extern_var_2;  /* see proj1_var.c */

void local_func(void);

static void static_local_func(void);

void extern_func(void);                 /* see proj1_func.c */

void test_multiple_args(int arg1, int arg2, int arg3);

void test_recursion(int count);

/* array of environment variables */
extern char **environ;

/*----------------------------------------------------------------------*/

int main(int argc, char *argv[], char *envp[])
{
  /* local and global variables */

  int local_main_var_1, local_main_var_2;
  static int static_local_main_var_1, static_local_main_var_2;

  show_int(global_var_1);
  show_int(global_var_2);

  show_int(static_global_var_1);
  show_int(static_global_var_2);

  show_int(extern_var_1);
  show_int(extern_var_2);

  show_int(local_main_var_1);
  show_int(local_main_var_2);

  show_int(static_local_main_var_1);
  show_int(static_local_main_var_2);

  local_func();
  static_local_func();
  extern_func();


  /* function arguments and recursion */

  test_multiple_args(1, 2, 3);
  test_recursion(4);


  /* library functions */

  show_func(printf);
  show_func(malloc);
  show_func(strlen);
  show_func(sqrt);


  /* this program's functions */

  show_func(main);
  show_func(local_func);
  show_func(static_local_func);
  show_func(extern_func);
  show_func(test_multiple_args);
  show_func(test_recursion);


  /* string constants */
  char *local_main_string_ptr = "abcdef";

  show_str("abc");
  show_str("abcdef");
  show_str(local_main_string_ptr);
  show_ptr(local_main_string_ptr);


  /* command-line */

  show_int(argc);
  show_ptr(argv);

  int i;

  for (i = 0; i < argc; i++) {
    show_array(argv,i);
    show_array_str(argv,i);
  }
    show_array(argv,i);         /* NULL */


  /* environment strings */

  /* Let's make this more interesting by first allocating a new environment
   * variable.  The value of environ will change because the array will be
   * enlarged and reallocated.  The value of envp will not change.
   */

  /* choose one of these, depending on the system */
  setenv("FOO", "BAR", 1);      /* ignore the return value */
  // putenv("FOO=BAR");         /* ignore the return value */
  // putenv(foobar);            /* ignore the return value */

  show_str(foobar);


  /* environment via envp */

  show_ptr(envp);

  for (i = 0; envp[i] != NULL; i++) {
    show_array(envp,i);
    show_array_str(envp,i);
  }
    show_array(envp,i);         /* NULL */


  /* environment via environ */

  show_ptr(environ);

  for (i = 0; environ[i] != NULL; i++) {
    show_array(environ,i);
    show_array_str(environ,i);
  }
    show_array(environ,i);      /* NULL */


  /* dynamically-allocated arrays with local pointers */

  size_t k = 1024;
    /* size_t is an unsigned integer type */
  void * malloc_16 = malloc(16);
  void * malloc_1K = malloc(k);
  void * malloc_1M = malloc(k*k);
  void * malloc_1G = malloc(k*k*k);
  void * malloc_2G = malloc(2*k*k*k);
  void * malloc_4G = malloc(4*k*k*k);
    /* note that 4*k*k*k will overflow to 0 in 32-bit arithmetic */

  show_malloc(malloc_16);
  show_malloc(malloc_1K);
  show_malloc(malloc_1M);
  show_malloc(malloc_1G);
  show_malloc(malloc_2G);
  show_malloc(malloc_4G);


  return 0;
}

/*----------------------------------------------------------------------*/

void local_func(void)
{
  int local_lf_var_1, local_lf_var_2;
  static int static_local_lf_var_1, static_local_lf_var_2;

  show_int(local_lf_var_1);
  show_int(local_lf_var_2);

  show_int(static_local_lf_var_1);
  show_int(static_local_lf_var_2);

  return;
}

/*----------------------------------------------------------------------*/

static void static_local_func(void)
{
  int local_slf_var_1, local_slf_var_2;
  static int static_local_slf_var_1, static_local_slf_var_2;

  show_int(local_slf_var_1);
  show_int(local_slf_var_2);

  show_int(static_local_slf_var_1);
  show_int(static_local_slf_var_2);

  return;
}

/*----------------------------------------------------------------------*/

void test_multiple_args(int test_multiple_arg_1,
                        int test_multiple_arg_2,
                        int test_multiple_arg_3)
{
  show_int(test_multiple_arg_1);
  show_int(test_multiple_arg_2);
  show_int(test_multiple_arg_3);
}

/*----------------------------------------------------------------------*/

void test_recursion(int test_recursion_arg)
{
  int test_recursion_local = test_recursion_arg;

  if (test_recursion_arg < 0) return;

  test_recursion(test_recursion_arg-1);

  show_int(test_recursion_local);
  show_int(test_recursion_arg);
}

/*----------------------------------------------------------------------*/

