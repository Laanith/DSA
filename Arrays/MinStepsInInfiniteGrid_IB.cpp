#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
 
 
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