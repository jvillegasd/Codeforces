#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ai, sp = 0, dp = 0, l, r;
    vector<int> cards;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), cards.push_back(ai);
    l = 0;
    r = n - 1;
    for(int i = 0; i < n; i++){
        if(!(i % 2)){
            if(cards[l] >= cards[r]) sp+=cards[l], l++;
            else sp+=cards[r], r--;
        }
        else{
            if(cards[l] >= cards[r]) dp+=cards[l], l++;
            else dp+=cards[r], r--;
        }
    }
    printf("%d %d", sp, dp);
    return 0;
}