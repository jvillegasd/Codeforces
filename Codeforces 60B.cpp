#include <stdio.h>
#include <tuple>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

char plate[11][11][11];
int x, y, z;
const int rows[] = {1, -1, 0, 0}, cols[] = {0, 0, 1, -1}, profs[] = {1, -1};

bool valid(int row, int col, int prof){
    if(row < 0 || col < 0 || prof < 0 || row >= y || col >= x || prof >= z) return false;
    return true;
}

int BFS(int row, int col){
    bool visited[z][y][x];
    queue<tuple<int, int, int>> cola;
    int time = 0;
    memset(&visited[0][0][0], false, sizeof(visited));
    cola.push(tuple<int, int, int>(0, row, col));
    visited[0][row][col] = true;
    while(!cola.empty()){
        tuple<int, int, int> node = cola.front();
        int prof = get<0>(node);
        int row = get<1>(node);
        int col = get<2>(node);
        time++;
        cola.pop();
        for(int i = 0; i < 4; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];
            if(valid(nRow, nCol, prof) && !visited[prof][nRow][nCol] && plate[prof][nRow][nCol] == '.'){
                visited[prof][nRow][nCol] = true;
                cola.push(tuple<int, int, int>(prof, nRow, nCol));
            }
        }
        for(int i = 0; i < 2; i++){
            int nProf = prof + profs[i];
            if(valid(row, col, nProf) && !visited[nProf][row][col] && plate[nProf][row][col] == '.'){
                visited[nProf][row][col] = true;
                cola.push(tuple<int, int, int>(nProf, row, col));
            }
        }
    }
    return time;
}

int main(){
    int row, col;
    scanf("%d%d%d", &z, &y, &x);
    for(int i = 0; i < z; i++){
        for(int j = 0; j < y; j++) scanf("%s", &plate[i][j]);
    }
    scanf("%d %d", &row, &col);
    printf("%d\n", BFS(row - 1, col - 1));
    return 0;
}