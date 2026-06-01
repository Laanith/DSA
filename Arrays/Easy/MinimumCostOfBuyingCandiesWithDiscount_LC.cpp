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
A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

Example 1:

Input: cost = [1,2,3]
Output: 5
Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
Example 2:

Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
Example 3:

Input: cost = [5,5]
Output: 10
Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.


Constraints:

1 <= cost.length <= 100
1 <= cost[i] <= 100
*/

class Solution
{
public:
    int minimumCost(vi &cost)
    {
        sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < cost.siz(); i++)
        {
            if ((i + 1) % 3 == 0)
                continue;
            sum += cost[i];
        }
        return sum;
    }

#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
    void pv(vi A)
    {
        for (auto x : A)
            cout << x << ' ';
        cout << endl;
    }

    int minimumCost_MyInitialSolution(vector<int> &cost)
    {
        sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0, n = cost.size();
        for (int i = 0; i < n; i += 3)
        {
            if (i < n && i + 1 < n)
            {
                sum += (cost[i] + cost[i + 1]);
            }
            else if (i < n && i + 1 >= n)
            {
                sum += cost[i];
                continue;
            }
            else
            {
                continue;
            }
        }

        return sum;
    };
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi cost = {6, 5, 7, 9, 2, 2};
    pint(S->minimumCost(cost));
    return 0;
}