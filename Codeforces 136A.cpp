#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

int main(){
    int n, pi;
    vector<pair<int, int> > arr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &pi), arr.push_back(make_pair(pi, i + 1));
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < n; i++) printf("%d ", arr[i].second);
    return 0;
}