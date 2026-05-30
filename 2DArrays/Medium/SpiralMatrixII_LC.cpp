#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A, int width = 4)
{
    for (auto x : A)
        cout << setw(width) << right << x;
    cout << endl;
}
void pint(int A) { cout << endl
                        << A << endl; }
void pp(pair<int, int> p) { cout << p.first << ' ' << p.second << endl; }
void pvvi(vvi A)
{
    for (auto v : A)
    {
        pv(v);
    }
    cout << endl;
}

/*!SECTION : Problem Description ::

*/

class Solution
{
public:
    vvi generateMatrix(int n)
    {
        vvi mat(n, vi(n, 0));
        int k = 1, temp;
        int u = 0, l = 0, d = n - 1, r = n - 1;
        while (k <= n * n)
        {
            for (int i = l; i <= r; i++)
                mat[u][i] = k++;
            u++;
            for (int i = u; i <= d; i++)
                mat[i][r] = k++;
            r--;
            for (int i = r; i >= l; i--)
                mat[d][i] = k++;
            d--;
            for (int i = d; i >= u; i--)
                mat[i][l] = k++;
            l++;
        }
        return mat;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    pvvi(S->generateMatrix(6));
    cout << endl;
    pvvi(S->generateMatrix(4));

    return 0;
}