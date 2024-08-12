func isSubsequence(s string, t string) bool {
    i, j, ok := 0, 0, false
    for {
        if( i >= len(s) ) {
            ok = true
            break
        }

        if j >= len(t) {
            break
        }

        if s[i] == t[j] {
            i++
        }
        j++
    }
    
    return ok
}