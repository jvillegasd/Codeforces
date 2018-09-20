#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, percent, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &percent);
        sum+=percent;
    }
    cout << (double)sum/n;
    return 0;
}