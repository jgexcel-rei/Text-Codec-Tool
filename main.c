// Morse Code
#include <stdio.h>
#include <string.h>
int lock(char original[], int b, char lock_result[])
{
    int c = 0;
    char in[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    char* out[36] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    for(int i = 0; i < b; i++){
    if(original[i] >= 'a' && original[i] <= 'z'){
        original[i] = original[i] - 32;
    }
        if((original[i] >= 'A' && original[i] <= 'Z') || (original[i] >= '0' && original[i] <= '9')){
            for(int j = 0; j < 36; j++){
                if(original[i] == in[j]){
                    for(int k = 0; k < strlen(out[j]); k++){
                        lock_result[c++] = out[j][k];
                    }
                    lock_result[c++] = ' ';
                }
            }


        }
        else{
            return EOF;
        }
    }
    return 0;
}
int unlock(char lock_result[], int b, char unlock_result[])
{
    int c = 0, d = 0;
    char in[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    char* out[36] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
      for(int j = 0; j < 36; j++){
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
  printf("请输入密码：\n");
  scanf("%s", original);
  int lock_b = strlen(original);
  if (lock(original, lock_b, lock_result) == EOF)
  {
    goto END;
  }
  printf("加密后的密码为：%s\n", lock_result);
  int unlock_b = strlen(lock_result);
  unlock(lock_result, unlock_b, unlock_result);
  printf("解密后的密码为：%s\n", unlock_result);
  return 0;
END:
  printf("密码中包含非字母或数字，无法加密或解密\n");
  return 0;
}