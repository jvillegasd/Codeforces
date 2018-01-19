#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    int n, p, l, r;
    scanf("%d %d %d %d", &n, &p, &l, &r);
    if(l == 1 && r == n) printf("0\n");
    else if(l == 1 && r != n) printf("%d\n", abs(p - r) + 1);
    else if(r == n && l != 1) printf("%d\n", abs(p - l) + 1);
    else printf("%d\n", min(abs(p - l), abs(p - r)) + 2 + r - l);
    return 0;
}