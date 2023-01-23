#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n,k,x = 1e9;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> k;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(k == 0){
        x = v[0] > 1 ? 1 : -1;
        cout << x;
        return 0;
    }
    x = v[k-1];
    if(k < n && v[k] == v[k-1]){
        x = -1;
    }
    cout << x;
    return 0;
}