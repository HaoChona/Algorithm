/*
 * [8] String to Integer (atoi)
 * 此题的坑点在于 对于“+-8” 和 “       0000008884000”这样的字符串；
 *
 * 解题思路：
 *
 * 首先去处字符串首部的‘ ’ 空格字符
 *
 * 然后判断首字符是否为正负符号或者是数字符号 若不是则 return 0 反之继续执行
 *
 * 之后就是对‘+-8’这样的字符进行判断了 如果是 return 0 反之继续执行
 *
 * 记录数字是正数还是负数
 *
 * 去首部0操作
 *
 * rangh
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.11%)
 * Total Accepted:    235.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *
 *
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (231 − 1) or
 * INT_MIN (−231) is returned.
 *
 *
 * Example 1:
 *
 *
 * Input: "42"
 * Output: 42
 *
 *
 * Example 2:
 *
 *
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 *
 *
 * Example 3:
 *
 *
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 *
 *
 * Example 4:
 *
 *
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 *
 * Example 5:
 *
 *
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−231) is returned.
 *
 */
class Solution {
public:
    int myAtoi(string str) {
        int l = str.size(),i=0,j;
        int64_t sum=0;
        string s="";
        int flag=0;
        while(i < l){
            if(str[i]==' '){
                i++;
            }
            else{
                break;
            }
        }
        if((str[i]!='-' || str[i]!='+') && (str[i] <'0' && str[i]>'9'))
            return 0;
        if((str[i]=='+' || str[i]=='-') && (str[i+1]=='+' || str[i+1]=='-'))
                return 0;
        if(str[i]=='+'){
            flag=0;
            i++;
        }
        if(str[i]=='-'){
            flag=1;
            i++;
        }
        int t=0;
        for(int n=i; n<l; n++){
            while(t==0 && n < l){
                if(str[n]=='0')
                    n++;
                else
                    t=1;
            }
            if(str[n]>='0'&& str[n]<='9')
                s+=str[n];
            else
                break;
        }
        if(s.size() > 11){
            if(flag)
                return INT_MIN;
            else
                return INT_MAX;
        }
        l=s.size()-1;
        for(i=l,j=0; i>=0; i--){
            sum+=((s[i]-'0')*pow(10,j++));
        }
        if(flag)
            sum*=(-1);
        if(sum > INT_MAX)
            return INT_MAX;
        else if(sum < INT_MIN)
            return INT_MIN;
        else
            return sum;
    }
};
