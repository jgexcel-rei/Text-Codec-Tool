// 多模式文本编码与加解密工具_主程序
#include <stdio.h>
#include <string.h>

#include "Base64.c"
#include "URL.c"
#include "Shift5.c"
#include "Morse Code.c"

int main()
{
    char choice[10] = {};
    int mode = 0;
    char input[1000] = {};
    char result[10000] = {};
    int len = strlen(input);
    int function = 0;

    printf("=== 文本编码与加解密工具 ===\n");
    printf("1. 凯撒密码\n");
    printf("2. URL 编码\n");
    printf("3. Base64 编码\n");
    printf("4. 摩斯电码\n");
    printf("输入 q! 退出\n");
    printf("请选择功能: ");
    fgets(choice, 3, stdin);
    choice[strcspn(choice, "\n")] = '\0';
    if (strlen(choice) >= 2)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    if (strcmp(choice, "q!") == 0)
    {
        printf("程序退出\n");
        return 0;
    }

    if (choice[0] < '1' || choice[0] > '4' || choice[1] != '\0')
    {
        printf("无效选择\n");
        return 1;
    }
    switch (choice[0] - '0')
    {
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    case 4:
        mode = 4;
        break;
    default:
        printf("无效选择！\n");
        return 1;
    }
    printf("请输入文本: ");
    fgets(input, 999, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("模式 (0=加密/编码, 1=解密／解码): ");
    scanf("%d", &function);
    if (function != 0 && function != 1)
    {
        printf("无效选择\n");
        return 1;
    }

    switch (mode)
    {
    case 1:
        if (Shift5_lock(input, len) == EOF)
        {
            printf("Shift5 仅支持英文字母！\n");
            return 1;
        }
        if (function == 0)
        {
            Shift5_lock(input, len);
            printf("Shift5 加密: %s\n", result);
        }
        else if (function == 1)
        {
            Shift5_lock(input, len);
            printf("Shift5 解密: %s\n", input);
        }
        break;

    case 2:
        if (function == 0)
        {
            URL_lock(input, len, result);
            printf("URL 编码: %s\n", result);
        }
        else if (function == 1)
        {
            URL_unlock(input, len, result);
            printf("URL 解码: %s\n", result);
        }
        break;

    case 3:
        if (function == 0)
        {
            Base64_lock((unsigned char *)input, len, (unsigned char *)result);
            printf("Base64 编码: %s\n", result);
        }
        else if (function == 1)
        {
            Base64_unlock((unsigned char *)input, len, (unsigned char *)result);
            printf("Base64 解码: %s\n", result);
        }
        break;

    case 4:
        if (Morse_Code_lock(input, len, result) == EOF)
        {
            printf("摩斯电码中包含不支持的字符，无法处理！\n");
            return 1;
        }
        if (function == 0)
        {
            Morse_Code_lock(input, len, result);
            printf("摩斯电码编码: %s\n", result);
        }
        else if (function == 1)
        {
            Morse_Code_unlock(input, len, result);
            printf("摩斯电码解码: %s\n", result);
        }
        break;
    }

    return 0;
}