func rangeSum(nums []int, n int, left int, right int) int {
	ans := make([]int, n * (n + 1) / 2)
	MOD := int(1e9 + 7)

	idx := 0
	for i := 0; i < n; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += ( nums[j] % MOD )
			sum %= MOD
			ans[idx] = sum
			idx++
		}
	}

	sort.Ints(ans)
	left--; right--

	res := 0
	for i := left; i <= right; i++ {
		res +=  ( ans[i] % MOD )
		res %= MOD
	}

	return res
}