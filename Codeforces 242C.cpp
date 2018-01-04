#include <stdio.h>
#include <queue>
#include <map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(), rows[] = {0, 0, -1, 1, -1, 1, -1, 1}, cols[] = {-1, 1, 0, 0, -1, -1, 1, 1};
map<pair<int, int>, int> chessB;

int BFS(int yo, int xo, int y, int x){
    queue<pair<int, int>> cola;
    chessB[make_pair(yo, xo)] = 0;
    cola.push(make_pair(yo, xo));
    while(!cola.empty()){
        int row = cola.front().first;
        int col = cola.front().second;
        int dist = chessB[make_pair(row, col)];
        if(row == y && col == x) break;
        cola.pop();
        for(int i = 0; i < 8; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];
            if(chessB.count(make_pair(nRow, nCol)) > 0 && chessB[make_pair(nRow, nCol)] > dist + 1){
                chessB[make_pair(nRow, nCol)] = dist + 1;
                cola.push(make_pair(nRow, nCol));
            }
        }
    }
    if(chessB[make_pair(y, x)] < INF) return chessB[make_pair(y, x)];
    return -1;
}

int main(){
    int xo, yo, x, y, n, row, colo, col;
    scanf("%d %d %d %d %d", &yo, &xo, &y, &x, &n);
    while(n--){
        scanf("%d %d %d", &row, &colo, &col);
        for(int i = colo; i <= col; i++) chessB[make_pair(row, i)] = INF;
    }
    printf("%d\n", BFS(yo, xo, y, x));
    return 0;
}