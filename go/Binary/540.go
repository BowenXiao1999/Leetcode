
func singleNonDuplicate(nums []int) int {
    lo := 0
    hi := len(nums)-1
    if hi == 0{
        return nums[0]
    }
    for lo < hi - 1{
        m := lo + (hi - lo)/2
        if m % 2 == 1{
            m--
        }
        if nums[m] != nums[m+1]{
            hi = m
        }else{
            lo = m+2
        }
    }
    
    return nums[hi]
}