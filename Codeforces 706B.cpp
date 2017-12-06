#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int M, int tam, int shops[]){
    int inf = 0, sup = tam - 1, mid;
    while(inf + 1 < sup){
        mid = (sup + inf)/2;
        if(M >= shops[mid]){
            inf = mid;
        }else{
            sup = mid;
        }
    }
    if(shops[sup] <= M) return sup + 1;
    else if(shops[inf] <= M) return sup;
    else return 0;
}

int main(){
    int N, Q, M;
    cin >> N;
    int shops[N];
    for(int i = 0; i < N; i++) cin >> shops[i];
    sort(shops, shops + N);
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> M;
        cout << binarySearch(M, N, shops) << endl;
    }
}