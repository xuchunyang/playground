#include <chewing.h>
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  ChewingContext *ctx = chewing_new2 ("/usr/local/share/libchewing/", NULL, NULL, 0);
  char *buf;
  int counter;

  printf ("%d\n", MAX_SELKEY);
  
  if (chewing_get_ChiEngMode (ctx) == CHINESE_MODE)
    printf ("Chinese mode!\n");

  buf = chewing_get_KBString (ctx);
  printf ("Layout: %s\n", buf);
  free (buf);

  /*
   * Sequence 1：'綠茶'
   */
  chewing_handle_Default (ctx, 'x');    /* ㄌ */
  chewing_handle_Default (ctx, 'm');    /* ㄩ */
  chewing_handle_Default (ctx, '4');    /* ˋ */
  chewing_handle_Default (ctx, 't');    /* ㄔ */
  chewing_handle_Default (ctx, '8');    /* ㄚ */
  chewing_handle_Default (ctx, '6');    /* ˊ */
  /* commit buffer to output area */
  chewing_handle_Enter (ctx);

  /* Copy stribf from output area */
  buf = chewing_commit_String (ctx);
  printf ("%s\n", buf);
  free (buf);

  
  chewing_delete (ctx);
  return 0;
}

/* Local Variables: */
/* compile-command: "cc hello-chewing.c $(pkg-config --cflags --libs chewing) && ./a.out" */
/* End: */
