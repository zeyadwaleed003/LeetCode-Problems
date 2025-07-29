func smallestSubarrays(nums []int) []int {
	n := len(nums)
	m, ans := make(map[int]int), make([]int, n)

	for i := range 30 {
		m[i] = 0
	}

	for i, r := n-1, n-1; i >= 0; i-- {
		for j := range 30 {
			if (nums[i] & (1 << j)) != 0 {
				m[j]++
			}
		}

        ok := false
        for j := range 30 {
            if m[j] > 0 {
                ok = true
            }
        }

		ready := true
		for ready && ok {
			for j := range 30 {
				if (nums[r]&(1<<j)) != 0 && m[j] == 1 {
					ready = false
				}
			}

			if ready == true {
				for j := range 30 {
					if (nums[r]&(1<<j)) != 0 && m[j] != 0 {
						m[j]--
					}
				}

				r--
			}
		}

        if ok == false {
            ans[i] = 1
        } else {
            ans[i] = r + 1 - i
        }
	}

	return ans
}