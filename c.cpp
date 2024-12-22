#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<int> a(m), q(k);
        for(int i=0; i<m; i++){
            cin>>a[i];
        }
        vector<int> known(n+1, false);
        for(int i=0; i<k; i++){
            cin>>q[i];
            known[q[i]] = true;
        }
        int notKnown = 0;
        int notKnownSubject;
        for(int i=1; i<=n; i++){
            if(known[i] == false){
                notKnownSubject = i;
                notKnown++;
            }
        }
        if(notKnown == 0){
            for(int i=0; i<m; i++){
                cout<<1;
            }
        } else if(notKnown >= 2){
            for(int i=0; i<m; i++){
                cout<<0;
            }
        } else {
            for(int i=0; i<m; i++){
                if(a[i] == notKnownSubject){
                    cout<<1;
                } else{
                    cout<<0;
                }
            }
        }
        cout<<endl;
    }
}