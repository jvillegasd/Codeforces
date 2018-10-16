#include <bits/stdc++.h>

using namespace std;

bool isLetter(char l){
    return (l>='a'&&l<='z') || (l>='A'&&l<='Z');
}

int main(){
    string input;
    cin >> input;
    long long ans = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '@'){
            long long before = 0, after = 0;
            for(int j = i - 1; j >= 0; j--){
                if(input[j] == '@' || input[j] == '.') break;
                if(isLetter(input[j])) before++;
            }
            for(int j = i + 1; j < input.size(); j++){
                if(input[j] == '@' || input[j] == '_'){
                    i = j - 1;
                    break;
                }
                if(input[j] == '.'){
                    if(j == i + 1) break;
                    for(int k = j + 1; k < input.size(); k++){
                        if(!isLetter(input[k])) {
                            i = k - 1;
                            break;
                        }
                        i = k - 1;
                        after++;
                    }
                    break;
                }
            }
            /*
                Multiplicar para obtener las multiples parejas (mini emails) que se forman con esos caracteres
                consecutivos.
            */
            ans+=before*after; 
        }
    }
    cout << ans << endl;
    return 0;
}