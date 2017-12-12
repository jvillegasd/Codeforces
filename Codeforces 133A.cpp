#include <stdio.h>

using namespace std;

int main(){
    char input[120];
    bool found = false;
    scanf("%s", &input);
    for(int i = 0; input[i]; i++){
        if(input[i] == 'H' || input[i] == 'Q' || input[i] == '9'){
            printf("YES\n");
            found = true;
            break;
        }
    }
    if(!found) printf("NO\n");
    return 0;
}