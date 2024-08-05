func rotate(nums []int, k int)  {
\tn := len(nums)
\tk %= n

\tpos := n - k
\tif pos == n {
\t\tpos = 0
\t}

\tans := make([]int, n)
\tidx := 0
\tfor i := pos; i < n; i++ {
\t\tans[idx] = nums[i]
\t\tidx++
\t}

\tfor i := 0; i < pos; i++ {
\t\tans[idx] = nums[i]
\t\tidx++
\t}

\tfor i := 0; i < n; i++ {
\t\tnums[i] = ans[i]
\t}
}