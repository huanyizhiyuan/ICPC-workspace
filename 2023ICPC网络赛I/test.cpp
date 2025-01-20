#include<bits/stdc++.h>
constexpr int mod = 20220911;
constexpr int inf = 1e9+5;
int n,m,k;
const int N=2e6;
int p[N];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int qmi(int a,int b){
     int res=1;
     while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
     }
     return res;
}
using namespace std;
void solve()
{
    std::string s;
    std::vector<std::string>a;
    while(true)
    {
        std::cin >> s;
        if(s == "fin")
            break;
        a.push_back(s);
    }

      int res=0;
      stack<int>sk;
      int cnt=0;
      bool flag=false;
      for(auto x:a){
          if(x=="repeat") {
                while(sk.top()==1){
                     sk.pop();
                     while(sk.top()==0) res++;
                }

                sk.push(0);
          }
          else if(x=="library"){
                sk.push(1);
          }
          else if(isdigit(x)){

          }
      }

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

