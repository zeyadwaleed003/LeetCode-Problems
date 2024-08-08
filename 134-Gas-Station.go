func canCompleteCircuit(gas []int, cost []int) int {
    tot, now, ans, n := 0, 0, 0, len(gas)

    for i := 0; i < n; i++ {
        tot += gas[i] - cost[i]
        now += gas[i] - cost[i]

        if now < 0 {
            now = 0
            ans = i + 1
        }
    }

    if tot < 0 {
        return -1
    }

    return ans
}