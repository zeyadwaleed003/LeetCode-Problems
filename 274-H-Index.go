func hIndex(citations []int) int {
\tsort.Ints(citations);

\tmn, n, ans := int(1e4), len(citations), 0
\tfor i := n - 1; i >= 0; i-- {
\t\tmn = min(mn, citations[i])
\t\tif ans + 1 <= mn {
\t\t\tans++
\t\t} else {
\t\t\tbreak
\t\t}
\t}

\treturn ans
}
