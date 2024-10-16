#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t ;
    cin >> t;
    while(t--){
        ll n,sum=0,s;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum+=v[i];
        }
        if(sum%2){
            cout << "NO" << endl;
        }
        else
        {
            cout << n << " " <<sum << endl;
        sum/=2;
        s=sum;
        bool dp[n+5][s+5];
         dp[0][0]=true;
        for(int i=1;i<=s;i++) {
            dp[0][i]=false;
        }
       
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(v[i-1]<=j){
                    bool taken = dp[i-1][j-v[i-1]];
                    bool not_taken = dp[i-1][j];
                    dp[i][j]=taken || not_taken;
                    return dp[i][j];
                }
                else{
                    bool not_taken = dp[i-1][j];
                    dp[i][j]=not_taken;
                    return dp[i][j];
                    
                }
                
            }
        }
        cout << n << " " << s << endl;
        if(dp[n][s]){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        }
    }
}
