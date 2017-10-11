#include <stdio.h>
#include <assert.h>

int
say_hi ()
{
  fputs ("hi\n", stdout);
  return 0;
}

int
add (int x, int y)
{
  int sum = x + y;
  return sum;
}

int
length (char *S)
{
  int length = 0;
  while (*S++) length++;
  return length;
}

int
print_nums (int nums[], int length, char *sep)
{
  for (int i = 0; i < length; i++) {
    printf("%d", nums[i]);
    if (i != 4)
      printf ("%s ", sep);
    else
      fputs("\n", stdout);
  }
  return 0;
}

int
sum_nums (int nums[], int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += nums[i];
  return sum;
}

/* TODO: Reverse an array */
/* TODO: Swap contents of two array */
/* TODO: Build an number sequence */

int
main ()
{
  {
    int count = 3;
    while (count--) say_hi ();
  }
  {
    int x = 3;
    int y = 5;
    printf ("%d + %d = %d\n", x, y, add (x, y));
  }
  {
    char *S = "hello world";
    printf ("The length of '%s' is %d\n", S, length (S));
  }
  {
    int nums[] = { 1, 2, 3, 4, 5 };
    print_nums(nums, 5, ",");
    nums[0] = 100;
    print_nums(nums, 5, ",");
  }
  {
    int nums[] = { 1, 2, 3, 4, 5 };
    int reversed_nums[5] = { 0 };
    for (int i = 4; i >= 0; i--)
      reversed_nums[4 - i] = nums[i];
    print_nums(nums, 5, ",");
    print_nums(reversed_nums, 5, ",");
  }
  {
    int nums[] = { 1, 2, 3, 4, 5 };
    assert (sum_nums (nums, 5) == 15);
  }
  return 0;
}

/* Local Variables: */
/* compile-command: "cc func.c && ./a.out" */
/* End: */
