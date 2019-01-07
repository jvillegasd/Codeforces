#include <bits/stdc++.h>

using namespace std;

int main(){
    bool possible = false;
    string h, t;
    cin >> h;
    getline(cin, t);
    getline(cin, t);
    for(int i = 0; i < t.length(); i++){
        if(t[i] == ' ') continue;
        if(t[i] == h[0] || (t[i] == h[1] && t[i - 1] != ' ')){
            possible = true; 
            break;
        }
    }
    if(possible) printf("YES");
    else printf("NO");
    return 0;
}