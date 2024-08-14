func smallestDistancePair(nums []int, k int) int{
    n := len(nums)
    sort.Ints(nums)

    l, r := 0, nums[n - 1] - nums[0]
    ans := r
    var mid int

    for l <= r {
        mid = ( l + r ) / 2;
        L, R, small := 0, 1, 0

        for L < R && L < n - 1 {
            if( R == n ) {
                small += R - L - 1
                L++
                continue
            }

            if nums[R] - nums[L] <= mid {
                R++;
                continue
            }

            if nums[R] - nums[L] > mid {
                small += R - L - 1
                L++
                if L == R {
                    R++;
                }
            }
        }

        if small >= k {
            ans = mid;
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return ans
}