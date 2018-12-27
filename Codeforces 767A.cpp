#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    int n, ai;
    vector<int> sn;
    priority_queue<int> pq;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ai), sn.push_back(ai);
    for(int i = 0; i < sn.size(); i++){
        pq.push(sn[i]);
        while(!pq.empty() && pq.top() == n) printf("%d ", n--), pq.pop();
        printf("\n");
    }
    return 0;
}