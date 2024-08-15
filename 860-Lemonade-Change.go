func lemonadeChange(bills []int) bool {
    sum5, sum10 := 0, 0
    for _, value := range bills {
        if value == 10 {
            if sum5 > 0 {
                sum5--
                sum10++
            } else {
                return false;
            }
        } else if value == 20 {
            if sum5 > 0 && sum10 > 0 {
                sum5--
                sum10--
            } else if sum5 > 2{
               sum5 -= 3
            } else {
                return false;
            }
        } else {
            sum5++
        }
    }

    return true
}