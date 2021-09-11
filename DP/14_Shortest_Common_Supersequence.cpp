/* (https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0)

Question:- Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

Approach:- 
As we know , to get shortest common supersequence we have to include a particular letter only once if it is present in both strings so to include the common letter once,
we have to subtract the longest common subsequence from the total length of both strings .

1. initialisation:- when any of the two strings is empty then empty subsequence will be common whose size will be zero.
2. Code:- If letters at particular index of the matrix is equal then will include that length of longest subsequence will be one greater than the length at one minus that
index else will not include that length and length will be the maximum of one less in the index.

using these steps we will get length of longest common subsequence and substracting it from total length of both strings we will get our shortest common supersequence length.

*/

#include <iostream>
#include <string>
using namespace std;

int shortestCommonSupersequence(string text1, string text2, int n, int m)
{
    vector<vector<int>> DP(2, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                DP[i % 2][j] = 1 + DP[(i - 1) % 2][j - 1];
            else
                DP[i % 2][j] = max(DP[(i - 1) % 2][j], DP[i % 2][j - 1]);
        }
    }

    return m + n - DP[n % 2][m];
}

int main()
{
    int t;
    string X, Y;
    cin >> t;

    while (t--)
    {
        cin >> X >> Y;
        cout << shortestCommonSupersequence(X, Y, X.size(), Y.size()) << "\n";
    }

    return 0;
}
