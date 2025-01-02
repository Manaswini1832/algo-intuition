#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length(), n2 = text2.length();

    //dp[i][j] = length of the longest common subseq formed from i characters(ie 0 to i-1 indices) of text1 and j chars of text2
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(text1[i-1] == text2[j-1]){ //if current chars(text1[i-1], text2[j-1] correspond to dp[i][j]) match, then we do lcs till prev chars + current match contributing length 1 to lcs
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                //otherwise, we could've formed lcs with i-1 chars from text1 & j from text2 OR with i chars from text1 and j-1 from text2 so take max of both
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    //To get the actual longest common subsequence, we just have to work backwards through the dp array
    //start at the bottom right and whenever we go diagonal, that means there was a common char between text1 & text2 so we included it in the longest comm susbseq so
        //append it to the result
    //otherwise from the above nested fors we see that we took the max of dp[i-1][j] & dp[i][j-1] so we see where dp[i][j] came from and teleport to that cell in the following code
    string result = "";

    int i = n1, j = n2;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]) {
            result += text1[i-1];
            i -= 1; j-= 1;
        }else{
            if(dp[i-1][j] == dp[i][j]) i -= 1;
            else j -= 1;
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string text1 = "abcdaf";
    string text2 = "acbcf";
    cout << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
