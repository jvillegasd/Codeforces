#include <bits/stdc++.h>

using namespace std;

int main(){
    map<long long int, long long int> mapa;
    vector<long long int> beauty;
    long long int n, b, delta, comb;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &b), beauty.push_back(b), mapa[b]++;
    sort(beauty.begin(), beauty.end());
    delta = beauty[n - 1] - beauty[0];
    comb = mapa[beauty[n - 1]] * mapa[beauty[0]];
    if(mapa[beauty[n - 1]] == n) comb = n * (n - 1)/2; //C(n, 2)
    printf("%lld %lld", delta, comb);
    return 0;
}