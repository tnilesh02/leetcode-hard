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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(int i=0;i<lists.size();i++){
            while(lists[i]!=NULL){
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(v.size() == 0){
            return NULL;
        }
        sort(v.begin(), v.end());
        ListNode* head = new ListNode(v[0]);
        ListNode* ret = head;
        for(int i=1;i<v.size();i++){
            head->next = new ListNode(v[i]);
            head = head->next;
        }
        return ret;
    }
};