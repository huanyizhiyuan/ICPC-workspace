#include<bits/stdc++.h>
#define i64 long long
int n,m,k;
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int mx=0;
    vector<int>in(n+100,0);
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        in[x]++,in[y]++;
        mx=max(mx,in[x]);
        mx=max(mx,in[y]);
    }
    if(mx%4 == 1) cout<<0<<endl;
    else if(mx %4 == 2)cout << 0 <<endl;
    else if(mx %4 == 3)cout << 1 << endl;
    else cout << 0 << "\n";
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
