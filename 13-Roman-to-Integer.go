func romanToInt(s string) int {
    m := make(map[byte]int)
\tm['I'] = 1;
\tm['V'] = 5;
\tm['X'] = 10;
\tm['L'] = 50;
\tm['C'] = 100;
\tm['D'] = 500;
\tm['M'] = 1000;

\tvar last, sum int
\tfor i := 0; i < len(s); i++ {
\t\tnum := m[s[i]]

\t\tif last < num {
\t\t\tsum += ( num - ( 2 * last ) );
\t\t} else {
\t\t\tsum += num
\t\t}

\t\tlast = num;
\t}

\treturn sum
}