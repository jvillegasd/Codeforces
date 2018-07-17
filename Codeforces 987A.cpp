#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
    map<string, pair<string, int>> gems;
    bool ans[] = {false, false, false, false, false, false, false};
    char input[50];
    int n;
    gems["purple"] = make_pair("Power", 0);
    gems["green"] = make_pair("Time", 1);
    gems["blue"] = make_pair("Space", 2);
    gems["orange"] = make_pair("Soul", 3);
    gems["red"] = make_pair("Reality", 4);
    gems["yellow"] = make_pair("Mind", 5);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &input);
        pair<string, int> p = gems[input];
        ans[p.second] = true;
    }
    printf("%d\n", 6 - n);
    for(map<string, pair<string,int>>::iterator it = gems.begin(); it != gems.end(); it++){
        if(!ans[(*it).second.second]) cout << (*it).second.first << endl;
    }
    return 0;
}