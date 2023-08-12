#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
 Given a column title A as appears in an Excel sheet, return its corresponding column number.
*/

class Solution{
public :
    int ColumnToNumber(string A);
};

int Solution::ColumnToNumber(string A){
    int sum = 0;
    for (char c: A) {
        sum = sum * 26 + (c - 'A' + 1);
    }
    return sum;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
string A = "ZA";
cout << S->ColumnToNumber(A);

return 0 ;
}