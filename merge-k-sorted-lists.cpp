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
    ListNode* merge2(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* ret = new ListNode();
        ListNode* head = ret;
        int fl = 0;
        while(a && b){
            if(a->val <= b->val){
                if(!fl){
                    head->val = a->val;fl=1;
                } else {
                    head->next = new ListNode(a->val);
                    head = head->next;
                }
                a = a->next;
            } else {
                if(!fl){
                    head->val = b->val;
                    fl=1;
                } else {
                    head->next = new ListNode(b->val);
                    head = head->next;
                }
                b = b->next;
            }
        }
        if(a){
            head->next = a;
        } else {
            head->next = b;
        }
        return ret;
    }
    ListNode* mergeIt(vector<ListNode*>& lists,int st,int en){
        if(st == en){
            return lists[st];
        }
        if(st + 1 == en){
            return merge2(lists[st],lists[en]);
        }
        int mid = (st+en)/2;
        return merge2(mergeIt(lists,st,mid),mergeIt(lists,mid+1,en));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        return mergeIt(lists,0,lists.size()-1);
    }
};