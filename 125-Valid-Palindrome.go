func isPalindrome(s string) bool {
    ans := \\
    for i := 0; i < len(s); i++ {
\t\tif unicode.IsLetter(rune(s[i])) {
\t\t\tans += string(unicode.ToLower(rune(s[i])))
\t\t}

\t\tif unicode.IsDigit(rune(s[i])) {
\t\t\tans += string(s[i])
\t\t}
\t}

\tansRev := \\
\tfor i := len(ans) - 1; i >= 0; i-- {
\t\tansRev += string(ans[i])
\t}

\tfmt.Print(ansRev)
\tif ans == ansRev {
\t\treturn true
\t}

\treturn false
}