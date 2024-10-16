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
const int N=100;

int main()
{
    int n;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int sum ;
    cin >> sum;
    int m=sum;
    bool dp[n+1][m+1];
      dp[0][0]=true;
        for(int j=1;j<=m;j++){
             dp[0][j]=false;        
            }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(v[i-1]<=j){
                bool taken = dp[i-1][j-v[i-1]];
                bool not_taken = dp[i-1][j];
                dp[i][j]= taken || not_taken;
            }
            else{
                bool not_taken = dp[i-1][j];
                dp[i][j]=not_taken;
            }

        }
    }
     for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout <<  dp[i][j] << " ";
        }
        cout << endl;
    }
}