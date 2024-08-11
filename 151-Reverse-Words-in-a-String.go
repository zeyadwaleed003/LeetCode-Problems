func reverseWords(s string) string {
    word, ans := \\, \\
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == ' ' {
            if len(word) == 0 {
                continue
            }

            if len(ans) > 0 {
                ans += string(\ \)
            }

            for j := len(word) - 1; j >= 0; j-- {
                ans += string(word[j])
            }
            word = \\

            continue
        }

        word += string(s[i])
    }

    if len(word) > 0 {
        if len(ans) > 0 {
            ans += string(\ \)
        } 

        for j := len(word) - 1; j >= 0; j-- {
            ans += string(word[j])
        }
    }

    return ans
}