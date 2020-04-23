func findMin(nums []int) int {
    n := len(nums)
    lo := 0
    hi := n - 1
    for lo < hi{
        mi := lo + (hi - lo)/2
        if nums[mi] < nums[n-1]{
            hi = mi
        }else{
            lo = mi+1
        }
    }
    
    return nums[lo]
}