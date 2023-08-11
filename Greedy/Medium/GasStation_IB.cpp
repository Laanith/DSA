#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/* Sliding window problem , but with greedy approach */

/*!SECTION : Problem Description ::
 Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.
*/

class Solution{
public :
    int Solve(vi A, vi B);
};

int Solution::Solve(vi A, vi B){
    int sum = 0;
    for (int i = 0; i < A.size(); i++){
        sum += (A[i] - B[i]);
    }
    if(sum < 0)
        return -1;

    int index = INT_MAX;
    sum = 0;
    for (int i = 0; i < A.size(); i++){
        sum += (A[i] - B[i]);
        if(sum >= 0)
            index = min(index, i);
        if(sum < 0){
            index = INT_MAX;
            sum = 0;
        }
    }

    return index;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi A = {1, 2};
vi B = {2, 1};
cout<<S->Solve(A,B)<<endl;

return 0 ;
}