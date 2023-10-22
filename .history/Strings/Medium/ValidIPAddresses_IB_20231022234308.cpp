#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
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

/*!SECTION : Problem Description ::
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

bool isValidIP(string ip, int length)
{
    if (ip.size() != length + 3)
        return false;
    string curr = "";
    bool hasNonZero = false;
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            if (curr == "")
                return false;

            if (to_string(stoi(curr)).size() != curr.size())
                return false;

            curr = "";

            continue;
        }

        curr += ip[i];
    }

    if (curr == "")
        return false;

    if (to_string(stoi(curr)).size() != curr.size())
        return false;

    return true;
}



void GetPosIpAddress(vs & pos, string & orig, int currIndex, string temp, int step){
    if(step >= 4 && currIndex > orig.size())
        return;

    if(step==4 && currIndex == orig.size()){
        string ip = temp.substr(1);
        if(isValidIP(ip,  orig.size()))
            pos.push_back(ip);

        return;
    }

    string curr = "";
    for (int i = currIndex; i < min(currIndex + 3, int(orig.size())); i++){
        curr += orig[i];
        if(stoi(curr) < 256){
            GetPosIpAddress(pos, orig, i + 1, temp + '.', step + 1);
        }
    }
}

class Solution
{
public:
    vs restoreIPAddresses(string A);
};

vs Solution::restoreIPAddresses(string A){
    vs pos;
    GetPosIpAddress(pos, A, 0, "", 0);
    return pos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();

    return 0;
}