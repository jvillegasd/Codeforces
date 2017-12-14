#include <iostream>

using namespace std;

bool fall = false;
char iceCave[510][510];
int row, col, r2, c2;

void backtracking(int r1, int c1){
    if(iceCave[r1][c1] == '.'){
        if(r1 >= 1 && r1 <= row && c1 >= 1 && c1 <= col){
            iceCave[r1][c1] = 'X';
            backtracking(r1+1, c1);
            backtracking(r1-1, c1);
            backtracking(r1, c1-1);
            backtracking(r1, c1+1);
        }
    }else if(r1 == r2 && c1 == c2){
        if(iceCave[r1][c1] == '.') iceCave[r1][c1] = 'X';
        else if(iceCave[r1][c1] == 'X') fall = true;
    }
}

int main(){
    int r1, c1;
    cin >> row >> col;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++) cin >> iceCave[i][j];
    }
    cin >> r1 >> c1 >> r2 >> c2;
    iceCave[r1][c1] = '.';
    backtracking(r1, c1);
    if(fall) printf("YES\n");
    else printf("NO\n");
    return 0;
}