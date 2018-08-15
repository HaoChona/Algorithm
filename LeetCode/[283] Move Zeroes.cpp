/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (51.74%)
 * Total Accepted:    296K
 * Total Submissions: 572K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Note:
 *
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 *
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = (int)nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==0){
                for(int j=i;j<len;j++){
                    if(nums[j]!=0){
                        int t = nums[i];
                        nums[i]=nums[j];
                        nums[j]=t;
                        break;
                    }
                }
            }
        }
    }
};
