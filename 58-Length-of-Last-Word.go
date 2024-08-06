func lengthOfLastWord(s string) int {
    ans := 0
    start := len(s) - 1
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] != ' ' {
            break
        }

        start--
    }

    for i := start; i >= 0; i-- {
        if s[i] == ' ' {
            return ans
        }

        ans++
    }

    return ans
}