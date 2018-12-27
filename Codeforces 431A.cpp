#include <bits/stdc++.h>

using namespace std;

int main(){
    int a1, a2, a3, a4, ans = 0;
    string game;
    scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
    cin >> game;
    for(int i = 0; i < game.length(); i++){
        if(game[i] == '1') ans+=a1;
        if(game[i] == '2') ans+=a2;
        if(game[i] == '3') ans+=a3;
        if(game[i] == '4') ans+=a4;
    }
    printf("%d", ans);
    return 0;
}