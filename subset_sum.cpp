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
const int N=1001;
int dp[N][N];
bool subset_sum(int n,vector<int> &v,int sum){
    if(n==0){
        if(sum==0){
            return true;
        }
        else
        return false;
    }
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(v[n-1]<=sum){
        bool taken = subset_sum(n-1,v,sum-v[n-1]);
        bool not_taken = subset_sum(n-1,v,sum);
        dp[n][sum] = taken || not_taken;
        return dp[n][sum];

    }
    else{
         bool not_taken = subset_sum(n-1,v,sum);
         dp[n][sum] = not_taken;
         return dp[n][sum];
      }

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int sum ;
    cin >> sum;
    bool ans = subset_sum(n,v,sum);
    cout << ans << endl;
}