#include <bits/stdc++.h>
#define pb push_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];
int arr[1100], prime[1100];

int main(){
    int n, num, sum = 0;
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i = 0; i < n - 1; i++) printf("1 ");
    printf("1");
    return 0;
}