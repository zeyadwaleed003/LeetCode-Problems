func maximumUniqueSubarray(nums []int) int {
	m, r, l, sum, mx := make(map[int]bool), 0, -1, 0, 0
	for r < len(nums) {
		if m[nums[r]] == true {
			for true {
				l++
				sum = sum - nums[l]
				if nums[l] == nums[r] {
					break
				}

				m[nums[l]] = false
			}
		}

		sum = sum + nums[r]
		m[nums[r]] = true
		r++
		mx = max(mx, sum)
	}

	return mx
}