#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl

/*!SECTION : Problem description


You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to
    (x-1, y-1),
    (x-1, y)  ,
    (x-1, y+1),
    (x  , y-1),
    (x  , y+1),
    (x+1, y-1),
    (x+1, y)  ,
    (x+1, y+1)
You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

*/

using namespace std;

class Solution
{
    public :
    int MinStepsInInfiniteGrid(vector<int> x_coOrdinates, vector<int> y_coOrdinates);
};

int Solution::MinStepsInInfiniteGrid(vector<int> x_coOrdinates, vector<int> y_coOrdinates){
    int sum = 0;
    for (int i = 0; i < x_coOrdinates.size()-1; i++){
        sum += max(abs(x_coOrdinates[i + 1] - x_coOrdinates[i]), abs(y_coOrdinates[i + 1] - y_coOrdinates[i]));
    }

    return sum;
}

    int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> A = {0, 1, 1};
    vector<int> B = {0, 1, 2};

    auto S = new Solution();
    cout<<S->MinStepsInInfiniteGrid(A,B)<<"\n";

    return 0;
}