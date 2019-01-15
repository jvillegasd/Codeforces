#include <bits/stdc++.h>
#define pb push_back
#define addEdge(u, v) g[u].pb(v), g[v].pb(u)

using namespace std;
typedef long long int lli;
vector<int> g[0];

int main(){
    int n, m, a[1000100], pool[1000100], problems = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++){
        if(pool[a[i]] == 0) problems++;
        pool[a[i]]++;
        if(problems == n){
            problems = 0;
            printf("1");
            for(int j = 1; j <= n; j++){
                pool[j]--;
                if(pool[j]) problems++;
            }
        }else printf("0");
    }
    return 0;
}