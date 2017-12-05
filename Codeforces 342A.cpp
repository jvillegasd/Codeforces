#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int N, vector[8] = {0}, s1 = 0, s2 = 0, s3 = 0;
  bool hit = true;
  cin >> N;
  for(int i = 0; i < N; i++){
      int index;
      cin >> index;
      vector[index]++;
  }
  for(int i = 0; i < N/3; i++){
      if(vector[4] > 0 && vector[2] > 0 && vector[1] > 0){
        s1++;
        vector[4]--;
        vector[2]--;
        vector[1]--;
        continue;
    }
    if(vector[6] > 0 && vector[2] > 0 && vector[1] > 0){
        s2++;
        vector[2]--;
        vector[6]--;
        vector[1]--;
        continue;
    }
    if(vector[3] > 0 && vector[6] > 0 && vector[1] > 0){
        s3++;
        vector[3]--;
        vector[6]--;
        vector[1]--;
        continue;
    }
    hit = false;
    break;
  }
  if((vector[5] != 0 && vector[7] != 0) || !hit) printf("-1\n");
  else{
      for(int i = 0; i < s1; i++) printf("1 2 4\n");
      for(int i = 0; i < s2; i++) printf("1 2 6\n");
      for(int i = 0; i < s3; i++) printf("1 3 6\n");
  }
  return 0;
}