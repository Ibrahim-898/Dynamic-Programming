#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first)
    return (a.first<b.first);
    else
     return (a.second>b.second);
}
int fact(int n)
{
    return (n==1) ? 1: n * fact(n - 1); 
    // ? :
}
const int N=100;

void solve(){
    ll n,x,sum=0;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }
    sum+=x;
    if(sum%2 || sum<=0) {
        cout << "NO" << endl;
        return;
    }
    sum/=2;
    ll s = sum;
    bool dp[n+1][s+1];
    dp[0][0]=true;
    for(int i=1;i<=s;i++) {
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(v[i-1]<=j){
            bool  taken = dp[i-1][j-v[i-1]];
            bool not_taken = dp[i-1][j];
            dp[i][j]=taken || not_taken;
            }
            else{
                 bool not_taken = dp[i-1][j];
            dp[i][j]=not_taken;
            }
        }
    }
    if(dp[n][s]) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main()
{
   solve();
}