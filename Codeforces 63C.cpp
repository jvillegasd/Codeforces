#include <iostream>
#include <vector>

using namespace std;   //Guardar en char arrays para optimizar, implementacion == hacerlo a lo maldita sea.

int n, x[11], y[11];
char guesser[11][6];
char guess[11];

bool itsAnswer(){
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(guess[i] == guess[j]) return false;
        }
    }
    for(int i = 0; i < n; i++){
        int bulls = 0, cow = 0;
        for(int j = 0; j < 4; j++){
            if(guesser[i][j] == guess[j]) bulls++;
        }
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(j == k) continue;
                if(guesser[i][j] == guess[k]) cow++;
            }
        }
        if(x[i] != bulls || y[i] != cow) return false;
    }
    return true;
}

int main(){
    vector<string> ans;
    cin >> n;
    bool end = false;
    for(int i = 0; i < n; i++) cin >> guesser[i] >> x[i] >> y[i];
    for(char i = '0'; i <= '9' && !end; i++){
        for(char j = '0'; j <= '9' && !end; j++){
            for(char k = '0'; k <= '9' && !end; k++){
                for(char l = '0'; l <= '9' && !end; l++){
                    guess[0]=i;
                    guess[1]=j;
                    guess[2]=k;
                    guess[3]=l;
                    if(itsAnswer()) ans.push_back(guess);
                    if(ans.size() > 1){
                        end = true;
                        break;
                    }
                }
            }
        }
    }
    if(ans.size() == 1) printf("%s\n", ans[0].c_str());
    else if(ans.size() > 1) printf("Need more data\n");
    else printf("Incorrect data\n");
    return 0;
}