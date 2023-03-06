#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    int arr[n+1] = {0};
    long long qs[n+1] = {0};
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        qs[i] = qs[i-1]+arr[i]+k;
    }
    while(m--){
        int a;
        long long b;
        cin >> a >> b;
        int idx = upper_bound(qs,qs+n+1,qs[a]+b) - qs -1;
        cout << qs[idx]-qs[a]-(idx-a)*k << "\n";
    }
    return 0;
}