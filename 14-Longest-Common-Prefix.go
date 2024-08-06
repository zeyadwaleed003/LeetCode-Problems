func longestCommonPrefix(strs []string) string {
\tans := \\
\t
\tfor idx := 0; idx < len(strs[0]); idx++ {
\t\tfor i := 0; i < len(strs); i++ {
\t\t\tif idx >= len(strs[i]) || strs[i][idx] != strs[0][idx] {
\t\t\t\treturn ans
\t\t\t}
\t\t}

\t\tans += string(strs[0][idx])
\t}

\treturn ans
}