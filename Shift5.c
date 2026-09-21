// 凯撒移位密码Shift
#include <stdio.h>
#include <string.h>
#include "Shift5.h"
int Shift5_lock(char a[], int b)
{
  for (int i = 0; i < b; i++)
  {
    if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
    {
      if ((a[i] >= 'a' && a[i] + 5 <= 'z') || (a[i] >= 'A' && a[i] + 5 <= 'Z'))
      {
        a[i] = a[i] + 5;
      }
      else
      {
        a[i] = a[i] - 21;
      }
    }
    else
    {
      return EOF;
    }
  }
  a[b] = '\0';
  return 0;
}
int Shift5_unlock(char a[], int b)
{
  for (int i = 0; i < b; i++)
  {
    if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
    {
      if ((a[i] >= 'a' && a[i] - 5 >= 'a') || (a[i] <= 'Z' && a[i] - 5 >= 'A'))
      {
        a[i] = a[i] - 5;
      }
      else
      {
        a[i] = a[i] + 21;
      }
    }
    else
    {
      return EOF;
    }
  }
  a[b] = '\0';
  return 0;
}
