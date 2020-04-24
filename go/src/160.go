func getIntersectionNode(headA, headB *ListNode) *ListNode {
    ptr1 := headA
    ptr2 := headB
    for ptr1 != ptr2{
        if ptr1 != nil{
            ptr1 = ptr1.Next
        }else{
            ptr1 = headB
        }
        
        if ptr2 != nil{
            ptr2 = ptr2.Next
        }else{
            ptr2 = headA
        }
    }
    
    return ptr1
    
}