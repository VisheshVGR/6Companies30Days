/*
Author: Vishesh Gupta
E mail: visheshguptavgr@gmail.com
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define newline ("\n")
#define F first
#define S second
#define PB emplace_back
#define POP pop_back
#define ll long long
#define deb(n) cerr << #n << " = " << (n) << '\n'
#define rep(i, j, n) for (int i = j; i < n; i++)
#define PI (3.141592653589)

#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define MOD 1000000007

int evalRPN(vector<string> &tokens)
{
    stack<int> ans;

    for (auto i : tokens)
    {
        if (!(i == "+" || i == "-" || i == "*" || i == "/"))
        {
            ans.push(stoi(i));
        }
        else
        {
            int num1 = ans.top();
            ans.pop();
            int num2 = ans.top();
            ans.pop();
            int num;
            if (i == "+")
            {
                num = num2 + num1;
            }
            else if (i == "-")
            {
                num = num2 - num1;
            }
            else if (i == "*")
            {
                num = num2 * num1;
            }
            else
            {
                num = num2 / num1;
            }
            ans.push(num);
        }
    }

    return ans.top();
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(1);
    // start coding here

    vector<string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(v);

    return 0;
}
