/* Project 1
 * Authored by Prof. Don Heller and Prof. Bhuvan Urgaonkar
 * Files:  proj1.h proj1.c proj1_var.c proj1_func.c makefile
 */

/*----------------------------------------------------------------------*/

/* preprocessor macros for proj1.c
 *   show_int(v)
 *   show_ptr(v)
 *   show_malloc(v)
 *   show_func(f)
 *   show_str(s)
 *   show_array(a,n)
 *   show_array_str(a,n)
 *
 * These will print
 *   address                 [with leading 0's for the unix sort command]
 *   (number of bytes)       [if this is available]
 *   name of variable, function, etc.
 *   value at the address    [if this is possible to print]
 *
 * The macros use the preprocessor "stringization" operator # .
 * The final \ is used to continue the definition on the next line.
 *
 * printf() works by a match-and-substitute method between a format string
 * and a list of values.  The format codes start with % and end with a
 * character denoting the basic treatment of the matching value (s for
 * string, d for decimal integer, p for hexadecimal pointer).  Anything
 * in the format string that is not part of a format code is printed as-is.
 *
 * The printf() format codes used here are
 *   %s		for a null-terminated string
 *   %24s	for a null-terminated string, allocate 24 spaces
 *   %d		for an int type, decimal
 *   %2zd	for a size_t type, decimal, allocate 2 spaces
 *   %016p	for a void * pointer type, allocate 16 spaces, leading 0's
 */

#include <stdio.h>	/* for printf() */
#include <string.h>	/* for strlen() */

/*----------------------------------------------------------------------*/

/* v is the name of a declared int variable */

#define show_int(v) \
  printf("%016p (%2zd) %24s\t\t%d\n", \
    (void *)&v, sizeof(v), #v, v)

/*----------------------------------------------------------------------*/

/* v is the name of a declared pointer variable */

#define show_ptr(v) \
  printf("%016p (%2zd) %24s\t\t%016p\n", \
    (void *)&v, sizeof(v), #v, (void *)v)

/*----------------------------------------------------------------------*/

/* v is the name of a declared pointer variable, and
 * the value of v came from malloc(n)
 */

#define show_malloc(v) \
  show_ptr(v); \
  printf("%016p      %24s[0]\n", (void *)v, #v)

/*----------------------------------------------------------------------*/

/* f is the name of a function */

#define show_func(f) \
  printf("%016p      %24s\n", (void *)f, #f)

/*----------------------------------------------------------------------*/

/* s is the name of a character string */

/* If we use the obvious macro then we get three copies of the string
 * when using show_str("abc");
 */

static inline void Show_str(const char * const s, const char * const nm)
{
  printf("%016p (%2zd) %24s\t\t\"%s\"\n",
    (void *)s, strlen(s)+1, nm, s);
}

#define show_str(s) Show_str(s,#s)

/*----------------------------------------------------------------------*/

/* a is the name of a declared array of char *, and
 * n is a valid subscript into the array
 */

#define show_array(a,n) \
  printf("%016p (%2zd) %24s[%d]\t%016p\n", \
    (void *)&a[n], sizeof(a[n]), #a, n, (void *)a[n])

#define show_array_str(a,n) \
  printf("%016p (%2zd) %24s[%d]->\t\"%s\"\n", \
    (void *)a[n], strlen(a[n])+1, #a, n, a[n])

/*----------------------------------------------------------------------*/

