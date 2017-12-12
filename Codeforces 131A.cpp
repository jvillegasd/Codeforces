#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(){
    char input[120];
    int len = 0, caps = 0;
    scanf("%s", &input);
    for(int i = 0; input[i]; i++){
        len++;
        if(input[i] >= 'A' && input[i] <= 'Z') caps++;
    }
    if(caps == len - 1 && input[0] >= 'a' && input[0] <= 'z'){
        for(int i = 0; input[i]; i++){
            if(i == 0) printf("%c", toupper(input[i]));
            else printf("%c", tolower(input[i]));
        }
        printf("\n");
    }else if(caps == len){
        for(int i = 0; input[i]; i++) printf("%c", tolower(input[i]));
        printf("\n");
    }else printf("%s\n", input);
    return 0;
}