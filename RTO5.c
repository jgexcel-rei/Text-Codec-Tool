// 此文件换行符为 LF (Unix)，Git 在 Windows 上会自动转换为 CRLF，不影响使用
// 凯撒移位密码ROT5
#include <stdio.h>
#include <string.h>
int lock(char a[], int b)
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
  return 0;
}
void unlock(char a[], int b)
{
  for (int i = 0; i < b; i++)
  {
    if (a[i] >= 'a' && a[i] <= 'z')
    {

      if (a[i] - 5 >= 'a')
      {
        a[i] = a[i] - 5;
      }
      else
      {
        a[i] = a[i] + 21;
      }
    }
    if (a[i] >= 'A' && a[i] <= 'Z')
    {
      if (a[i] - 5 >= 'A')
      {
        a[i] = a[i] - 5;
      }
      else
      {
        a[i] = a[i] + 21;
      }
    }
  }
}
int main()
{
  char a[100];
  printf("请输入密码：");
  scanf("%s", a);
  int b = strlen(a);
  if (lock(a, b) == EOF)
  {
    goto END;
  }
  printf("加密后的密码为：%s\n", a);
  unlock(a, b);
  printf("解密后的密码为：%s\n", a);
  return 0;
END:
  printf("密码中包含非字母字符，无法加密或解密\n");
  return 0;
}
