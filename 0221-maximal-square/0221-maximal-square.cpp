class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int sz = 0;
        
        
        for (int i = 0; i <  matrix.size(); i++) {
            for (int j = 0; j <  matrix[0].size(); j++) {
                // if(matrix[i][j] == '1' && i && j) {
                //     dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                // }
                // sz = max(dp[i][j], sz);
                 if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                 sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};