func maximumLength(nums []int) int {
	evens, odds := 0, 0;
	for i, val := range(nums) {
		nums[i] = val % 2;
		if nums[i] == 0 {
			evens++;
		} else {
			odds++;
		}
	}

	mx, last, sum := max(evens, odds), nums[0], 1;
	for i := 1; i < len(nums); i++ {
		if nums[i] != last {
			sum++;
			last = 1 - last;
		}
	}

	return max(mx, sum)
}