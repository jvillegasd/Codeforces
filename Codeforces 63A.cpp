#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
    vector<string> cap;
    vector<string> rat;
    vector<string> woChild;
    vector<string> man;
    int n;
    char name[50], status[50];
    scanf("%d", &n);
    while(n--){
        scanf("%s %s", &name, &status);
        if(strcmp(status, "captain") == 0) cap.push_back(name);
        if(strcmp(status, "rat") == 0) rat.push_back(name);
        if(strcmp(status, "woman") == 0 || strcmp(status, "child") == 0) woChild.push_back(name);
        if(strcmp(status, "man") == 0) man.push_back(name);
    }
    for(int i = 0; i < rat.size(); i++) cout << rat[i] << "\n";
    for(int i = 0; i < woChild.size(); i++) cout << woChild[i] << "\n";
    for(int i = 0; i < man.size(); i++) cout << man[i] << "\n";
    for(int i = 0; i < cap.size(); i++) cout << cap[i] << "\n";
    return 0;
}