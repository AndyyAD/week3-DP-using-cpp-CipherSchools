#include <bits/stdc++.h>
using namespace std;

// LPS

// string longestPalindrome(string s) {
//     if (s.length() <= 1) {
//         return s;
//     }
//     string result;
//     int len = s.length(), maxLen = 0;
//     vector<vector<int>> dp(len, vector<int>(len, 0));
//     for (int i = 0; i < len; i++) {
//         dp[i][i] = 1;
//         if (maxLen < dp[i][i]) {
//             maxLen = 1;
//             result = s.substr(i, i - i + 1);
//         }
//     }
//     int i, j;
//     for (int window = 2; window <= len; window++) {
//         for (int i = 0; i < len - window + 1; i++) {
//             j = i + window - 1;
//             if (window == 2) {
//                 if (s[i] == s[j]) {
//                     dp[i][j] = window;
//                     if (maxLen < window) {
//                         maxLen = window;
//                         result = s.substr(i, window);
//                     }
//                 }
//             } else {
//                 if (s[i] == s[j] && dp[i + 1][j - 1] > 0) {
//                     dp[i][j] = window;
//                     if (maxLen < window) {
//                         maxLen = window;
//                         result = s.substr(i, window);
//                     }
//                 }
//             }
//         }
//     }

//     return result;
// }

// LCS

// int longestCommonSubsequence(string text1, string text2) {
//     int l1 = text1.length(), l2 = text2.length();
//     if (l1 == 0 || l2 == 0) {
//         return 0;
//     }
//     vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
//     for (int i = 1; i <= l1; i++) {
//         for (int j = 1; j <= l2; j++) {
//             if (text1[i - 1] == text2[j - 1]) {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     return dp[l1][l2];
// }

// LIPL 

const int possibleMoves = 4;
const int xMoves[] = {1, -1, 0, 0};
const int yMoves[] = {0, 0, 1, -1};

bool isSafe(vector<vector<bool>> &visited, int r, int c, int row, int col) {
    return !(r < 0 || c < 0 || r >= row || c >= col || visited[r][c]);
}

int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y, const int row, const int col, int &maxCounter, vector<vector<int>> &dp) {
    if (dp[x][y] > 0) {
        return dp[x][y];
    }
    visited[x][y] = true;
    int nextX, nextY, maxResult = 1;
    for (int i = 0; i < possibleMoves; i++) {
        nextX = x + xMoves[i];
        nextY = y + yMoves[i];
        if (isSafe(visited, nextX, nextY, row, col) && matrix[nextX][nextY] > matrix[x][y]) {
            maxResult = max(maxResult, 1 + longestIncreasingPath(matrix, visited, nextX, nextY, row, col, maxCounter, dp));
        }
    }
    dp[x][y] = maxResult;
    visited[x][y] = false;
    maxCounter = max(maxCounter, maxResult);
    return maxResult;
}

int longestIncreasingPath(vector<vector<int>> &matrix){
    int row = matrix.size();
    if (row == 0) {
        return 0;
    }
    int col = matrix[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int maxCounter = 1;

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (dp[r][c] == 0)
                dp[r][c] = longestIncreasingPath(matrix, visited, r, c, row, col, maxCounter, dp);
        }
    }

    return maxCounter;
}

int main() {
    
    return 0;
}