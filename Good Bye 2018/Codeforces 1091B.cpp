#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pii;

int main(){
    lli n, xi, yi, ai, bi;
    vector<pii> obelisk, clue;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) scanf("%lld %lld", &xi, &yi), obelisk.pb({xi, yi});
    for(int i = 0; i < n; i++) scanf("%lld %lld", &ai, &bi), clue.pb({ai, bi});
    xi = yi = 0;
    for(int i = 0; i < n; i++) xi+=obelisk[i].first + clue[i].first, yi+=obelisk[i].second + clue[i].second;
    printf("%lld %lld", xi/n, yi/n);
    return 0;
}
/*
    La estrategia es utilizar la afirmacion de que siempre existe una permutacion de este tipo:
                            (tx, ty) = (xi + ai, yi + bi) = (xj + aj, yj + bj)
    Entonces, el problema se reduce a sumar todos los puntos y dividirlo entre n.
*/