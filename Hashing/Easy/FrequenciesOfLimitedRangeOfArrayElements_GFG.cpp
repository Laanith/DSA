#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A)
{
    cout << endl;
    for (auto x : A)
        cout << x << ' ';
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
}

/*!SECTION : Problem Description ::
Given an array arr[] of n positive integers which can contain integers from 1 to p where elements can be repeated or can be absent from the array.
Your task is to count the frequency of all numbers from 1 to n. Do modify the array in-place changes in arr[], such that arr[i] = frequency(i) and assume 1-based indexing.

Note: The elements greater than n in the array can be ignored for counting.

Your Task:
You don't need to read input or print anything. Complete the function frequencyCount() that takes the array arr, and integers n, and p as input parameters and modify the array in-place to denote the frequency count of each element from 1 to N.

Expected time complexity: O(N)
Expected auxiliary space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ p ≤ 4*104 
1 <= arr[i] <= p
*/

class Solution
{
public:
    void frequencyCount(vi &arr, int N, int P)
    {
        map<int, int> m;
        for (auto x : arr)
            m[x]++;
        for (int i = 1; i <= N; i++)
        {
            if (m.count(i))
                arr[i - 1] = m[i];
            else
                arr[i - 1] = 0;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi A = {2,3,2,3,5};
    S->frequencyCount(A, 5, 5);
    pv(A);

    return 0;
}