/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.67%)
 * Total Accepted:    279.7K
 * Total Submissions: 883K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */
/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.67%)
 * Total Accepted:    279.7K
 * Total Submissions: 883K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty())
           return "";
       int len=(int)strs.size();
       string prefix=strs[0];
       string tmp="";
       for(int i=1; i<len; i++){
           tmp="";
           for(int j=0; j<prefix.size(); j++){
               if(prefix[j]==strs[i][j]){
                   tmp+=prefix[j];
               }
               else{
                   prefix=tmp;
                   tmp="";
                   break;
               }
           }
       }
       return prefix;
    }
};
