var dp [int(1e4 + 5)]int

func dpAmr7a7a(i int, nums[]int) int{
\tif i >= len(nums) - 1 {
\t\treturn 0
\t}

\tif dp[i] != -1 {
\t\treturn dp[i]
\t}

\tmn := int(1e15)
\tfor num := 1; num <= nums[i]; num++ {
\t\tmn = min(mn, dpAmr7a7a(i + num, nums) + 1)
\t}

\tdp[i] = mn
\treturn mn
}

func jump(nums []int) int{
\tfor i := 0; i < int(1e4 + 5); i++ {
\t\tdp[i] = -1;
\t}

\treturn dpAmr7a7a(0, nums)
}