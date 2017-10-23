/* https://www.ibm.com/developerworks/linux/tutorials/l-glib/ */

#include <glib.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  GList* list = NULL;
  list = g_list_append (list, "Hello world!");
  printf ("The first item is '%s'\n", (g_list_first (list))->data);
  return 0;
}

/* Local Variables: */
/* compile-command: "cc `pkg-config --cflags --libs glib-2.0` -o hello-glib hello-glib.c" */
/* End: */
