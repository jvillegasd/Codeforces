#include <bits/stdc++.h>

using namespace std;

int main(){
    int s1, s2, s3, s4, ans = 0;
    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
    if(s1 == s2 || s1 == s3 || s1 == s4) ans++;
    if(s2 == s3 || s2 == s4) ans++;
    if(s3 == s4) ans++;
    printf("%d", ans);
    return 0;
}