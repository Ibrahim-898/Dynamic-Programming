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
const ll N=1e6+5;
ll dp[N];
ll fibonacci(ll n) {
    if(n==0 || n==1) return n;
    if(dp[n]!=-1){
        return dp[n];
    }
    ll ans = fibonacci(n-1)+fibonacci(n-2);
    dp[n]=ans;
    return ans;
    
    
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll n;
    cin >> n;
    ll ans = fibonacci(n);
    cout << ans << endl;
}