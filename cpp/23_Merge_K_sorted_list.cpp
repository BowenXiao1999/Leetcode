//
// Created by bowen on 2020/9/19.
//
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while(1){
            int result =  INT_MAX;
            int listNumber = -1;
            for(int j = 0; j < lists.size() ; j++){
                if(lists[j] != nullptr){
                    if(result > lists[j]->val){
                        result = lists[j]->val;
                        listNumber = j;
                    }
                }
            }
            if(listNumber == -1)    break;
            current->next = lists[listNumber];
            current = current->next;
            lists[listNumber] = lists[listNumber]->next;
        }
        current = dummy->next;
        delete dummy;
        return current;
    }
};
