#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mymax(int a ,int b,int c,int d){
    return max(max(a,b),max(c,d));
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,summ = 0,ans = 0;
    cin >> n;
    vector<int> c(n,0);
    for(int i = 0;i<n;i++){
        cin >> c[i];
        summ += c[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    // dp[i][j] is the max ans of billboards j,j+1,j+2,...,j+i (i+1 billboards)
    for(int i = 0;i<n;i++){
        for(int j = 0;j+i<n;j++){
            if(i == 0){
                dp[i][j] = c[j];
            }else if(i == 1){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]);
            }else{
                dp[i][j] = mymax(dp[i-1][j],dp[i-1][j+1],dp[i-2][j]+c[j+i],dp[i-2][j+2]+c[j]);
            }
        }
    }
    cout << dp[n-1][0];
    return 0;
}