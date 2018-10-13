#include <bits\stdc++.h>

using namespace std;

int main(){
    set<string> comb;
    string input, nw;
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        nw = input.substr(i, input.size() - i) + input.substr(0, i);
        comb.insert(nw);
    }
    printf("%d", comb.size());
    return 0;
}