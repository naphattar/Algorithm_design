#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
vector<vector<long long>> m = {{2,1},{1,0}};
vector<vector<long long >> f = {{7},{3}};
const long long md = 987654321;
vector<vector<long long>> multiply(vector<vector<long long >> f, vector<vector<long long>> m){ // represent matrix f multiply matrix m
    vector<vector<long long>> res (2,vector<long long > (m[0].size(),0));
    for(int i = 0;i<2;i++){ // pick row from matrix f
        for(int j = 0;j<m[0].size();j++){ // pick column from matrix m
            long long ans = 0;
            for(int k = 0;k<2;k++){ // multiplying each row and column
                ans = (ans%md + ((f[i][k]%md)*(m[k][j]%md))%md)%md;
            }
            res[i][j] = ans; // keep the result in res
        }
    }
    return res;
}
vector<vector<long long>> power(vector<vector<long long>> v,long long n){ // calculate the f^n
    if(n  == 1){
        return {{2,1},{1,0}};
    }
    v = power(v,n/2);
    v = multiply(v,v);
    if(n%2 != 0){
        v = multiply(v,m);
    }
    return v;
}
long long solve(long long n){
    if(n == 1){
        return 3;
    }
    if(n == 2){
        return 7;
    }
    vector<vector<long long>> res = multiply(power(m,n-2),f);
    return res[0][0]%md;
}
int main(){
    ios_base::sync_with_stdio(false) , cin.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i<=n;i++){
        cout << "i = " << i << " " << solve(i) << "\n";

        }
    }
    return 0;
}