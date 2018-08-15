/*
 * [7] Reverse Integer
 *这题主要就是int 的边界处理
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.38%)
 * Total Accepted:    416.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 *
 */
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        int i=0,j=(int)str.size()-1,flag=0;
        if(str[0]=='-') { flag=1; i++; }
        while (i < j)
            swap(str[i++],str[j--]);
        if(flag) i=1;
        else i=0;
        while(str[i]=='0') i++;
        string tmp="";
        for(int l=i; l<(int)str.size(); l++)
            tmp+=str[l];
        int len = (int)tmp.size();
        int64_t sum=0;
        for(i=len-1,j=0; i>=0; i--){
            sum+=((tmp[i]-'0')*pow(10,j++));
        }
        if(flag){
            sum=sum*(-1);
            if(sum<(pow(-2,31))){
                return 0;
            }
        }
        if(sum>(pow(2,31)-1))
            return 0;
        else
            return (int)sum;
    }
};
