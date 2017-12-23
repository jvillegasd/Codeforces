#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

bool adjMatrix[7][7] = {0};

int index(char name[]){ //Para no gastar espacio innecesario
    if(strcmp(name, "Anka") == 0) return 0;
    else if(strcmp(name, "Chapay") == 0) return 1;
    else if(strcmp(name, "Cleo") == 0) return 2;
    else if(strcmp(name, "Troll") == 0) return 3;
    else if(strcmp(name, "Dracul") == 0) return 4;
    else if(strcmp(name, "Snowy") == 0) return 5;
    else return 6;
}

int teamLikes(int team1, int team2, int team3){
    int heroes[7], temp[7], cont;
    long long int likes = INT_MIN, aLikes;
    iota(heroes, heroes + 7, 0);
    do{
        aLikes = 0;
        vector<int> teams[3];
        memcpy(temp, heroes, sizeof(temp));
        cont = 0;
        for(int i = 0; i < 7; i++){
            if(temp[i] != -1) teams[0].push_back(temp[i]), temp[i] = -1, cont++;
            if(cont == team1) break;
        }
        cont = 0;
        for(int i = 0; i < 7; i++){
            if(temp[i] != -1) teams[1].push_back(temp[i]), temp[i] = -1, cont++;
            if(cont == team2) break;
        }
        cont = 0;
        for(int i = 0; i < 7; i++){
            if(temp[i] != -1) teams[2].push_back(temp[i]), temp[i] = -1, cont++;
            if(cont == team3) break;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < teams[i].size(); j++){
                int out = teams[i][j];
                for(int k = 0; k < teams[i].size(); k++){
                    int in = teams[i][k];
                    if(adjMatrix[out][in]) aLikes++;
                }
            }
        }
        likes = max(likes, aLikes);
    }while(next_permutation(heroes, heroes + 7));
    return likes;
}

int main(){
    long long n, a, b, c, delta, maxExp, minExp, exp1, exp2, exp3, newLikes, in, out, likes;
    scanf("%lld", &n);
    cin.get();
    for(int i = 0; i < n; i++){
        char name1[500], name2[500];
        scanf("%s likes %s", &name1, &name2);
        out = index(name1), in = index(name2);
        adjMatrix[out][in] = true;
    }
    scanf("%lld %lld %lld", &a, &b, &c);
    delta = INT_MAX;
    for(int i = 1; i <= 5; i++){ //Cantidad de integrantes por equipo, cada for-loop es un equipo
        for(int j = 1; j <= 5; j++){
            for(int k = 1; k <= 5; k++){
                if(i + j + k == 7){
                    exp1 = a/i, exp2 = b/j, exp3 = c/k;
                    maxExp = max(exp1, max(exp2, exp3));
                    minExp = min(exp1, min(exp2, exp3));
                    if(maxExp - minExp < delta){
                        delta = maxExp - minExp;
                        likes = teamLikes(i, j, k);
                    }else if(maxExp - minExp == delta){
                        newLikes = teamLikes(i, j, k);
                        if(newLikes > likes) likes = newLikes;
                    }
                }
            }
        }
    }
    printf("%lld %lld\n", delta, likes);
    return 0;
}
/*
    La estrategia es generar por fuerza bruta la cantidad de integrantes de los equipos para obtener el delta minimo y
    con esa informacion hacer todas las combinaciones posibles para generar el equipo con mayor cantidad de likes.
    Recomendacion: Usar un DAG para representar a quien le gusta quien.
*/