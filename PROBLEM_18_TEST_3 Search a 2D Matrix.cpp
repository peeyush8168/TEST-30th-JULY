/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()||matrix[0].empty()) {
            return false;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=m*n-1;
        while (left<=right) {
            int mid=left+(right-left)/2;
            int midValue=matrix[mid/n][mid%n];
            if (midValue==target) {
                return true;
            } else if (midValue<target) {
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        return false;
    }
};
