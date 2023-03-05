#include<iostream>
using namespace std;
const int md = 100000007;
int dp[10000001][3] = {{0}};

int main(){
    int n;
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i = 2;i<=n;i++){
        dp[i][0] = (dp[i-1][0]%md+dp[i-1][1]%md+dp[i-1][2]%md)%md;
        dp[i][1] = (dp[i-1][0]%md+dp[i-1][2]%md)%md;
        dp[i][2] = (dp[i-1][0]%md+dp[i-1][1]%md)%md;
    }
    cout << (dp[n][0]%md+dp[n][1]%md+dp[n][2]%md)%md;
    return 0;
}
