#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int h, m, x, y;
    scanf("%d", &x);
    cin >> h >> m;
    while(h % 10 != 7 && m % 10 != 7){
        if(m < x){
            m = 60 + (m - x);
            if(h == 0) h = 23;
            else h--;
        }else m-=x;
        y++;
    }
    printf("%d\n", y);
    return 0;
}