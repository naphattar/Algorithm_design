#include<iostream>
#include<vector>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    return 0;

}