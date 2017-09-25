#include <stdio.h>

swap (int *arr, int i, int j)
{
  arr[i] ^= arr[j];
  arr[j] ^= arr[i];
  arr[i] ^= arr[j];
}

HeapSort (int *arr, int size)
{
  BuildHeap (arr, size);
  int i;
  for (i = size - 1; i >= 0; i --)
  {
      swap (arr, 0, i);
      Heapify (arr, 0, i - 1);
  }
}

BuildHeap (int *arr, int size)
{
  int l;
  for (l = (size / 2) - 1; l >= 0; l--)
    {
      Heapify (arr, l, size - 1);
    }
}

Heapify (int *arr, int i, int j)
{
  int k;
  if (2 * i + 1 > j)
    return;
  if (2 * i + 2 > j)
    k = 2 * i + 1;
  else if (arr[2 * i + 1] > arr[2 * i + 2])
    k = 2 * i + 1;
  else
    k = 2 * i + 2;
  if (arr[i] < arr[k])
    swap (arr, i, k);
  Heapify (arr, k, j);
}

int
main ()
{
  int arr[10] = { 7, 8, 3, 9, 0, 2, 5, 1, 4, 6 }, i;
  int size = sizeof (arr) / sizeof (arr[0]);
  printf ("Size: %d\n", size);
  HeapSort (arr, size);
  for (i = 0; i < size; i++)
    printf ("%d ", arr[i]);
  return 0;
}
