#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int m,n,k;
    cin >> n >> m >> k;
    if(k >= n){
        // impossible
        cout << 0;
        return 0;
    }
    // (amount,(firstblock,lastcolor))
    vector<vector<pair<int,pair<int,int>>>> dp(n+1,vector<pair<int,pair<int,int>>>(k+1,make_pair(0,make_pair(1,0))));
    dp[1][0].first= 1; // length 1 and 0 color changing 
    dp[1][0].second.first= 1; // first black block is 1
    for(int i = 2;i<=n;i++){
        // case j == 0 no color changing
        if(i - dp[i-1][0].second.first < m){
                // can add same color
               dp[i][0] = dp[i-1][0];
        }else{
            dp[i][0].first = 0;
            dp[]
        }
        for(int j = 1;j<=k;j++){
            if(i - dp[i-1][j].second.first < m){
               dp[i][j] = dp[i-1][j];
            }
            // change color
            dp[i][j].first += dp[i-1][j-1].first;
            dp[i][j].second.first= i;
            dp[i][j].second.second = dp[i-1][j-1].second.second == 1 ? 0 : 1;
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=k;j++){
            cout << dp[i][j].first << " ";
        }
        cout << endl;
    }
    cout << dp[n][k].first;
    return 0;
}