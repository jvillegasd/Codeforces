#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, seq = 1, maxSeq = 1;
    scanf("%d", &n);
    int input[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
        if(i > 0){
            if(input[i] >= input[i - 1]){
                seq++;
                maxSeq = max(maxSeq, seq);
            } else seq = 1; 
        }
    }
    printf("%d\n", maxSeq);
    return 0;
}