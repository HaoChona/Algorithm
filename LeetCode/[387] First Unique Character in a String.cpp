/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.29%)
 * Total Accepted:    128.1K
 * Total Submissions: 270.9K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int> res;
        int len=s.size();
        for(int i=0; i<len; i++){
            res[s[i]]++;
        }
        int flag = -1;
        for(int i=0; i<len; i++){
            if(res[s[i]]==1){
                flag=i;
                break;
            }
        }
        return flag;

    }
};
