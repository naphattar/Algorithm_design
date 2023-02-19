#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    int r,c;
    cin >> r >> c;
    int arr[r][c];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    int dp[r][c] = {{0}};
    dp[0][0] = arr[0][0];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(i > 0 && j > 0 ){
                dp[i][j] = max(2*arr[i][j]+dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1])+arr[i][j]);
            }else if(i > 0){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }else if(j > 0){
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
        }
    }
    cout << dp[r-1][c-1];
    return 0;
}