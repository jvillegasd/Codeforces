#include <bits/stdc++.h>
#define pb push_back

using namespace std;
vector<int> g[100100];

int main(){
    int n, k, u, v;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n - 1; i++) scanf("%d %d", &u, &v), g[u].pb(v);
    
    return 0;
}