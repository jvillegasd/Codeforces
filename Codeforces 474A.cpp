#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main(){
    char move;
    string input;
    cin >> move;
    cin >> input;
    if(move == 'R'){
        for(int i = 0; i < input.length(); i++){
            for(int j = 0; j < keyboard.length(); j++){
                if(keyboard[j] == input[i]){
                  cout << keyboard[j - 1];
                  break;
                }
            }
        }
    } else{
        for(int i = 0; i < input.length(); i++){
            for(int j = 0; j < keyboard.length(); j++){
                if(keyboard[j] == input[i]){
                  cout << keyboard[j + 1];
                  break;
                }
            }
        }
    }
    return 0;
}