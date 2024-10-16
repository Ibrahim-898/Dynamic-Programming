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
bool dp[N][N];
bool subset_sum(ll n,vector<ll> v,ll sum){
    if(n==0){
        if(sum==0){
            return true;

        }
        else return false;
    }
    if(v[n-1]<=sum){
        bool taken = subset_sum(n-1,v,sum-v[n-1]);
        bool not_taken = subset_sum(n-1,v,sum); 
        dp[n-1][sum]=taken || not_taken;
        return dp[n-1][sum];

    }
    else{
         bool not_taken = subset_sum(n-1,v,sum); 
        dp[n-1][sum]=not_taken;
        return dp[n-1][sum];
    }

}
int main()
{
   ll n,sum=0;
   cin >> n;
   vector<ll> v(n);
   for(int i=0;i<n;i++){
    cin >> v[i];
    sum+=v[i];
   }
   if(sum%2) {
    cout <<  "Not possible" << endl; 
    return 0;
   }
   sum/=2;
   if(subset_sum(n,v,sum)) cout << "YES" << endl;
   else cout << "NO" << endl;

}