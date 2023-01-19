#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
map<int,int> mp;
void perm(int n, vector<int> &sol,int len , vector<bool> &used){
    if(len < n){
        for(int i = 0;i<n;i++){
            if(!used[i]){
                if((!mp.count(i)) || (mp.count(i) && used[mp[i]])){
                    used[i] = true;
                    sol[len] = i;
                    perm(n,sol,len+1,used);  
                    used[i] = false;
                }
            }
        }
    }else{
        for(auto &k : sol ){
            cout << k << " ";
        }
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false) ,cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        mp[b] = a;
    }
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    perm(n,sol,0,used);
    return 0;
}