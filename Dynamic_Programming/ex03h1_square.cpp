#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int r,c,maxans = 0;
    cin >> r >> c;
    char arr[r][c];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    int left[r][c] = {{0}};
    int up[r][c] = {{0}};
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(j == 0) left[i][j] = arr[i][j] == '1' ? 1 : 0;
            else{
                left[i][j] = arr[i][j] == '1' ? left[i][j-1]+1 : 0;
            }
        }
    }
    for(int j = 0;j<c;j++){
        for(int i = 0;i<r;i++){
            if( i == 0) up[i][j] = arr[i][j] == '1' ? 1 : 0;
            else{
                up[i][j] = arr[i][j] == '1' ? up[i-1][j]+1 : 0;
            }
        }
    }
    int dp[r][c] = {{0}};
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(i*j == 0) dp[i][j] = arr[i][j] == '1' ? 1 : 0;
            else if(left[i][j] > dp[i-1][j-1] && up[i][j] > dp[i-1][j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = min(left[i][j],up[i][j]);
            }
            maxans = max(maxans,dp[i][j]);
        }
    }
    cout << maxans;
    return 0;
}