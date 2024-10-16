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
const int N=1005;
set<int> st;
int s;
int main()
{
   ll n,sum=0;
   cin >> n;
   vector<ll> v(n);
   for(int i=0;i<n;i++){
    cin >> v[i];
    sum+=v[i];
   }
   s=sum;
   int dp[n+5][s+5];
   dp[0][0]=true;
   for(int i=1;i<=s;i++){
    dp[0][i]=false;
   }
   for(int i=1;i<=n;i++){
    for(int j=0;j<=s;j++){
        if(v[i-1]<=j){
            dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
    }
   }
   vector<ll> ans;
   for(int i=1;i<=n;i++){
    for(int j=0;j<=s;j++){
        if(dp[i][j]){
             ans.push_back(j);
        }
    }
   }
   ll mn = 1e9+7;
   for(int i=0;i<ans.size()-1;i++){
    mn = min(mn,abs(ans[i]-(ans.back()-ans[i])));
   }
   cout << mn << endl;
}