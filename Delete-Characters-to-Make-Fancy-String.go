func makeFancyString(s string) string {
    var ans strings.Builder
	last, sz := []rune{}, 0
	for _, c := range s {
		last = append(last, c)
		sz = len(last)
		if sz >= 3 {
			if last[sz-1] == last[sz-2] && last[sz-2] == last[sz-3] {
				continue
			}
		}

		ans.WriteRune(c)
	}

	return ans.String()
}