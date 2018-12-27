#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    int n, ai, bi;
    vector<int> a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &ai, &bi), a.push_back(ai), b.push_back(bi), c.push_back(ai);
    sort(c.begin(), c.end(), cmp);
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            printf("rated");
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && a[i] != c[i]){
            printf("unrated");
            return 0;
        }
    }
    printf("maybe");
    return 0;
}