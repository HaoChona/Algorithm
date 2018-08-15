/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.19%)
 * Total Accepted:    277.3K
 * Total Submissions: 949.9K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.19%)
 * Total Accepted:    277.3K
 * Total Submissions: 949.9K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
class Solution {
private:
    int *createNext(string &needle){
        int *next=new int[needle.size()];
        int i=0,j=next[0]=-1;
        while(i < needle.size()-1){
            if(j==-1 || needle[i]==needle[j]){
                i++;j++;
                next[i]=(needle[i]==needle[j]?next[j]:j);
            }
            else{
                j=next[j];
            }
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int *next=createNext(needle);
        int i=0,j=0;
        int hlen=(int)haystack.size(),nlen=(int)needle.size();
        while(i<hlen&&j<nlen){
            if(j==-1 || haystack[i]==needle[j]){
                i++;j++;
            }
            else{
                j=next[j];
            }
        }
        delete[]next;
        if(j>=nlen)
            return i-j;
        else
            return -1;
    }
};
