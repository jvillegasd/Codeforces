#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

int main(){
    int tc, a, i;
    lli z;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &a);
        z = log2(a);
        z = pow(2, z + 1) - 1;
        if(z != a) printf("%lld\n", z);
        else{
            for(i = 2; i * i <= a; i++) if(!(a % i)) break;
            if(i * i > a) printf("1\n");
            else printf("%d\n", a/i);
        }
    }
    return 0;
}
/*
    Sea "z" el bit mas grande de "a" menos 1 (2^log2(a) - 1) y b = "z" XOR "a", existen 2 casos:
    -) Si "a" != "z", quiere decir que siempre cualquier "b" < "a", por lo que "a" AND "b"  = 0 y
        GCD("a" XOR "b", "a" AND "b") = GCD("z", 0) = "z".
    -) Si "a" == "z", hay que encontrar el divisor mas grande de "a" (Mas info en la editorial)
*/