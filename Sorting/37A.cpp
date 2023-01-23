#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int start = v[0];
    int height = 0,cnt = 1,maxheight = 0;
    for(int i = 0;i<n;i++){
        if(v[i] > start){
            cnt++;
            height = 1;
            start = v[i];
        }else{
            height++;
        
        }
        maxheight = max(height,maxheight);
    }
    cout << maxheight << " " << cnt;
    return 0;
}