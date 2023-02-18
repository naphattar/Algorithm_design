#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<pair<int,int>,vector<int>> mp;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m,st;
    cin >> n >> m;
    vector<int> v(n+1,0),w(n+1,0);
    vector<int> used;
    for(int i = 0;i<n;i++){
        cin >> v[i+1];
    }
    for(int i = 0;i<n;i++){
        cin >> w[i+1];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            cin >> st;
            if(i > 0 && j > 0){
                if(j - w[i] >= 0 && dp[i-1][j-w[i]]+v[i] > dp[i-1][j]){
                    dp[i][j] = dp[i-1][j-w[i]]+v[i];
                    if(mp.count(make_pair(i-1,j-w[i]))){
                        vector<int> used = mp[make_pair(i-1,j-w[i])];
                        used.push_back(i);
                        mp[make_pair(i,j)] = used;
                    }else{
                        vector<int> used = {i};
                        mp[make_pair(i,j)] = used;
                    }
                }else{
                    dp[i][j] = dp[i-1][j];
                    mp[make_pair(i,j)] = mp[make_pair(i-1,j)];
                }
            }
        }
    }
    cout << mp[make_pair(n,m)].size() << '\n';
    for(auto t : mp[make_pair(n,m)]){
        cout << t << " ";
    }
    return 0;
}