#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    int cnt = n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(n%2 == 0){
        int md1 = n/2-1;
        cout << v[md1];
    }else{
        int md1 = n/2;
        cout << v[md1];
    }
    return 0;
}