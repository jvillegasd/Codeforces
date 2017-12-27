#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char s[120], t[120];
    scanf("%s %s", &s, &t);
    for(int i = strlen(s) - 1; i >= 0; i--){
        if(s[i] == 'z') s[i] = 'a';
        else{
            s[i]+=1;
            break;
        }
    }
    if(strcmp(s, t) >= 0) printf("No such string\n");
    else printf("%s\n", s); 
    return 0;
}