#include<bits/stdc++.h>
using namespace std;
int n,m,k,w,total = 0,shoted = 0;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k >> w;
    vector<int> pomp(k,0);
    vector<pair<int,int>> pos(m,{0,0});
    vector<int> health(m,0);
    for(int i = 0;i<m;i++){
        cin >> pos[i].first;
    }
    for(int i = 0;i<m;i++){
        cin >> pos[i].second;
        total += pos[i].second;
    }
    for(int i = 0;i<k;i++){
        cin >> pomp[i];
    }
    sort(pomp.begin(),pomp.end());
    sort(pos.begin(),pos.end());
    for(int i = 0;i<k;i++){
        int l = pomp[i]-w;
        int r = pomp[i]+w;
        int idx = lower_bound(pos.begin(),pos.end(),make_pair(l,0)) - pos.begin();
        if(pos[idx].first <= r && pos[idx].second > 0){
                total--;
        }
    }
    cout << total;
    return 0;
}