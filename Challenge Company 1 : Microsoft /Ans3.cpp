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

string getHint(string secret, string guess)
{
    unordered_map<char, int> secret_map, guess_map;

    for (auto i : secret)
        secret_map[i]++;

    for (auto i : guess)
        guess_map[i]++;

    int x = 0, y = 0;

    for (int i = 0; i < (int)secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            x++;
            secret_map[secret[i]]--;
            guess_map[secret[i]]--;
        }
    }

    for (auto it = secret_map.begin(); it != secret_map.end();)
    {
        if (it->second == 0)
        {
            it++;
            continue;
        }

        if (guess_map[it->first] != 0)
        {
            secret_map[it->first]--;
            guess_map[it->first]--;
            y++;
        }
        else
        {
            it++;
        }
    }

    string ans = to_string(x) + "A" + to_string(y) + "B";

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

    string secret = "1123", guess = "0111";

    cout << getHint(secret, guess);

    return 0;
}
