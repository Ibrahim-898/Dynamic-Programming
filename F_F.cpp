#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
bool cmp(const pair<string,int> &a,const pair<string,int> &b){
    return (a.second<b.second);
    
}
const int N=100;
void solve() {
    int n,q;
    cin >> n >> q;
    vector<pair<string,int>> v;
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        v.push_back({s,x});
    }
    sort(v.begin(),v.end(),cmp);
    map<string,int> mp;
    for(int i=0;i<n;i++){
        mp[v[i].first]=i;
    }
    while(q--){
        string c;
        cin >> c;
       int loc =mp[c];
       if(loc==n-1) {
        cout << "No More Chapters" << endl;
       }
       else {
        cout << v[loc+1].first <<endl;
       }
        
    }
    
    
}
int main()
{
    ios();
    int  t = 1;
   cin >> t;
    while(t--){
        solve();
    }
}