func isValid(word string) bool {
    if len(word) < 3 {
		return false
	}

	vowels, hasVowel:= []rune {'a', 'e', 'i', 'o', 'u'}, false
	consonants, hasConson := []rune {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}, false

	for _, e := range word {
		vowel, conson, digit := false, false, false
		el := strings.ToLower(string(e))

		for _, v := range vowels {
			if el == string(v) {
				vowel = true
				hasVowel = true
			}
		}

		for _, c := range consonants {
			if el == string(c) {
				conson = true
				hasConson = true
			}
		}


		for i := 0; i <= 9; i++ {
			if el == strconv.Itoa(i) {
				digit = true
			}
		}

		if !digit && !conson && !vowel {
			return false
		}
	}
	
	return hasConson && hasVowel
}