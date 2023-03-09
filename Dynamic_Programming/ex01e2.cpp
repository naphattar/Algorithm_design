#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int bestans = v[0];
    int maxseq = v[0];
    for(int i = 1;i<n;i++){
       maxseq = max(maxseq+v[i],v[i]);
       bestans = max(bestans,maxseq);
    }
    cout << bestans;

    return 0;
}