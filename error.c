#include <errno.h>
#include <fcntl.h>
#include <stdio.h>              /* perror */

int
main (int argc, char *argv[])
{
  if (-1 == open ("/tmp/nonexist.txt", O_RDONLY))
    {
      perror ("open");
      return -1;
    }
  return 0;
}
