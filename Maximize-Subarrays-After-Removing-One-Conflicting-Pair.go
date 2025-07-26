func maxSubarrays(n int, conflictingPairs [][]int) int64 {
    b1 := make([]int, n+1)
    b2 := make([]int, n+1)

    for i := 0; i <= n; i++ {
        b1[i] = math.MaxInt32
        b2[i] = math.MaxInt32
    }

    for _, pair := range conflictingPairs {
        a := min(pair[0], pair[1])
        b := max(pair[0], pair[1])

        if b1[a] > b {
            b2[a] = b1[a]
            b1[a] = b
        } else if b2[a] > b {
            b2[a] = b
        }
    }
    res, ib1, ib2 := int64(0), n, math.MaxInt32
    delCount := make([]int64, n+1)
    for i := n; i >= 1; i-- {
        if b1[ib1] > b1[i] {
            ib2 = min(ib2, b1[ib1])
            ib1 = i
        } else {
            ib2 = min(ib2, b1[i])
        }
        res += int64(min(b1[ib1], n+1) - i)
        delCount[ib1] += int64(min(min(ib2, b2[ib1]), n+1) - min(b1[ib1], n+1))
    }
    maxVal := int64(0)
    for _, v := range delCount {
        maxVal = max(maxVal, v)
    }
    return res + maxVal
}