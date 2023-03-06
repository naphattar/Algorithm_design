#include<iostream>
#include<vector>
using namespace std;
const int md = 100000007;

vector<vector<long long>> arr = {
    {1,0,1,0},
    {1,0,0,0},
    {0,1,0,1},
    {0,1,0,1}
};

vector<vector<long long>> multiply(vector<vector<long long >> f, vector<vector<long long>> m){ // represent matrix f multiply matrix m
    vector<vector<long long>> res (4,vector<long long > (m[0].size(),0));
    for(int i = 0;i<4;i++){ // pick row from matrix f
        for(int j = 0;j<m[0].size();j++){ // pick column from matrix m
            long long ans = 0;
            for(int k = 0;k<4;k++){ // multiplying each row and column
                ans = (ans + f[i][k]*m[k][j])%md;
            }
            res[i][j] = ans; // keep the result in res
        }
    }
    return res;
}

vector<vector<long long>> power(vector<vector<long long>> v,long long n){ // calculate the f^n
    if(n  == 1){
        return v;
    }
    v = power(v,n/2);
    v = multiply(v,v);
    if(n%2 != 0){
        v = multiply(v,arr);
    }
    return v;
}

int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> initarr = {{1},{1},{1},{1}};
    vector<vector<long long>> result = multiply(power(arr,n-2),initarr);
    cout << (result[0][0]%md+result[1][0]%md+result[2][0]%md+result[3][0]%md)%md;
    return 0;
}