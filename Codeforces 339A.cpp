#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> ans;
    char number;
    while(scanf("%c", &number) && number != '\n'){
        if(number >= '1' && number <= '9') ans.push_back(number-'0');
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
        if(i != ans.size() - 1) printf("+");
    }
    printf("\n");
    return 0;
}