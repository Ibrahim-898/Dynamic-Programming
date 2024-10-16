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
const int N =1001;
int fact(int n)
{
    return (n==1) ? 1: n * fact(n - 1); 
    // ? :
}
int weight[N];
int value[N];
int dp[N][N];
int knapsack(int n,int W) {
    if(n<0 || W==0) return 0;
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(weight[n]<=W){
        int op1 = value[n]+knapsack(n-1,W-weight[n]);
        int op2 = 0 + knapsack(n-1,W);
        return dp[n][W] = (max(op1,op2));
    }
    else{ 
        int op2 = 0 + knapsack(n-1,W);
        return dp[n][W] = op2;
    }
    
}
int main()
{
    ios();
    int n,W;
    cin >> n >> W;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }
    for(int i=0;i<n;i++){
        cin >> value[i];
    }
    int ans = knapsack(n-1,W);
    cout << ans << endl;

}