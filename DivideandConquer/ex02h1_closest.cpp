#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<pair<int,int>> points,middles;

bool sortbyy(pair<int,int> p1 , pair<int,int> p2){
    return p1.second < p2.second;
}
int distance(pair<int,int> p1,pair<int,int> p2){
    return pow((p1.first - p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second),0.5);
}

int bruteforce(int l,int r){
    int ans = 2e9;
    for(int i = l;i<r;i++){
        for(int j = i+1;j<=r;j++){
            ans = min(ans,distance(points[i],points[j]));
        }
    }
    return ans;
}
int closetpairs(int l,int r){
    if(r - l <= 2){
        return bruteforce(l,r);
    }
    int mid = (l+r)/2;
    int leftans = closetpairs(l,mid);
    int rightans = closetpairs(mid+1,r);
    int minans = min(leftans,rightans);
    //cout << l << " " << r << " minans  = " << minans << endl;
    middles.clear();
    for(int i = l;i<=r;i++){
        if(points[i].first - points[mid+1].first < minans && points[i].first - points[mid+1].first > -1*minans){
            middles.push_back(points[i]);
        }
    }
    sort(middles.begin(),middles.end(),sortbyy);
    for(int i = 0;i<middles.size()-1;i++){
        for(int j = i+1;j<middles.size() && middles[j].second-middles[i].second < minans;j++){
            minans = min(minans,distance(middles[i],middles[j]));
        }
    }
    return minans;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    sort(points.begin(),points.end());
    cout << closetpairs(0,n-1);
    return 0;
}