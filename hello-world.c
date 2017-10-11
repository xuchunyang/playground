#include <stdio.h>

int
main ()
{
  puts ("Hello World!");
  fputs ("Hello World!\n", stdout);
  printf ("Hello World!\n");
  {
    char msg[] = "Hello World!";
    char *ptr = msg;
    while (*ptr != 0)
      {
        putchar(*ptr);
        ptr++;
      }
    putchar('\n');
  }
  fputs("Are you ready? [y/n] ", stdout);
  int ch = fgetc(stdin);
  ch == 'y' ? puts ("Yes") : puts ("No");
  int ids[] = { 3, 42, 100 };
  for (int i = 0; i < sizeof ids / sizeof ids[0]; i++)
    printf ("ids[%d] = %d\n", i, ids[i]);
  return 0;
}

/* Local Variables: */
/* compile-command: "cc hello-world.c && echo y | ./a.out" */
/* End: */
