#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> k;
    vector<int> edges[n];
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    return 0;
}