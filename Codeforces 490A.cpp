#include <bits/stdc++.h>

using namespace std;

struct tp{
    int a, b, c;
};

int main(){
    int n, w = 0, ti, is, js, ks;
    vector<pair<int, int> > skl;
    vector<tp> ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ti), skl.push_back({ti, i});
    sort(skl.begin(), skl.end());
    for(int i = 0; i < n; i++){
        if(skl[i].first == 1){
            for(int j = i + 1; j < n; j++){
                if(skl[j].first == 2){
                    for(int k = j + 1; k < n; k++){
                        if(skl[k].first == 3){
                            is = skl[i].second + 1;
                            js = skl[j].second + 1;
                            ks = skl[k].second + 1;
                            ans.push_back({is, js, ks});
                            skl[i].first = skl[j].first = skl[k].first = 0;
                            w++;
                            break;
                        }
                    }
                    if(skl[j].first == 0) break;
                }
            }
        }
    }
    printf("%d\n", w);
    for(int i = 0; i < w; i++) printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
    return 0;
}