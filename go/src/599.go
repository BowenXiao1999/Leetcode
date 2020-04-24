func findRestaurant(list1 []string, list2 []string) []string {
    m1 := make(map[string]int)
    m2 := make(map[string]int)
    var ret []string
    var index int = -1
    for i, v := range list1{
        m1[v] = i
    }
    
    for i, v:= range list2 {
        m2[v] = i
    }
    
    for k, v := range m1{
        if in, ok:= m2[k]; ok{
            if in + v < index || index < 0{
                index = in + v
                ret = []string{k}
            }else if in + v == index{
                ret = append(ret, k)
            }
        }
    }
    return ret
}