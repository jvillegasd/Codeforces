#include <bits/stdc++.h>

using namespace std;

int main(){
    int y, b, r, mini;
    scanf("%d %d %d", &y, &b, &r);
    mini = min(y, min(b, r));
    if(mini == r || (mini == y && r - y == 1)) printf("%d", 3*r - 3);
    else if(mini == b) printf("%d", 3*b);
    else printf("%d", 3*y + 3);
    return 0;
}