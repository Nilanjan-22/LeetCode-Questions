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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL)return {-1,-1};
        int firstCriticalPoint=-1, prevCriticalPoint=-1;
        int minDist=INT_MAX;
        int prevVal=head->val;
        ListNode* itr = head->next;
        int dis=1;
        while(itr->next!=NULL){
            int curVal = itr->val;
            int nextVal = itr->next->val;
            if((curVal>prevVal && curVal>nextVal) || (curVal<prevVal && curVal<nextVal)){
                if(firstCriticalPoint!=-1){
                    minDist = min(minDist,dis-prevCriticalPoint);
                }
                else{
                    firstCriticalPoint = dis;
                }
                prevCriticalPoint = dis;
            }
            prevVal=curVal;
            dis++;
            itr=itr->next;
        }
        if(minDist==INT_MAX)return {-1,-1};
        return {minDist, prevCriticalPoint-firstCriticalPoint};
    }
};