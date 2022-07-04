#include <bits/stdc++.h>
using namespace std;

/*
Memoization :

int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // Base cases : if any of the string gets exhausted then we have to either delete of insert the remaining characters of the other string
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = 0 + solve(i - 1, j - 1, str1, str2, dp); // if the character matches then do nothing, thus adding 0 steps to the ans and then checking for the remaining parts of the strings
    else
    {
        int insert = 1 + solve(i, j - 1, str1, str2, dp);      // hypothetically inserting at the index prev to i to make the strings equal, so ans increases by 1
        int Delete = 1 + solve(i - 1, j, str1, str2, dp);      // deleting the character of the first string so its pointer moves ahead by 1 to check for the rest of the string 1 and also 1 step added to ans
        int replace = 1 + solve(i - 1, j - 1, str1, str2, dp); // replacing the character of the first string makes both the characters equal so both the pointers have to move ahead to check for the remaining part of the strings

        return dp[i][j] = min(insert, min(Delete, replace));
    }
}
int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, str1, str2, dp);
}
*/

/*
Tabulation :

int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = 0 + dp[i-1][j-1]; // if the character matches then do nothing, thus adding 0 steps to the ans and then checking for the remaining parts of the strings
    else{
        int insert = 1 + dp[i][j-1]; // hypothetically inserting at the index prev to i to make the strings equal, so ans increases by 1
        int Delete = 1 + dp[i-1][j]; // deleting the character of the first string so its pointer moves ahead by 1 to check for the rest of the string 1 and also 1 step added to ans
        int replace = 1 + dp[i-1][j-1]; // replacing the character of the first string makes both the characters equal so both the pointers have to move ahead to check for the remaining part of the strings

        dp[i][j] = min(insert, min(Delete, replace));
    }
        }

}
    return dp[n][m];
}
*/

/*
Space Optimization :

int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();

    vector<int> prev(m+1, 0);

    for(int j=0; j<=m; j++) prev[j] = j;

    for(int i=1; i<=n; i++){
        vector<int> curr(m+1, 0);
        curr[0] = i;
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]) curr[j] = 0 + prev[j-1]; // if the character matches then do nothing, thus adding 0 steps to the ans and then checking for the remaining parts of the strings
    else{
        int insert = 1 + curr[j-1]; // hypothetically inserting at the index prev to i to make the strings equal, so ans increases by 1
        int Delete = 1 + prev[j]; // deleting the character of the first string so its pointer moves ahead by 1 to check for the rest of the string 1 and also 1 step added to ans
        int replace = 1 + prev[j-1]; // replacing the character of the first string makes both the characters equal so both the pointers have to move ahead to check for the remaining part of the strings

        curr[j] = min(insert, min(Delete, replace));
    }

        }
        prev = curr;

}
    return prev[m];
}
*/

int main()
{
    std::ios_base::sync_with_stdio(false);

    return 0;
}