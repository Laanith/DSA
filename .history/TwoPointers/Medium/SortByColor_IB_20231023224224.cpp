#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
Given an array with N objects colored red, white, or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent red, white, and blue, respectively.

Note: Using the library sort function is not allowed.
*/

class Solution{
public :
    void sort(vi &A);
};
 
 void Solution::sort(vi & A){
    int n = A.size()-1;
    int s = 0;
    int mid = 0;
    int e = n;
    while(mid <= e){
        if(A[mid]==0){
            swap(A[s], A[mid]);
            s++;
            mid++;
        }
        else if(A[mid] == 1)
            mid++;
        else {
            swap(A[mid], A[e--]);
        }
    }


    
 }


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {0, 1, 1, 2, 1, 2, 1, 1, 0, 0, 2, 0, 1};

return 0 ;
}