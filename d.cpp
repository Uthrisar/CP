#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n;
    ll x, y;
    cin>>n>>x>>y;
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum += a[i];
    }
    ll x1 = sum-y;
    ll y1 = sum-x;
    ll ans = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i] > y1) continue;
        ll range_x = x1-a[i]-1;
        int lo = i+1, hi = n-1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(a[mid] <= range_x){
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        int lo2 = i+1, hi2 = n-1;
        ll range_y = y1-a[i];
        while(lo2 <= hi2){
            int mid = lo2+(hi2-lo2)/2;
            if(a[mid] <= range_y){
                lo2 = mid+1;
            } else {
                hi2 = mid-1;
            }
        }
        ans += (lo2-lo);
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
