#include <iostream>

using namespace std;

int main(){
    int n, a, b, sum = 0;
    cin >> n;
    int vector[n];
    n--;
    for(int i = 0; i < n; i++) cin >> vector[i];
    cin >> a >> b;
    a--;
    b--;
    for(int i = a; i < b; i++) sum += vector[i];
    cout << sum << endl;
    return 0;
}