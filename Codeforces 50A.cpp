#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%0.lf\n", floor(m/(double)2 * n));
    return 0;
}