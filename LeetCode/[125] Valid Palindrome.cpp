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
/*
 //method tow
class Solution {
public:
    bool isalpha(char ch)
    {
        return (('0'<=ch&&ch<='9')||('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')) ? true : false;
    }
    bool isequal(char lch, char rch)
    {
        if('A'<=lch&&lch<='Z')
            lch=lch+32;
        if('A'<=rch&&rch<='Z')
            rch=rch+32;
        
        return (lch==rch) ? true : false;
    }
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            while(l<r&& !isalpha(s[l]))
                l++;
            while(l<r&& !isalpha(s[r]))
                r--;
            if(!isequal(s[l],s[r]))
                return false;
            
            l++;
            r--;
        }
        return true;
    }
};
*/
