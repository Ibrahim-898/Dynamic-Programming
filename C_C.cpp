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
int MOD= 998244353;
const int N=100;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int mx = INT_MIN;
        int mul=1;

        for(int i=0;i<v.size();i++)
        {
         mul = ((mul % MOD) * (v[i] % MOD)) % MOD;
        mul = (mul + MOD) % MOD;
        cout << mul << endl;
          mx=max(mul,mx);
          if(mul==0)
           mul=1;
        }
        mul=1;
        for(int i=v.size()-1;i>=0;i--)
        { 
        mul = ((mul % MOD) * (v[i] % MOD)) % MOD;
        mul = (mul + MOD) % MOD;
          mx=max(mul,mx);
          if(mul==0)
           mul=1;
        }
        cout << mul%MOD << endl;
    
    
}
int main()
{
    ios();
    int  t ;
   cin >> t;
    while(t--){
        solve();

    }
}