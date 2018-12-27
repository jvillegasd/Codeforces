#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

int main(){
    int d, h, v, e;
    double s, vs;
    scanf("%d %d %d %d", &d, &h, &v, &e);
    s = pi * d * d / 4;
    vs = v/s;
    if(vs <= e) printf("NO");
    else printf("YES\n%.6lf", h / (vs - e));
    return 0;
}