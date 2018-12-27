#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, xi, mini, maxi;
    vector<int> cities;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &xi), cities.push_back(xi);
    for(int i = 0; i < n; i++){
        if(i != 0 && i != n - 1){
            mini = min(abs(cities[i] - cities[i - 1]), abs(cities[i] - cities[i + 1]));
            maxi = max(abs(cities[i] - cities[0]), abs(cities[n - 1] - cities[i]));
        }
        if(i == 0){
            mini = abs(cities[i + 1] - cities[i]);
            maxi = abs(cities[n - 1] - cities[i]);
        }
        if(i == n - 1){
            mini = abs(cities[i] - cities[i - 1]);
            maxi = abs(cities[i] - cities[0]);
        }
        printf("%d %d\n", mini, maxi);
    }
    return 0;
}