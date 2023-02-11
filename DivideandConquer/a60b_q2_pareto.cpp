#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int,int>> points(100001,{0,0});

bool mysort(pair<int,int> a,pair<int,int> b){
    // sort the point by x-axis maximum -> minimum
    return  a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(),points.begin()+n,mysort);
    int maxy = -1;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(points[i].second > maxy){
            maxy = points[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}