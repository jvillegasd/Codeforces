#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a = 0, d = 0;
    char input[200000];
    scanf("%d %s", &n, input);
    for(int i = 0; i < n; i++){
        if(input[i] == 'A') a++;
        else if(input[i] == 'D') d++;
    }
    if(a > d) printf("Anton");
    else if(d > a)printf("Danik");
    else printf("Friendship");
    return 0;
}