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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int i=0;i<nums.size();i++)st.insert(nums[i]);

        ListNode* copy=head;
        while(copy!=NULL && st.find(copy->val)!=st.end())copy=copy->next;
        if(copy==NULL)return copy;
        ListNode* prev=copy;
        ListNode* nxt=prev->next;
        while(nxt!=NULL){
            if(st.find(nxt->val)!=st.end()){
                ListNode* temp=nxt->next;
                nxt->next=NULL;
                nxt=temp;
                prev->next=nxt;
            }
            else{
                prev=nxt;
                nxt=nxt->next;
            }
        }
        return copy;
    }
};