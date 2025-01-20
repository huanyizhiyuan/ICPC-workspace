#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 mod = 998244353;

struct Mat{
    i64 arr[101][101];
    int a, b;
    Mat(int n, int m) : a(n), b(m){
        memset(arr, 0, sizeof(arr));
    }

    Mat operator * (const Mat &m) const{
        Mat res(a, m.b);
        for (int i = 0;i < a;i ++){
            for (int j = 0;j < b;j ++){
                for (int k = 0;k < m.b;k ++){
                    (res.arr[i][k] += arr[i][j] * m.arr[j][k]) %= mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for(int i = 0;i < a;i ++)
        {
            for(int j = 0;j < b;j ++)
                std::cout << arr[i][j] << " ";
            std::cout << "\n";
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    //单位矩阵。
    Mat Tr(m + 1, m + 1);
    for (int i = 0;i <= m;i ++){
        Tr.arr[i][i] = 1;
    }

    for (auto e : s){
        Mat Q(m + 1, m + 1);
        //单位矩阵。
        for (int i = 0;i <= m;i ++){
            Q.arr[i][i] = 1;
        }
        for (int i = 0;i < m;i ++){
            if (t[i] == e){
                Q.arr[i][i + 1] = 1;
            }
        }
        std::cout << "Q:\n";
        Q.print();
        std::cout << "\n";

        std::cout << "Tr:\n";
        Tr = Tr * Q * Tr;
        Tr.print();
        std::cout << "\n";
    }

    cout << Tr.arr[0][m] << "\n";

    return 0;
}

/*
a
aba
abaaaba

a
aba
abacaba
abacabadabacaba
*/
