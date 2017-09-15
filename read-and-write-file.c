#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void
read_10_bytes (int fd)
{
  char ten[11];
  if (10 == read (fd, ten, 10))
    {
      ten[10] = 0;
      printf ("%s\n", ten);
    }
  else
    printf ("read error\n");
}

int
main ()
{
  int passwd = open ("/etc/passwd", O_RDONLY);
  read_10_bytes (passwd);
  close (passwd);
  read_10_bytes (STDIN_FILENO);

  int tmp = open ("/tmp/data.txt", O_WRONLY);
  char *msg = "Hello, World!";
  int msglen = strlen (msg);
  if (msglen != write (tmp, msg, msglen))
    printf ("write error\n");
  else
    printf ("write to /tmp/data.txt\n");
  
  return 0;
}
