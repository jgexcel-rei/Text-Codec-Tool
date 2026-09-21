#include <stdio.h>
#include <string.h>
#include "Base64.h"
int Base64_lock(unsigned char a[], int b, unsigned char lock_result[])
{
    int c = 0, d = 0;
    unsigned char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    while (d < b)
    {
        if (b - d == 2)
        {
            lock_result[c] = base64[a[d] >> 2];
            lock_result[c + 1] = base64[(a[d] & 0x03) << 4 | a[d + 1] >> 4];
            lock_result[c + 2] = base64[(a[d + 1] & 0x0F) << 2 | 0x00];
            lock_result[c + 3] = '=';
            c += 4;
            d += 2;
            continue;
        }
        if (b - d == 1)
        {
            lock_result[c] = base64[a[d] >> 2];
            lock_result[c + 1] = base64[(a[d] & 0x03) << 4 | 0x00];
            lock_result[c + 2] = '=';
            lock_result[c + 3] = '=';
            c += 4;
            d += 1;
            continue;
        }

        lock_result[c] = base64[a[d] >> 2];
        lock_result[c + 1] = base64[(a[d] & 0x03) << 4 | a[d + 1] >> 4];
        lock_result[c + 2] = base64[(a[d + 1] & 0x0F) << 2 | a[d + 2] >> 6];
        lock_result[c + 3] = base64[a[d + 2] & 0x3F];
        c += 4;
        d += 3;
    }
    lock_result[c] = '\0';
    return 0;
}
int Base64_unlock(unsigned char a[], int b, unsigned char unlock_result[])
{
    int c = 0, d = 0;
    int p[1000] = {};
    for (int i = 0; i < b; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            p[i] = a[i] - 'A';
        }
        else if (a[i] >= 'a' && a[i] <= 'z')
        {
            p[i] = a[i] - 'a' + 26;
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            p[i] = a[i] - '0' + 52;
        }
        else if (a[i] == '+')
        {
            p[i] = 62;
        }
        else if (a[i] == '/')
        {
            p[i] = 63;
        }
        else if (a[i] == '=')
        {
            p[i] = 0;
        }
        else{
            return EOF;
        }
    }
    while (d < b)
    {
        if (a[d + 2] == '=')
        {
            unlock_result[c] = p[d] << 2 | p[d + 1] >> 4;
            c++;
            d += 4;
            continue;
        }
        if (a[d + 3] == '=')
        {
            unlock_result[c] = p[d] << 2 | p[d + 1] >> 4;
            unlock_result[c + 1] = (p[d + 1] & 0x0F) << 4 | p[d + 2] >> 2;
            c += 2;
            d += 4;
            continue;
        }
        unlock_result[c] = p[d] << 2 | p[d + 1] >> 4;
        unlock_result[c + 1] = (p[d + 1] & 0x0F) << 4 | p[d + 2] >> 2;
        unlock_result[c + 2] = (p[d + 2] & 0x03) << 6 | p[d + 3];
        c += 3;
        d += 4;
    }
    unlock_result[c] = '\0';
    return 0;
}
