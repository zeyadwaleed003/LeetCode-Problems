func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Ints(players); sort.Ints(trainers);

	l, r, ans := 0, 0, 0
	for l < len(players) && r < len(trainers) {
		if players[l] <= trainers[r] {
			ans++; l++;
		}

		r++;
	}

	return ans
}