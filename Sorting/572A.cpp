#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int na,nb,k,m;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> na >> nb >> k >> m;
    vector<int> a(na,0);
    vector<int> b(nb,0);
    for(int i = 0;i<na;i++){
        cin >> a[i];
    }
    for(int i = 0;i<nb;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int maxa = a[k-1];
    int minb = b[nb-m];
    if(maxa < minb){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}