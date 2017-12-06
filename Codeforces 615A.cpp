#include <iostream>

using namespace std;

int main(){
    int m, n, numBulbs, bulb, cont = 0;
    bool bulbs[110] = {false};
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> numBulbs;
        for(int j = 0; j < numBulbs; j++){
            cin >> bulb;
            bulbs[bulb] = true;
        }
    }
    for(int i = 1; i <= m; i++){
        if(bulbs[i]) cont++;
    }
    if(cont == m) printf("YES\n");
    else printf("NO\n");
    return 0;
}