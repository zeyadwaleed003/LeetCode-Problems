func totalFruit(fruits []int) int {
	frq := make([]int, 100005)

	for i := range frq {
		frq[i] = 0
	}

	l, r, n, cnt := 0, 0, len(fruits), 0
	ans := 0
	for r < n {
		if frq[fruits[r]] == 0 {
			cnt++
			for cnt > 2 {
				frq[fruits[l]]--
				if frq[fruits[l]] == 0 {
					cnt--
				}
				l++
			}
		}

		frq[fruits[r]]++
		ans = max(ans, r-l+1)
		r++
	}

	return ans
}