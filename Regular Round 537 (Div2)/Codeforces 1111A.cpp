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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[0];

bool vol(char l){
    return l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u';
}

int main(){
    int v1 = 0, c1 = 0, v2 = 0, c2 = 0; 
    BOOST;
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(s.length() != t.length()){
        printf("No");
        return 0;
    }
    for(int i = 0; i < s.length(); i++){
        if(vol(s[i]) != vol(t[i])){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}