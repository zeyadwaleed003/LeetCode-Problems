func removeSubfolders(folder []string) []string {
	sort.Strings(folder)

	folders := [][]string{}
	for _, f := range folder {
		folders = append(folders, strings.Split(f, "/"))
	}

	m := map[string]bool{}
	take := make([]bool, len(folder))

	for i := range take {
		take[i] = true
	}

	for i, f := range folders {
		path := ""
		for j := 1; j < len(f); j++ {
			path = path + fmt.Sprint("/", f[j])
			if m[path] == true {
				take[i] = false
				break
			}
		}
		m[path] = true
	}

	ans := []string{}
	for i, f := range folder {
		if take[i] == true {
			ans = append(ans, f)
		}
	}

	return ans
}