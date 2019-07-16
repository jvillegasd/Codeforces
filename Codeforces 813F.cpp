#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
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
vector<pii> segTree[400010];
int parent[100010], color[100010], sz[100010], ans[100010], cnt=0;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    a%=b;
    return gcd(b, a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

int binsearch(int n, lli arr[], lli sum){
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==sum) return mid;
        if(arr[mid]<sum) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

struct state{
    int iRoot, setsz, jRoot, jRootP, jRootC, invalid_state;
    state(int iRoot, int setsz, int jRoot, int jRootP, int jRootC){
        this->iRoot=iRoot;
        this->setsz=setsz;
        this->jRoot=jRoot;
        this->jRootP=jRootP;
        this->jRootC=jRootC;
        this->invalid_state=0;
    }
    state(int invalid_state){
        iRoot=setsz=jRoot=jRootP=jRootC=0;
        this->invalid_state=invalid_state;
    }
};

stack<state> s;

int find(int i){
    if(i == parent[i]) return i;
    return find(parent[i]);
}

int getColor(int i){
    int ans=0;
    while(1){
        ans^=color[i];
        if(i==parent[i]) break;
        i=parent[i];
    }
    return ans;
}

void unionSet(int i, int j){
    int iRoot=find(i), jRoot=find(j), iColor=getColor(i), jColor=getColor(j);
    if(iRoot!=jRoot){
        if(sz[iRoot] < sz[jRoot]) swap(iRoot, jRoot), swap(iColor, jColor);
        s.push(state(iRoot, sz[iRoot], jRoot, parent[jRoot], color[jRoot]));
        parent[jRoot]=iRoot;
        sz[iRoot]+=sz[jRoot];
        if(iColor==jColor) color[jRoot]^=1;
    }else{
        if(iColor==jColor) cnt++, s.push(state(-1));
        else s.push(state(0));
    }
}

void rollback(){
    if(s.empty()) return;
    state rb_state=s.top();
    s.pop();
    parent[rb_state.jRoot]=rb_state.jRootP;
    color[rb_state.jRoot]=rb_state.jRootC;
    sz[rb_state.iRoot]=rb_state.setsz;
    cnt+=rb_state.invalid_state;
}

void DFS(int u, int l, int r){
    for(auto e : segTree[u]) unionSet(e.fp,e.sp);
    if(l==r) ans[l]=(cnt==0);
    else{
        int mid=(l+r)/2;
        DFS(2*u,l,mid);
        DFS(2*u+1,mid+1,r);
    }
    for(auto e : segTree[u]) rollback();
}

void insertNode(int node, int l, int r, int s, int e, int u, int v){
    if(r < s || l > e) return;
    if(l>=s&&r<=e){
        segTree[node].pb({u,v});
        return;
    }
    int mid=(l+r)/2;
    insertNode(2*node,l,mid,s,e,u,v);
    insertNode(2*node+1,mid+1,r,s,e,u,v);
}

int main(){
    int n, q, x, y;
    map<pii, vector<pii>> data;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) parent[i]=i, color[i]=0, sz[i]=1;
    for(int i = 1; i <= q; i++){
        scanf("%d %d", &x, &y);
        vector<pii> &ranges=data[{x,y}];
        if(!ranges.empty()&&ranges.back().sp==-1) ranges.back().sp=i-1;
        else ranges.pb({i,-1});
    }
    for(auto &di : data){
        if(di.sp.back().sp==-1) di.sp.back().sp=q;
        for(auto ri : di.sp) insertNode(1,1,q,ri.fp,ri.sp,di.fp.fp,di.fp.sp);
    }
    DFS(1,1,q);
    for(int i=1; i<=q; i++) if(ans[i]) printf("YES\n"); else printf("NO\n");
    return 0;
}
