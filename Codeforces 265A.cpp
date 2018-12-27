#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < t.length(); i++){
        if(ans == s.length() - 1) break;
        if(t[i] == s[ans]) ans++;
    }
    printf("%d", ans + 1);
    return 0;
}