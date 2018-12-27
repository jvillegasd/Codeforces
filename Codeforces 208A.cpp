#include <bits/stdc++.h>

using namespace std;

int main(){
    bool spc = false;
    string inp;
    cin >> inp;
    for(int i = 0; i < inp.length(); i++){
        if(inp[i] == 'W' && inp[i + 1] == 'U' && inp[i + 2] == 'B'){
            if(spc) printf(" ");
            i+=2;
        }
        else cout << inp[i], spc = true;
    }
    return 0;
}