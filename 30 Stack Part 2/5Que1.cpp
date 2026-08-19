// Given the head of a singly linked list, return true if it is a palindrome 
// or false otherwise. Use a stack to solve this problem. For example, if
// the input is head = [1,2,2,1], the output should be true. If the input
// is head = [1,2,3], the output should be false.(leetcode)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;

        ListNode* curr = head;

        while(curr != NULL){
            st.push(curr->val);
            curr = curr -> next;
        } 
        curr = head;
        while(curr != NULL){
            if(curr->val != st.top()){
                return false;
            }
            curr = curr->next;
            st.pop();
        }
        return true;
    }
};
