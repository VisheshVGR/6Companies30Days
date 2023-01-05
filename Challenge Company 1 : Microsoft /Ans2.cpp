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

void helper(int start, int k, int n, int currSum, vector<int> &temp, vector<vector<int>> &ans)
{
    if (k == 0)
    {
        if (currSum == n)
        {
            ans.push_back(temp);
        }
        return;
    }

    for (int i = start + 1; i < 10; i++)
    {
        temp.push_back(i);
        helper(i, k - 1, n, currSum + i, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, k, n, 0, temp, ans);

    return ans;
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

    int k = 3, n = 9;
    vector<vector<int>> ans = combinationSum3(k, n);
    for (auto i : ans)
    {
        for (auto it : i)
        {
            cout << it << ' ';
        }
        cout << endl;
    }

    return 0;
}
