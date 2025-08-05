func numOfUnplacedFruits(fruits []int, baskets []int) int {
	n := len(baskets)
	vis := make([]bool, n)

	for i := range vis {
		vis[i] = false
	}

	for i := range fruits {
		for j := range baskets {
			if baskets[j] >= fruits[i] && vis[j] == false {
				vis[j] = true
				break
			}
		}
	}

	ans := 0
	for i := range vis {
		if vis[i] == false {
			ans++
		}
	}

	return ans
}