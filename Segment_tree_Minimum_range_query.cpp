#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define PII pair<int, int>
#define INF LLONG_MAX

int seg[1000000];
int nums[1000000];
void build(int index,int low,int high){
    if(low == high){
        seg[index] = nums[low];
        return;
    }
    int mid = (low+high)/2;
    build((2*index)+1,low,mid);
    build((2*index)+2,mid+1,high);
    seg[index] = min(seg[(2*index)+1],seg[(2*index)+2]);
    return;
}

int query(int index,int l,int r,int low,int high){
    if(low>=l && r>=high){
        return seg[index];
    }
    else if(high<l || low>r){
        return INT_MAX;
    }
    int mid = (low+high)/2;
    int left = query(2*index+1,l,r,low,mid);
    int right = query(2*index+2,l,r,mid+1,high);
    return min(left,right);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    build(0,0,n-1);
    vector<int> ans;
    for(int i = 0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int answer = query(0,l-1,r-1,0,n-1);
        ans.push_back(answer);
    }
    for(auto i : ans){
        cout<<i<<endl;
    }
    return;
}
signed main(){
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}