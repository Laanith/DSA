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

/*!SECTION : EXPLANATION BY CHATGPT AS I DID NOT UNDERSTAND THE RECURSION GIVEN IN THE SOLUTION

The recursive function `GetPosIpAddress` in the provided code is designed to generate all possible valid IP addresses by recursively exploring combinations of segments from the input string `A`. Here's a step-by-step explanation of how it works:

1. **Function Parameters**:
   - `pos`: This is a reference to a vector that will store the generated valid IP addresses.
   - `orig`: This is the original input string, which is used to extract IP segments.
   - `currIndex`: It represents the current index in the `orig` string.
   - `temp`: This is a temporary string that accumulates segments of the IP address as the function progresses.
   - `step`: It keeps track of how many segments have been collected so far.

2. **Base Cases**:
   - If `step` is equal to 4 (indicating that four segments have been collected) and `currIndex` is not equal to the length of the `orig` string, the function returns, effectively terminating this branch of recursion.
   - If `currIndex` is equal to the length of the `orig` string and `step` is equal to 4, it means that four segments have been collected, and the function checks if the accumulated IP address in `temp` is valid. If it's a valid IP address, it adds it to the `pos` vector.

3. **Recursive Exploration**:
   - The function iterates from `currIndex` to a maximum of `currIndex + 3` or the end of the `orig` string (whichever comes first) to consider all possible segment combinations.
   - It accumulates characters from `orig` into the `curr` string and checks if the integer value of `curr` is less than 256 (to ensure it's a valid IP segment).
   - If the condition is met, it recursively calls itself with the updated parameters:
     - `currIndex` is updated to `i + 1`, indicating that the next segment will start from the next character.
     - `temp` is updated with the accumulated segment separated by a dot.
     - `step` is incremented by 1.

By recursively exploring different segment combinations and validating them, this function generates all possible valid IP addresses for the given input string `A`. The valid IP addresses are stored in the `pos` vector, which is returned as the result of the `restoreIpAddresses` function.
*/

class Solution
{
public:
    vs restoreIpAddresses(string A);
};

bool isValidIp(string ip, int length)
{

    if (ip.size() != length + 3)
        return false;
    string curr = "";
    bool hasnonZero = false;
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

void GetPosIpAddress(vector<string> &pos, string &orig, int currIndex, string temp, int step)
{

    if (step >= 4 && currIndex != orig.size())
    {

        return;
    }

    if (currIndex == orig.size() && step == 4)
    {

        string ip = temp.substr(1);

        if (isValidIp(ip, orig.size()))
        {

            pos.push_back(ip);
        }

        return;
    }

    string curr = "";

    for (int i = currIndex; i < min(currIndex + 3, (int)(orig.size())); i++)
    {

        curr += orig[i];

        if (stoi(curr) < 256)
        {

            GetPosIpAddress(pos, orig, i + 1, temp + '.' + curr, step + 1);
        }
    }
}

vector<string> Solution::restoreIpAddresses(string A)
{

    vector<string> pos;

    GetPosIpAddress(pos, A, 0, "", 0);

    return pos;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    for (auto str : S->restoreIpAddresses( "1285511135"))
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}