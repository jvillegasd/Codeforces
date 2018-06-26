#include <math.h>
#include <stdio.h>

int main(){
    long double x,y,xl,yl;
    scanf("%Lf %Lf",&x,&y);
    xl=y*log(x);
    yl=x*log(y);
    if(xl>yl) printf(">");
    else if(yl>xl) printf("<");
    else printf("=");
}