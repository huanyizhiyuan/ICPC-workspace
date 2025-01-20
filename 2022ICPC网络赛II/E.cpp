#include<bits/stdc++.h>
#define int long long
int n,m,k;
using  namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int res=k;
    vector<int>v;
    map<int,int>m;
    for(int i=2;i<=k/i;i++){
        if(k%i==0){
            m[i]=m[k/i]=1;
        }
    }
    if(!(k&1)){
        for(int i=3;;i+=2){
            if(!m.count(i)) {
                res+=i;
                break;
            }
        }

        if(n % 2 == 0)
            res += 5 * (n - 2) / 2;
        else
            res += 5 * (n - 2 + 1) / 2 - 3;
    }
    else {
        res += 2;
        if(n % 2 == 0)
            res += 5 * (n - 2) / 2;
        else
            res += 5 * (n - 2 + 1) / 2 - 2;
    }
    cout<<res<<endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
   // std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}
