/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.84%)
 * Total Accepted:    248.9K
 * Total Submissions: 624.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 *
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = (int)digits.size()-1;
        int tmp=(digits[len]+1)/10;
        digits[len] = (digits[len]+1)%10;
        while(tmp){
            if(len==0 && tmp==1){
                digits.insert(digits.begin(),1);
                break;
            }
            len--;
            int t = digits[len]+tmp;
            tmp = (int)t/10;
            digits[len] = t%10;
        }
            return digits;
    }
};
