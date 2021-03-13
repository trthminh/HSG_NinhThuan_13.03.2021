//Truong Thanh Minh - Ninh Thuan 13.03.2021
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e5 + 7, oo = 1e18;
ll n, m, a[maxn], b[maxn], mx = -oo, pos, choose[maxn], res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("flowers.inp", "r", stdin);
    reopen("flowers.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i];
        if (mx < b[i])
        {
            mx = b[i];
            pos = i;
        }
        else if (mx == b[i])
        {
            if (a[i] > a[pos])
                pos = i;
        }
    }
    choose[pos] = 1;
    for (int i = 1; i <= m; ++i)
    {
        if (i == pos) continue;
        if (a[i] > mx)
            choose[i] = 1;
    }
    mx = -oo;
    for (int i = 1; i <= m; ++i)
        if (choose[i] == 1)
        {
            res += a[i];
            --n;
        }
    res += n * b[pos];
    cout << res;
}
