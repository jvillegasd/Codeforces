#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0, l, r, index;
    char lw = 'a';
    string inp, tape = "opqrstuvwxyzabcdefghijklmn";
    cin >> inp;
    for(int i = 0; i < inp.length(); i++){
        index = (12 + lw - 'a') % 26;
        l = r = 0;
        while(tape[index] != inp[i]) r++, index++, index%=26; //Der
        index = (12 + lw - 'a') % 26;
        while(tape[index] != inp[i]){ //Izq
            l++;
            index--;
            if(index < 0) index = 25;
        }
        ans+=min(l, r);
        lw = inp[i];
    }
    printf("%d", ans);
    return 0;
}