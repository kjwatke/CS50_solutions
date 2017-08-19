/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
  if (value < 0)
  {
    return false;
  }

  if (n == 1)
  {
    return value == values[0];
  }

  int startPoint = 0, endPoint = n - 1, midPoint;

  while (startPoint <= endPoint)
  {

    midPoint = (startPoint + endPoint) / 2;

    // Handle found value at midpoint.
    if (values[midPoint] == value)
    {
      return 1;
    }

    // Handle when midPoint is smaller than value.
    if (values[midPoint] < value)
    {
      startPoint = midPoint + 1;
    }

    // Handle when midPoint is greater than value.
    if (values[midPoint] > value)
    {
      endPoint = midPoint - 1;
    }
  }

  return 0;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
  for (int i = 1; i < n; ++i)
  {
    int j = i;
    while (j > 0 && values[j] < values[j - 1])
    {
      int tmp = values[j];
      values[j] = values[j - 1];
      values[j - 1] = tmp;
      j -= 1;
    }
  }
}
