#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

int MAX = numeric_limits<int>::max();

int main(){
    int n, number, mini = MAX, index, delta;
    vector<int> input;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &number), input.push_back(number), mini = min(mini, number);
    if(n == 2) printf("1\n");
    else{
        delta = MAX;
        index = MAX;
        for(int i = 0; i < n; i++){
            if(input[i] == mini){
                delta = min(delta, abs(i - index));
                index = i;
            }
        }
        printf("%d\n", delta);
    }
    return 0;
}