#include <bits/stdc++.h>

using namespace std;

int main(){
    string inp;
    int k, len, sn = 0, cc = 0;
    cin >> inp;
    scanf("%d", &k);
    len = inp.length();
    for(int i = 0; i < inp.length(); i++){
        if(inp[i] == '*') sn++;
        if(inp[i] == '?') cc++;
    }
    len = len - cc - sn;
    if(k < len - cc - sn || (k > len && sn == 0)){
        printf("Impossible");
        exit(0);
    }
    if(len == k) {for(auto l : inp) if(l != '*' && l != '?') cout << l;}
    else if(len < k){
        for(int i = 0; i < inp.length(); i++){
            if(inp[i] == '*'){
                while(len < k) cout << inp[i - 1], len++;
            }else if(inp[i] != '?') cout << inp[i];
        }
    }else if(k < len){
        for(int i = 0; i < inp.length(); i++){
            if(inp[i + 1] == '*' || inp[i + 1] == '?'){
                if(len > k) k++;
                else cout << inp[i];
            }else if(inp[i] != '*' && inp[i] != '?') cout << inp[i];
        }
    }
    return 0;
}