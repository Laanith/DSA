#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371.

Note: Return "true" if it is an Armstrong number else return "false".


*/

/*NOTE - Instead of a 3-digit number, I here write code to be compatible for any length number in range of int */

class Solution
{
public:
    bool isArmstrong(int n)
    {
        int numDigits = static_cast<int>(std::log10(n)) + 1;
        int sum = 0, original = n;

        while (n > 0)
        {
            int digit = n % 10;
            int digitPower = 1;
            for (int i = 0; i < numDigits; ++i)
            {
                digitPower *= digit;
            }
            sum += digitPower;
            n /= 10;
        }

        return sum == original;
    }
};

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->isArmstrong(153)<<endl;
cout<<S->isArmstrong(121119208)<<endl;
 
return 0 ;
}