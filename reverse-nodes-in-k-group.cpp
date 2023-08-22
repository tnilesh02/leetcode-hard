/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* prev=head;
        ListNode* cur=head->next;
        if(!prev || !cur) {
            return head;
        }
        ListNode* temp;
        head->next=NULL;
        while(prev && cur){
            //cout<<prev->val<<endl;
            temp = cur->next;
            cur->next=prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int c = 0;
        ListNode* ret = head;
        ListNode* pr = NULL;
        ListNode* ne = NULL;
        ListNode* curr = head;
        ListNode* curhead = head;
        while(curr){
            c++;
            if(c == k){
                ne = curr->next;
                curr->next = NULL;
                ListNode* newHead = reverseList(curhead);
                if(!pr) {
                    ret = newHead;
                } else {
                    pr->next = newHead;
                }
                pr = curhead;
                curhead->next = ne;
                curr = curhead;
                curhead = ne;
                c = 0;
                // ListNode* temp = ret;
                // while(temp){cout<<temp->val<<" ";temp = temp->next;}
                // cout<<endl;
            }
            curr = curr->next;
        }
        return ret;
    }
};