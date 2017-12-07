#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int M, int tam, int arr[]){
    int inf = 0, sup = tam - 1, mid;
    while(inf + 1 < sup){
        mid = (sup + inf)/2;
        if(M >= arr[mid]){
            inf = mid;
        }else{
            sup = mid;
        }
    }
    if(arr[sup] <= M) return sup + 1;
    else if(arr[inf] <= M) return sup;
    else return 0;
}

int main(){
    int m, n, a[200005], b[200005];
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + m);
    for(int i = 0; i < n; i++) cout << binarySearch(b[i], m, a) << " ";                                       
    return 0;
}