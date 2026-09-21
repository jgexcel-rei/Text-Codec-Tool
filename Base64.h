#ifndef BASE64_H
#define BASE64_H

int Base64_lock(unsigned char a[], int b, unsigned char lock_result[]);
int Base64_unlock(unsigned char a[], int b, unsigned char unlock_result[]);

#endif
