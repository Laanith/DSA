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
Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.
*/

class Solution
{
public:
    int searchInSorted(int arr[], int N, int k){
        int mid;
        int left  = 0, right = N-1;
        while(left<=right){
            mid = left + (right-left)/2;
            if(arr[mid]==k) return 1;
            else if (arr[mid] < k) left = mid+1;
            else right = mid -1;
        }
        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    int arr[] = {1,2,3,4,6};
    pint(S->searchInSorted(arr, 5,6));

    return 0;
}