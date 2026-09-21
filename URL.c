#include <stdio.h>
#include <string.h>
#include "URL.h"
int URL_lock(char a[], int b, char lock_result[])
{
  int c = 0;
  for (int i = 0; i < b; i++)
  {
    if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9') || a[i] == '_' || a[i] == '.' || a[i] == '-' || a[i] == '~')
    {
      lock_result[c] = a[i];
      c++;
    }
    else
    {
      sprintf(lock_result + c, "%%%02X", (unsigned char)a[i]);
      c += 3;
    }
  }
  lock_result[c] = '\0';
  return 0;
}
int URL_unlock(char a[], int b, char unlock_result[])
{
  int c = 0;
  for (int i = 0; i < b; i++)
  {
    if (a[i] == '%' && i + 2 < b)
    {
      int j, k;
      if (a[i + 1] >= '0' && a[i + 1] <= '9')
        j = a[i + 1] - '0';
      else if (a[i + 1] >= 'A' && a[i + 1] <= 'F')
        j = a[i + 1] - 'A' + 10;
      else if (a[i + 1] >= 'a' && a[i + 1] <= 'f')
        j = a[i + 1] - 'a' + 10;
      else
      {
        unlock_result[c++] = a[i];
        continue;
      }

      if (a[i + 2] >= '0' && a[i + 2] <= '9')
        k = a[i + 2] - '0';
      else if (a[i + 2] >= 'A' && a[i + 2] <= 'F')
        k = a[i + 2] - 'A' + 10;
      else if (a[i + 2] >= 'a' && a[i + 2] <= 'f')
        k = a[i + 2] - 'a' + 10;
      else
      {
        unlock_result[c++] = a[i];
        continue;
      }

      unlock_result[c++] = (j << 4) | k;
      i += 2;
    }
    else
    {
      unlock_result[c++] = a[i];
    }
  }
  unlock_result[c] = '\0';
  return c;
}

