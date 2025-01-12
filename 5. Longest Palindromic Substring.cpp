5. Longest Palindromic Substring -: 

Given a string s, return the longest palindromic substring in s.

 

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
  
Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.



  

class Solution { // Top-Down Approach -: Recursion + Memoization -: 
public:

    int dp[1001][1001];

    bool solve(string& s, int i, int j){
        if(i>=j){ // Single char or empty string is a palindrome
            return true;  
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=solve(s, i+1, j-1);
        }else{
            return dp[i][j]=false; 
        }
    }

    string longestPalindrome(string s) {
        int n=s.size(); 

        int maxlen=INT_MIN;
        int startidx=0; // starting idx of the longest palindrome 
        
        // Initialize DP array to -1
        memset(dp, -1, sizeof(dp)); // memset/fill my DP by -1

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s, i, j)==true){
                    int currlen=j-i+1;
                    if(currlen>maxlen){
                        maxlen=currlen;
                        startidx=i;
                    }
                }
            }
        }
        // we have to return a string 
        return s.substr(startidx, maxlen);
    }
};



