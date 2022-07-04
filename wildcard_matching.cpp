#include <bits/stdc++.h>
using namespace std;

/*
Memoization :

#include<bits/stdc++.h>
bool solve(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){

    if(i<0 &&  j<0) return true;
    if(j>=0 && i<0) return false;
    if(i>=0 && j<0){
        for(int k=0; k<=i; k++) if(pattern[k] != '*') return false;
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = solve(i-1, j-1, pattern, text, dp);
    if(pattern[i] == '*') return dp[i][j] = (solve(i-1, j, pattern, text, dp) | solve(i, j-1, pattern, text, dp));
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));

   return solve(n-1, m-1, pattern, text, dp);
}
*/

/*
Tabulation :

#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = 1;
    for(int j=1; j<=m; j++) dp[0][j] = 0;
    for(int i=1; i<=n; i++){
        bool fl = true;
        dp[i][0] = 1;
        for(int k=1; k<=i; k++) if(pattern[k-1] != '*'){
            dp[i][0] = 0;
            fl = false;
            break;
        }
        if(!fl) break;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
             if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
            else
        {if(pattern[i-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
         else
            dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
*/

/*
Space Optimization :

#include<bits/stdc++.h>
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<int> prev(m+1, 0);

    prev[0] = 1;
    for(int j=1; j<=m; j++) prev[j] = 0;

    for(int i=1; i<=n; i++){
        vector<int> curr(m+1, 0);
        bool fl = true;
        curr[0] = 1;
        for(int k=1; k<=i; k++) if(pattern[k-1] != '*'){
            curr[0] = 0;
            fl = false;
            break;
        }
        for(int j=1; j<=m; j++){
             if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') curr[j] = prev[j-1];
            else
        {if(pattern[i-1] == '*') curr[j] = prev[j] | curr[j-1];
         else
            curr[j] = false;
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