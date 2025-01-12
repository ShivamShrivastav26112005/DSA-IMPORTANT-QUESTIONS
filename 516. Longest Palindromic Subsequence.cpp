516. Longest Palindromic Subsequence -: 

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting 
some or no elements without changing the order of the remaining elements.

 

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
  
Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.





class Solution { // DP Used -: 
public:

    int solve(string& s, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0; // idx out of bound 
        if(i==j) return 1; // string of 1 char -: length 1. 

        if(dp[i][j]!=-1){
            return dp[i][j]; 
        }

        // DP Logic -: 
        if(s[i]==s[j]){
            dp[i][j]=2+solve(s, i+1, j-1, dp); 
        }else{
            dp[i][j]=max(solve(s, i+1, j, dp), solve(s, i, j-1, dp)); 
        }

        return dp[i][j]; 
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        // Two Pointer -: 
        int i=0; 
        int j=n-1;
        // 2D DP Vector -: 
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(s, 0, n-1, dp); 
    }
};


