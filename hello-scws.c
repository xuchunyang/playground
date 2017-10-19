#include <stdio.h>
#include <scws/scws.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  scws_t s;
  scws_res_t res, cur;
  char *text = "Hello, 我叫李那曲，是个中国人。我有时买Q币来玩, 我还听说过C#语言";

  if (!(s = scws_new ()))
    {
      printf ("ERROR: cann't init the scws!\n");
      exit (-1);
    }
  scws_set_charset (s, "utf8");
  scws_set_dict (s, "/usr/local/etc/dict.utf8.xdb", SCWS_XDICT_XDB);
  scws_set_rule (s, "/usr/local/etc/rules.utf8.ini");

  scws_send_text (s, text, strlen (text));
  while ((res = cur = scws_get_result (s)))
    {
      while (cur != NULL)
        {
          printf ("WORD: %.*s/%s (IDF = %4.2f)\n",
                  cur->len,
                  text+cur->off,
                  cur->attr,
                  cur->idf);
          cur = cur->next;
        }
      scws_free_result (res);
    }
  scws_free (s);
  return 0;
}

/* Local Variables: */
/* compile-command: "cc hello-scws.c -lscws && ./a.out" */
/* End: */
