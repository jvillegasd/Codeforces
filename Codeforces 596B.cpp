#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, sum, delta;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; i++) cin >> b[i];
    sum = b[0];
    for(int i = 1; i < n; i++){
        delta=b[i]-b[i-1];
        sum+=abs(delta);
    }
    printf("%d\n", sum);
    return 0;
}