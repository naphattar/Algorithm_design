#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n,a,b;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<pair<int,int>> labtop(n,{0,0});
    for(int i = 0;i<n;i++){
        cin >> labtop[i].first >> labtop[i].second;
    }
    sort(labtop.begin(),labtop.end());
    for(int i = 1;i<n;i++){
        if(labtop[i].first > labtop[i-1].first && labtop[i].second < labtop[i-1].second){
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
    return 0;
}