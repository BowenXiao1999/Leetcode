// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* dummy = new ListNode(-1);
//         ListNode* current = dummy;
//         while(1){
//             int result =  INT_MAX;
//             int listNumber = -1;
//             for(int j = 0; j < lists.size() ; j++){
//                 if(lists[j] != nullptr){
//                     if(result > lists[j]->val){
//                         result = lists[j]->val;
//                         listNumber = j;
//                     }
//                 }
//             }
//             if(listNumber == -1)    break;
//             current->next = lists[listNumber];
//             current = current->next;
//             lists[listNumber] = lists[listNumber]->next;
//         }
//         current = dummy->next;
//         delete dummy;
//         return current;
//     }
// };


// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *dummy = new ListNode(0), *cur = dummy;
//         priority_queue<ListNode*, vector<ListNode*>, comapre> pq;
//         for (ListNode* l : lists) {
//             if (l) {
//                 pq.push(l);
//             }
//         }
//         while (!pq.empty()) {
//             ListNode* node = pq.top();
//             pq.pop();
//             cur -> next = node;
//             cur = cur -> next;
//             if (node -> next) {
//                 pq.push(node -> next);
//             }
//         }
//         return dummy -> next;
//     }
// private:
//     struct comapre {
//         bool operator()(ListNode* l, ListNode* r) {
//             return l -> val > r -> val;
//         }
//     };
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        for (int n = lists.size(); n > 1; n = (n + 1) / 2) {
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
            }
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = l1 ? l1 : l2;
        return dummy -> next;
    }
};