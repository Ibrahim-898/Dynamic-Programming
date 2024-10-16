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
// int fact(int n)
// {
//     return (n==1) ? 1: n * fact(n - 1); 
//     // ? :
// }
const int N=100;
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
int main()
{
   int n;
   cin >> n;
   int ans = fact(n);
   cout << ans << endl;
}