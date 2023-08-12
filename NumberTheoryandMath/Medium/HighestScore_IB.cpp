#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
You are given a 2D string array A of dimensions N x 2,

where each row consists of two strings: first is the name of the student, second is their marks.

You have to find the maximum average mark. If it is a floating point, round it down to the nearest integer less than or equal to the number.
*/

class Solution{
public :
    int solve(vector<vector<string>> &A);
};

int Solution::solve(vector<vector<string>> &A){
    /*NOTE - This was my approach : To use a map that has a vector. Each time an string is found, its corresponding integer score is pushed into the vector. We calculate the average for each key in the map and return the maximum average*/
    map<string, vector<int>> m;
    for(auto vs : A){
        m[vs[0]].push_back(stoi(vs[1]));
    }

    int max_avg = INT_MIN;
    for(auto p : m){
        auto K = p.second;
        int sum = 0;
        for(auto x : K){
            sum +=x ;
        }
        sum /= K.size();
        max_avg = max(max_avg, sum);
    }

    return max_avg;
}

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        auto S = new Solution();
        vector<vector<string>> A = {{"Balu", "200"}, {"Balu", "10"}, {"Jacob", "40"}};
        cout << S->solve(A) << endl;
        return 0;
}