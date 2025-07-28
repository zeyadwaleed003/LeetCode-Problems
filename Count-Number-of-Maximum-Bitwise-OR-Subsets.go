func countMaxOrSubsets(nums []int) int {
	mx := 0
	for _, num := range nums {
		mx |= num
	}

	sz, ans := len(nums), 0
	for i := 0; i < (1 << sz); i++ {
		or := 0
		for j := range sz {
			if (i & (1 << j)) != 0 {
				or |= nums[j]
			}
		}

		if or == mx {
			ans++
		}
	}

	return ans
}