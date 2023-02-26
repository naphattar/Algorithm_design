#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> d(n+1,0);
    vector<int> qs(n+1,0);
    qs[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> d[i];
        d[i] -= m;
        qs[i] = qs[i-1]+d[i];
    }
    while(k--){
        int pos,need;
        cin >> pos >> need;
        int anspos = lower_bound(qs.begin(),qs.end(),need+qs[pos-1]) - qs.begin();
        cout << anspos << "\n";
    }
    return 0;
}