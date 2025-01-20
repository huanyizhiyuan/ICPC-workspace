#include<bits/stdc++.h>
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;
const int N=2e6;
int p[N];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
       p[i]=0;
    for(int i=1;i<=n-1;i++){
         int x,y;
         cin>>x>>y;
         p[x]++,p[y]++;
    }
    for(int i=1;i<=n;i++) {
        if(p[i]==1) cnt++;

    }
    if(n==1) cnt=1;
    cout<<cnt<<endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
     std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

