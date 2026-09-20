#include <stdio.h>
#include <string.h>
int lock(char a[], int b, char lock_result[])
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
  return 0;
}
int unlock(char a[], int b)
{
}
int main()
{
  char original[100] = {},lock_result[100] = {0},unlock_result[100] = {0};
  printf("请输入密码：");
  fgets(original, sizeof(original), stdin);
  original[strcspn(original, "\n")] = '\0';//也可以使用scanf("%[^\n]s", original);
  int b = strlen(original);
  lock(original, b, lock_result);
  printf("加密后的密码为：%s\n", lock_result);
  return 0;

}