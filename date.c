#include <time.h>
#include <stdio.h>

#define SIZE 512

int
main ()
{
  char buffer[SIZE];
  time_t curtime;
  struct tm *loctime;

  /* Get the current time */
  curtime = time (NULL);

  /* Convert it to local time representation */
  loctime = localtime(&curtime);

  /* Print it out in the default format of date(1) */
  strftime(buffer, SIZE, "%a %b %d %H:%M:%S %Z %Y\n", loctime);
  fputs (buffer, stdout);

  return 0;
}
