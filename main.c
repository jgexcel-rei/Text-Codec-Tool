// Morse Code
#include <stdio.h>
#include <string.h>
int lock(char original[], int b, char lock_result[])
{
    int c = 0;
    int n = 53;
    char in[53] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.',',','?','!','/','-','+','=',':',';','(',')','&','@','\x27','"','_'};
    char* out[53] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..","-.-.--","-..-.","-....-",".-.-.","-...-","---...","-.-.-.","-.--.","-.--.-",".-...",".--.-.",".----.",".-..-.","..--.-"};
    for(int i = 0; i < b; i++){
    if(original[i] >= 'a' && original[i] <= 'z'){
        original[i] = original[i] - 32;
    }
        int found = 0;
        for(int j = 0; j < n; j++){
            if(original[i] == in[j]){
                found = 1;
                for(int k = 0; k < strlen(out[j]); k++){
                    lock_result[c++] = out[j][k];
                }
                lock_result[c++] = ' ';
            }
        }
        if(!found){
            return EOF;
        }
    }
    return 0;
}
int unlock(char lock_result[], int b, char unlock_result[])
{
    int c = 0, d = 0;
    int n = 53;
    char in[53] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.',',','?','!','/','-','+','=',':',';','(',')','&','@','\x27','"','_'};
    char* out[53] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..","-.-.--","-..-.","-....-",".-.-.","-...-","---...","-.-.-.","-.--.","-.--.-",".-...",".--.-.",".----.",".-..-.","..--.-"};
      for(int j = 0; j < n; j++){
        for(int i = 0; i < strlen(out[j]); i++){
        if(lock_result[c + i] != out[j][i]){
            break;
        }

        if(i == strlen(out[j]) - 1 && (lock_result[c + i + 1] == ' ' || lock_result[c + i + 1] == '\0')){
            unlock_result[d++] = in[j];
            c += strlen(out[j]) + 1;
            j = -1;
            break;
        }
    }
           if(lock_result[c] == '\0'){
             break;
           }
}
return 0;
}
int main(){
  char original[100], lock_result[1000] = {}, unlock_result[100] = {};
  printf("\u8bf7\u8f93\u5165\u5bc6\u7801\uff1a");
  scanf("%s", original);
  int lock_b = strlen(original);
  if (lock(original, lock_b, lock_result) == EOF)
  {
    goto END;
  }
  printf("\u52a0\u5bc6\u540e\u7684\u5bc6\u7801\u4e3a\uff1a%s\n", lock_result);
  int unlock_b = strlen(lock_result);
  unlock(lock_result, unlock_b, unlock_result);
  printf("\u89e3\u5bc6\u540e\u7684\u5bc6\u7801\u4e3a\uff1a%s\n", unlock_result);
  return 0;
END:
  printf("\u5bc6\u7801\u4e2d\u5305\u542b\u4e0d\u652f\u6301\u7684\u5b57\u7b26\uff0c\u65e0\u6cd5\u52a0\u5bc6\u6216\u89e3\u5bc6\n");
  return 0;
}
