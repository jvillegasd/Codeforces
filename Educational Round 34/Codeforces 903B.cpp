#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int h1, a1, c1, h2, a2;
    vector<bool> battle;
    scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);
    while(h2 > 0){
        if(h2 - a1 <= 0){ //Last hit
            h2 -= a1;
            battle.push_back(true);
            break;
        }else if(h1 - a2 > 0){ //If Vova can attack
            h1 -= a2;
            h2 -= a1;
            battle.push_back(true);
        }else{ //else he needs to heal himself
            h1 += c1 - a2;
            battle.push_back(false);
        }
    }
    printf("%d\n", battle.size());
    for(int i = 0; i < battle.size(); i++){
        if(battle[i]) printf("STRIKE\n");
        else printf("HEAL\n");
    }
    return 0;
}
/*
    La estrategia es recrear la batalla, usando un vector de booleano para saber si Vova ataca o se cura,
    la batalla termina cuando el modcrab muera, ya que se nos dice que Vova siempre gana.
*/