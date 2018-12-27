#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[b.length() - 1 - i]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}