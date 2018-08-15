/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (60.55%)
 * Total Accepted:    251.8K
 * Total Submissions: 415.8K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 *
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 */
class Solution {
public:
    string reverseString(string s) {
    	int i=0,j=s.size()-1;
		while(i<j){
			swap(s[i++],s[j--]);
		}
		return s;
	}
};
