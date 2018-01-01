#include <stdio.h>
#include <queue>
#include <string.h>
#include <limits>

using namespace std;

char map[1010][1010];
int rowE, colE, rowS, colS, r, c, dist[1010][1010], MAX = numeric_limits<int>::max();
const int rows[] = {0, 1, 0, -1}, cols[] = {1, 0, -1, 0};

bool valid(int row, int col){
    return row < 0 || row >= r || col < 0 || col >= c;
}

int BFS(){
    queue<pair<int, int>> cola;
    int minB = 0;
    dist[rowE][colE] = 0;
    cola.push(make_pair(rowE, colE));
    while(!cola.empty()){
        int row = cola.front().first;
        int col = cola.front().second;
        cola.pop();
        for(int i = 0; i < 4; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];
            if(valid(nRow, nCol) || map[nRow][nCol] == 'T') continue;
            if(dist[nRow][nCol] == MAX){
                dist[nRow][nCol] = dist[row][col] + 1;
                cola.push(make_pair(nRow, nCol));
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j]>='1' && map[i][j]<='9' && dist[i][j] <= dist[rowS][colS]) minB+= map[i][j]-'0';
        }
    }
    return minB;
}

int main(){
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++) scanf("%s", &map[i]);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == 'E') rowE = i, colE = j;
            if(map[i][j] == 'S') rowS = i, colS = j;
            dist[i][j] = MAX;
        }
    }
    printf("%d\n", BFS());
    return 0;
}