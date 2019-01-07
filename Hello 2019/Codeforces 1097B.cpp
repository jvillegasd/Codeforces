#include <bits/stdc++.h>
#define pb push_back

using namespace std;
vector<int> angles;
bool possible = false;

void BT(int i, int ans, int n){
    if(i == n){
        if(ans % 360 == 0) possible = true; 
        return;
    }
    BT(i + 1, ans + angles[i], n);
    BT(i + 1, ans - angles[i], n);
}

int main(){
    int n, ai, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), angles.pb(ai);
    BT(0, 0, n);
    if(possible) printf("YES");
    else printf("NO");
    return 0;
}