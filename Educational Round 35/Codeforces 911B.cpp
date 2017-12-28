#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b, minPiece, pieceA, pieceB, maxP = 0;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i < n; i++){
        pieceA = a/i, pieceB = b/(n - i);
        if(pieceA > 0 && pieceB > 0){
            minPiece = min(pieceA, pieceB);
            maxP = max(maxP, minPiece);
        }
    }
    printf("%d\n", maxP);
    return 0;
}