/*
 * [242] Valid Anagram
 * 另一种更快的方法是定义一个数组大小为26，以s t的每个字符值-‘a'为索引，对其进行++ -- 操作 若数组中每一个值都为了则true fanz
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (47.82%)
 * Total Accepted:    218.3K
 * Total Submissions: 456.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        else
            return false;
    }
};
