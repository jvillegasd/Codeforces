#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, x, y, ai;
    vector<int> wires;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), wires.push_back(ai);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        if(x - 2 < wires.size()) wires[x - 2]+= y - 1;
        if(x >= 0) wires[x]+= abs(wires[x - 1] - y);
        wires[x - 1] = 0;
    }
    for(int i = 0; i < n; i++) printf("%d\n", wires[i]);
    return 0;
}