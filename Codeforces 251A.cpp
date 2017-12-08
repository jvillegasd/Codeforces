#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    long right, n, d;
    long long ans, points;   
    scanf("%ld %ld", &n, &d);
    long arr[n] = {0};
    for(long i = 0; i < n; i++) scanf("%ld", &arr[i]);
    right = 0;
    ans = 0;
    for(long left = 0; left < n - 1; left++){
        while(right < n && arr[right] <= arr[left] + d)right++;
        right--;
        points = right - left;
        ans += points*(points-1)/2; //C(n, 2)
    }
    printf("%I64d\n", ans);
    return 0;
}