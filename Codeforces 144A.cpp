#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int searchMin(int number, int arr[], int n){
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == number) pos = i;
        if(i == n - 1) return pos;
    }
    return -1;
}

int searchMax(int number, int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == number) return i;
    }
    return -1;
}

int maxValue(int arr[], int n){
    int max = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int minValue(int arr[], int n){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int main(){
    int n, arr[150], min = INT_MAX, max = -1, iMin, iMax, cont = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    min = minValue(arr, n);
    iMin = searchMin(min, arr, n);
    while(arr[n - 1] != min && iMin < n){
        swap(arr[iMin], arr[iMin + 1]);
        cont++;
        iMin++;
    }
    max = maxValue(arr, n);
    iMax = searchMax(max, arr, n);
    while(arr[0] != max && iMax > -1){
        swap(arr[iMax], arr[iMax - 1]);
        cont++;
        iMax--;
    }
    printf("%d\n", cont);
    return 0;
}