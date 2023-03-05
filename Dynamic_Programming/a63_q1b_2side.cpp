#include<iostream>
#include<vector>
using namespace std;
/*
Testcase 1
10 1 3
2 5 7 8 4 3 9 5 1 4
9 5 7 3 1 6 8 4 2 5
*/
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,w,k;
    cin >> n >> w >> k;
    vector<int> l(n+1,0);
    vector<int> r(n+1,0);
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(k+1,make_pair(0,0))); 
    for(int i = 1;i<=n;i++) cin >> l[i];
    for(int i = 1;i<=n;i++) cin >> r[i];
    int maxans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(i > w){
                for(int m = 1;m<i-w;m++){
                    dp[i][j].first = max(dp[i][j].first , dp[m][j-1].second+l[i]);
                    dp[i][j].second = max(dp[i][j].second , dp[m][j-1].first + r[i]);
                }
            }
            if(dp[i][j].first > maxans) maxans = dp[i][j].first;
            if(dp[i][j].second > maxans) maxans = dp[i][j].second;
        }
    }
    cout << maxans;
    return 0;
}