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

Given an array arr, the problem is to print all the subsequences. There is a difference between a subsequence and a subarray

*/

class Solution
{
public:
void printSubSequence(int index, vi &A, vi arr){
    if(index>=arr.size()){
        pv(A);
        return;
    }

    A.push_back(arr[index]);
    printSubSequence(index+1, A, arr);

    A.pop_back();
    printSubSequence(index+1, A, arr);
}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi arr = {1,2,3,4};
    vi A;
    S->printSubSequence(0,A, arr);
    return 0;
}