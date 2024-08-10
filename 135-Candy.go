func candy(ratings []int) int {
    n := len(ratings)
    if n == 1 {
        return 1
    }

    num := make([]int, n)
    for i := 0; i < n; i++ {
        num[i] = 1
    }

    for i := 1; i < n; i++ {
        if ratings[i] > ratings[i - 1] {
            num[i] = num[i - 1] + 1
        }
    }

    for i := n - 2; i >= 0; i-- {
        if ratings[i] > ratings[i + 1] {
            num[i] = max(num[i], num[i + 1] + 1)
        }
    }

    sum := 0
    for i := 0; i < n; i++ {
        sum += num[i]
    }

    return sum
}