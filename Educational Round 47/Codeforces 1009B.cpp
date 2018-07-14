#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    int one = 0, zero = 0;
    bool enter;
    cin >> a;
    for(int i = 0; i < a.length(); i++) if(a[i] == '1') one++;
    int j = 0;
    while(j < a.length() && a[j]!='2'){
        if(a[j] == '0') zero++;
        j++;
    }
    while(zero > 0){
        printf("0");
        zero--;
    }
    while(one > 0){
        printf("1");
        one--;
    }
    while(j < a.length()){
        if(a[j] != '1') printf("%c", a[j]);
        j++;
    }
    return 0;
}