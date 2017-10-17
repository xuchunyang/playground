#include <stdio.h>
#include <assert.h>
#include <stdlib.h>             /* random */
#include <time.h>               /* time */
#include <stdarg.h>

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
    if (i != length - 1)
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

int
reverse_print (char *S)
{
  int len = length (S);
  char *ptr = S + len - 1;
  while (ptr >= S) putchar (*ptr--);
  return 0;
}

int
sort_print (int nums[], int size)
{
  for (int j = size - 1; j > 0; j--)
    for (int i = 0; i < j; i++)
      if (nums[i] > nums[i+1]) {
        int tmp = nums[i];
        nums[i] = nums[i+1];
        nums[i+1] = tmp;
      }
  print_nums (nums, size, ",");
  return 0;
}

int
compare_numbers (const void *v1, const void *v2)
{
  return *(int *)v1 - *(int *)v2;
}

int
sort_numbers (int *numbers, int nnumbers)
{
  qsort (numbers, nnumbers, sizeof (int), compare_numbers);
  return 0;
}

int
nums_equal (int nums1[], int size1, int nums2[], int size2)
{
  if (size1 != size2) return -1;
  for (int i = 0; i < size1; i++)
    if (nums1[i] != nums2[i])
      return -1;
  return 0;
}

int
num_seq (int nums[], int from, int to)
{
  for (int i = 0; i < to - from + 1; i++)
    nums[i] = from + i;
  return 0;
}

int
random_nums (int nums[], int size)
{
  srandom (time (0));
  for (int i = 0; i < size; i++)
    {
      /* XXX: Limit the range */
      nums[i] = random ();
    }
  return 0;
}

int
swap_ints (int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return 0;
}

int
swap_nums (int nums1[], int nums2[], int size)
{
  for (int i = 0; i < size; i++)
    swap_ints (&nums1[i], &nums2[i]);
  return 0;
}

int *
some_nums (int size)
{
  int *rtv = malloc (size * sizeof(int));
  if (rtv == NULL)
    {
      perror ("malloc");
      exit (EXIT_FAILURE);
    }
  return rtv;
}

int
print_strings (const char *str, ...)
{
  va_list ap;

  va_start (ap, str);

  for (const char *s = str; s != NULL; s = va_arg (ap, const char *))
    fputs (s, stdout);

  va_end (ap);
  return 0;
}

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
  {
    char *S = "hello";
    reverse_print (S);
    puts ("");
  }
  {
    int nums[] = { 4, 3, 2, 1 };
    sort_print (nums, 4);
    int nums2[] = {8, 1, 2, 4, 3, 7, 100, 0};
    sort_print (nums2, 8);
  }
  {
    int nums1[] = { 1, 2, 3 };
    int nums2[] = { 1, 2, 3 };
    assert (nums_equal (nums1, 3, nums2, 3) == 0);
    nums1[0] = 100;
    assert (nums_equal (nums1, 3, nums2, 3) != 0);
  }
  {
    int nums1[] = { 1, 2, 3 };
    int nums2[] = { 3, 2, 1 };
    swap_nums (nums1, nums2, 3);
    print_nums (nums1, 3, ",");
    print_nums (nums2, 3, ",");
  }
  {
    int a = 1, b = 2;
    printf ("a = %d, b = %d\n", a, b);
    swap_ints (&a, &b);
    printf ("a = %d, b = %d\n", a, b);    
  }
  {
    int nums[3];
    num_seq (nums, 1, 3);
    print_nums (nums, 3, ",");
  }
  {
    int nums[3];
    random_nums (nums, 3);
    print_nums (nums, 3, ",");
  }
  {
    int size = 10;
    int *ptr = some_nums (size);
    for (int *p = ptr + 9, i = 10; p != ptr - 1; p--, i--)
      *p = i;
    print_nums (ptr, size, ",");
    free (ptr);
  }
  {
    char *ptr;
    int len = 10;
    ptr = malloc (len + 1);
    char *p = ptr;
    for (int i = '0'; i <= '9'; i++)
      *p++ = i;
    p = 0;
    puts (ptr);
    free (ptr);
  }
  {
    print_strings ("Hello", ", ", "World", "!\n", NULL);
  }
  {
    int numbers[] = { 4, 3, 2, 1, 100 };
    int nnumbers = sizeof numbers / sizeof (int);
    sort_numbers (numbers, nnumbers);
    print_nums (numbers, nnumbers, ",");
  }
  return 0;
}

/* Local Variables: */
/* compile-command: "cc func.c && ./a.out" */
/* End: */
