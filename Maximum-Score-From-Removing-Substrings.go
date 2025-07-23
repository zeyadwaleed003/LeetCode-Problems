func maximumGain(s string, x int, y int) int {
	if x >= y {
		ans1, s1 := removeSub(s, "ab", x)
		ans2, _ := removeSub(s1, "ba", y)

		return ans1 + ans2
	} else {
		ans1, s1 := removeSub(s, "ba", y)
		ans2, _ := removeSub(s1, "ab", x)
		return ans1 + ans2
	}
}

func removeSub(s string, target string, val int) (int, string) {
	var stack []byte
	ans := 0

	for i := 0; i < len(s); i++ {
		if len(stack) > 0 && s[i] == target[1] && stack[len(stack)-1] == target[0] {
			stack = stack[:len(stack)-1]
			ans += val
		} else {
			stack = append(stack, s[i])
		}
	}

	return ans, string(stack)
}