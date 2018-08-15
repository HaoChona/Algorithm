/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.64%)
 * Total Accepted:    165.1K
 * Total Submissions: 490.1K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next)
			return true;
		//快慢指针判断中间节点slow每次前进一步，fast每次前进两步
		ListNode* slow=head,*fast=head;
		while(fast->next && fast->next->next){
			slow=slow->next;
			fast=fast->next->next;
		}

		fast = reverseList(slow->next);
		while(fast){
			if(head->val != fast->val)
				return false;
			head = head->next;
			fast = fast->next;
		}
		return true;
	}
	ListNode* reverseList(ListNode* head){
		ListNode* next,* pre=NULL;
		while(head){
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};
