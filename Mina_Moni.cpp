#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
    int n,x;
    cin >> n;
    x=n;
   vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
        sort(v.rbegin(),v.rend());
        int i=0,ans1=0,ans2=0,cnt1=0,cnt2=0;
        if(n%2) n--;
        while(i<n){
            while(ans1<=ans2 && cnt1<n/2 && i<n){
                ans1+=v[i];
                i++;
                cnt1++;
            }
            while(ans2<=ans1 && cnt2<n/2 && i<n){
                ans2+=v[i];
                i++;
                cnt2++;
                
            }
            if(cnt1==n/2 && i<n){
                ans2+=v[i];
                i++;

            }
            else if(cnt2==n/2 && i<n){
                ans1+=v[i];
                i++;
            }
        }
        if(x%2) {
            if(ans1==min(ans1,ans2)) ans1+=v[x-1];
            else ans2+=v[x-1];
        }
        cout << abs(ans1-ans2)  << endl;
    }
}
