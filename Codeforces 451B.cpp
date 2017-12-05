#include <iostream>
#include <algorithm>

using namespace std;

bool isSorted(int arr[], int N){
    for(int i = 0; i < N - 1; i++){
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main(){
    int N, R = 0, L = 0;
    cin >> N;
    int array[N];
    for(int i = 0; i < N; i++) cin >> array[i];
    for(int i = 0; i < N - 1; i++){
        if(array[i] > array[i + 1]){
            L = i;
            break;
        }
    }
    R = L;
    while(R < N - 1 && array[R] > array[R + 1]){
        R++;
    }
    if(N == 1){
        printf("yes\n");
        printf("1 1\n");
    }else {
        reverse(array + L, array + R + 1);
        if(isSorted(array, N)){
            printf("yes\n");
            cout << (L + 1) << " " << (R + 1) << endl;
        }else printf("no\n");
    }
    return 0;
}