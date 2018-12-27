#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ai;
    vector<int> cube;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), cube.push_back(ai);
    sort(cube.begin(), cube.end());
    for(int i = 0; i < n; i++) printf("%d ", cube[i]);
    return 0;
}