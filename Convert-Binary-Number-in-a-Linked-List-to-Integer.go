func getDecimalValue(head *ListNode) int {
	num, cur := []int {}, head

	for cur != nil {
		num = append(num, cur.Val);
		cur = cur.Next;
	}

	bNum := []int {}
	for i := len(num) - 1; i >= 0; i-- {
		bNum = append(bNum, num[i])
	}

	p, ans := 1, 0
	for _, val := range bNum {
		if val == 1 {
			ans += p;
		}
		
		p *= 2;
	}

	return ans;
}