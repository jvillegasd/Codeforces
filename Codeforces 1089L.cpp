#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool cmp(const pair<lli, lli> &a, const pair<lli, lli> &b){
    return a.second < b.second;
}

int main(){
    lli n, k, ai, bi, total = 0, ans = 0;
    vector<lli> a;
    vector<pair<lli, lli> > ab;
    map<lli, lli> jobs;
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%lld", &ai), a.push_back(ai), jobs[ai]++;
        if(jobs[ai] == 1) total++;
    }
    for(int i = 0; i < n; i++) scanf("%lld", &bi), ab.push_back(make_pair(a[i], bi));
    sort(ab.begin(), ab.end(), cmp);
    total = k - total;
    for(int i = 0; i < n; i++){
        if(jobs[ab[i].first] > 1 && total > 0){
            ans+=ab[i].second;
            total--;
            jobs[ab[i].first]--;
        }
    }
    printf("%lld", ans);
    return 0;
}