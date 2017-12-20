#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char input[20], str1[20], str2[20];
    int len = 0, cont = 0, lenO;
    scanf("%s", &input);
    lenO = len = strlen(input);
    if(len % 2 != 0) for(int i = len/2; input[i]; i++) input[i] = input[i + 1];
    len = strlen(input);
    for(int i = 0; i < len; i++){
        if(i < len/2) str1[i] = input[i];
        else str2[i - len/2] = input[i];
    }
    for(int i = 0; i < len/2; i++) if(str1[i] != str2[len/2 - i - 1]) cont++;
    if(cont == 1 || cont == 0 && lenO % 2 != 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}