#include <bits/stdc++.h>

using namespace std;

int white(char piece){
    if(piece == 'Q') return 9;
    if(piece == 'R') return 5;
    if(piece == 'B' || piece == 'N') return 3;
    if(piece == 'P') return 1;
    return 0;
}

int black(char piece){
    if(piece == 'q') return 9;
    if(piece == 'r') return 5;
    if(piece == 'b' || piece == 'n') return 3;
    if(piece == 'p') return 1;
    return 0;
}

int main(){
    int w = 0, b = 0;
    string input;
    for(int i = 0; i < 8; i++){
        cin >> input;
        for(int j = 0; j < 8; j++) w+=white(input[j]), b+=black(input[j]);
    }
    if(w > b) printf("White");
    else if(b > w) printf("Black");
    else printf("Draw");
    return 0;
}