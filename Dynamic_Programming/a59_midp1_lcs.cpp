#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    //cin >> n >> m;
    string x,y;
    cin >> x >> y;
    n = x.length() , m = y.length();
    int dp[n+1][m+1];
    string words[n+1][m+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            //cin >> dp[i][j];
            if(i == 0 || j == 0){
                words[i][j] = "";
            }else{
                if(x[i-1] == y[j-1]){
                    words[i][j] = words[i-1][j-1] + x[i-1];
                }else{
                    if(words[i-1][j].length() > words[i][j-1].length()){
                        words[i][j] = words[i-1][j];
                    }else{
                        words[i][j] = words[i][j-1];
                    }
                }
            }
        }
    }
    cout << words[n][m];
    return 0;
}