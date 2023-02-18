#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    string x,y;
    cin >> x >> y;
    n = x.length();
    m = y.length();
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    cout <<dp[n][m];
    return 0;
}