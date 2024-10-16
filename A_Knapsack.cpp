#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a.first!=b.first)
    return (a.first>b.first);
    else
     return (a.second<b.second);
}
const ll N =1001;
ll fact(ll n)
{
    return (n==1) ? 1: n * fact(n - 1); 
    // ? :
}
void solve(){
     ll n,W,w;
    cin >> n >> W;
    w=W;
    vector<pair<ll,ll>> v;
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;   
        v.push_back({x,i+1});
     }
         sort(v.begin(),v.end(),cmp);
         ll j=0,total=0;
         while(1){
            if(W >= v[j].first){
                total+=v[j].first;
                W-=v[j].first;
                ans.push_back(v[j].second);
            }
            j++;
            if(total*2>=w || j==n) break;


         }
         if(total*2<w){
            cout << -1 << endl;
            return;
         }
         cout << ans.size() << endl;
         for(auto u:ans){
            cout << u << " ";
         }
         cout << endl;

}
int main()
{
    ios();
    ll t;
    cin >> t;
    while(t--){
         solve();
     }

}