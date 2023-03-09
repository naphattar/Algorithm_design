#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,start = 0,stop = 0;
    cin >> n;
    int arr[n] = {0};
    for(int i = 0;i<n;i++) cin >> arr[i];
    int maxseq = arr[0];
    int bestans = arr[0],beststart = 0,beststop = 0;
    for(int i = 1;i<n;i++){
        if(arr[i] > maxseq+arr[i]){
            maxseq = arr[i];
            start = i;
            stop = i;
        }else{
            maxseq += arr[i];
            stop++;
        }
        if(maxseq > bestans){
            beststart = start;
            beststop = stop;
            bestans = maxseq;
        }
    }
    // find the second seq in the front;
    maxseq = -1001;
    int bestfront = maxseq;
    for(int i = 0;i<beststart;i++){
        if(arr[i] > maxseq + arr[i]){
            maxseq = arr[i];
        }else{
            maxseq += arr[i];
        }
        if(maxseq > bestfront){
            bestfront = maxseq;
        }
    }
     // find the second seq in the back;
    maxseq = -1001;
    int bestback = maxseq;
    for(int i = beststop+1;i<n;i++){
        if(arr[i] > maxseq + arr[i]){
            maxseq = arr[i];
        }else{
            maxseq += arr[i];
        }
        if(maxseq > bestback){
            bestback = maxseq;
        }
    }
    if(bestans + max(bestfront,bestback) > bestans) bestans += max(bestfront,bestback);
    cout << bestans;
    return 0;
}