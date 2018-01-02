#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

char game[2][100010];

bool valid(int row, int col){
    if(row < 0 || col < 0 || row >= 2) return false;
    return true;
}

bool BFS(int n, int k){
    queue<pair<int, pair<int, int>>> cola;
    bool visited[2][n];
    memset(visited, false, sizeof(visited[0][0]) * 2 * n);
    int rows[] = {0, 0, 1, -1}, cols[] = {1, -1, k, k};
    visited[0][0] = true;
    cola.push(make_pair(0, make_pair(0, 0)));
    while(!cola.empty()){
        int row = cola.front().second.first;
        int col = cola.front().second.second;
        int water = cola.front().first;
        cola.pop();
        for(int i = 0; i < 4; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];
            if(valid(nRow, nCol)){
                if(nCol >= n) return true;
                if(!visited[nRow][nCol] && game[nRow][nCol] != 'X' && nCol > water){
                    visited[nRow][nCol] = true;
                    cola.push(make_pair(water + 1, make_pair(nRow, nCol)));
                }               
            }
        }
    }
    return false;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 2; i++) scanf("%s", &game[i]);
    if(BFS(n, k)) printf("YES\n");
    else printf("NO\n");
    return 0;
}