func maxProfit(prices []int) int{
    var cur_min = 0
    var max_profit int = 0
    if len(prices) == 0{
        return 0
    }
    
    cur_min = prices[0]
    for i, _ := range prices{
        if i == 0{ //切片???
            continue
        }
        now_profit := prices[i] - cur_min
        if now_profit > max_profit{
            max_profit = now_profit
        }
        
        if prices[i] < cur_min{
            cur_min = prices[i]
        }
    }
    
    return max_profit
}