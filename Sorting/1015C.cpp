#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a,b,cnt=0;
long long suma = 0;
int main(){
    ios_base::sync_with_stdio(false) , cin.tie(nullptr);
    cin >> n >> m;
    vector<int> diff(n,0);
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        diff[i] = a-b;
        suma += a;
    }
    sort(diff.begin(),diff.end());
    long long needed = suma-m;
    if(needed <= 0){
        cout << cnt;
        return 0;
    }
    for(int i = n-1;i>=0;i--){
        needed -= diff[i];
        cnt++;
        if(needed <=0){
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
    return 0;
}