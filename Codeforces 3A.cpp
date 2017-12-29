#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

bool visited[8][8] = {0};
const int rows[] = {0, 0, -1, 1, -1, 1, -1, 1}, cols[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const string mov[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

struct Node{
    int col, row, index[100], moves;
    void init(int col, int row, int moves){
        this->col = col;
        this->row = row;
        this->moves = moves;
    }
};

bool validValues(int row, int col){
    if(row < 0 || col < 0 || row > 7 || col > 7 ) return false;
    return true;
}

void BFS(Node start, int rowF, int colF){
    queue<Node> cola;
    cola.push(start);
    while(!cola.empty()){
        Node nodo = cola.front();
        cola.pop();
        int row = nodo.row;
        int col = nodo.col;
        if(row == rowF && col == colF){
            printf("%d\n", nodo.moves);
            for(int i = 0; i < nodo.moves; i++){
                printf("%s\n", mov[nodo.index[i]].c_str());
            }
            return;
        } else{
            if(visited[row][col]) continue;
            visited[row][col] = true;
            for(int i = 0; i < 8; i++){
                int newRow = row + rows[i];
                int newCol = col + cols[i];
                if(validValues(newRow, newCol)){
                    Node newNodo;
                    newNodo.init(newCol, newRow, nodo.moves + 1);
                    nodo.index[nodo.moves] = i;
                    for(int j = 0; j <= nodo.moves; j++) newNodo.index[j] = nodo.index[j];
                    cola.push(newNodo);
                }
            }
        } 
    }
}

int main(){
    int rowI, colI, row, col;
    char cI, c;
    scanf("%c%d", &cI, &rowI);
    cin.get();
    scanf("%c%d", &c, &row);
    colI = cI - 'a';
    col = c - 'a';
    rowI = abs(rowI - 8);
    row = abs(row - 8);
    Node start;
    start.init(colI, rowI, 0);
    BFS(start, row, col);
    return 0;
}