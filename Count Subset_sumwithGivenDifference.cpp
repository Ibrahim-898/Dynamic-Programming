// 
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
    int t;
    cin >> t;
    while(t--){
   ll n,sum=0,m,s1;
   cin >> n >> m;
        if(m==1000){
            cout << "YES" << endl;
            continue;
        }
        ll dif = 1000-m;
   vector<ll> v(n);
   for(int i=0;i<n;i++){
    cin >> v[i];
    sum+=v[i];
   }  
   s1 = (sum+dif);
   if(s1%2){
    cout << "NO" << endl;
    continue;
   }
   s1/=2;
    s=s1;
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
   for(int i=1;i<=n;i++){
    for(int j=0;j<=s;j++){
        if(dp[i][j]){
            if(j>0) st.insert(j);
        }
    }
   }
//    bool ans =subset_sum(n,v,sum);
   cout << st.size() << endl;
  for(auto u:st){
    cout << u << " ";
  }
    }

} 