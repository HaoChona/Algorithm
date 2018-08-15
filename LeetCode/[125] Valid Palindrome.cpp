/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.39%)
 * Total Accepted:    232.3K
 * Total Submissions: 847.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.39%)
 * Total Accepted:    232.3K
 * Total Submissions: 847.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size())
            return true;
        string str="";
        int i,j;
        for(i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')
                str+=s[i];
            if(s[i]>='A' && s[i]<='Z')
                str+=tolower(s[i]);
            if(s[i]>='0' && s[i]<='9')
                str+=s[i];
        }
        i=0;j=str.size()-1;
        while(i < j){
            if(str[i]!=str[j])
                return false;
            else{
                i++;j--;
            }
        }
        return true;

    }
};
