func clr(vis [][]bool, rows int, cols int) {
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			vis[i][j] = false
		}
	}
}

func dfs(i int, j int , dx []int, dy []int, vis [][]bool, grid [][]int, rows int, cols int) {
	vis[i][j] = true
	for idx := 0; idx < 4; idx++ {
		nx := i + dx[idx]
		ny := j + dy[idx]

		if nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1 && !vis[nx][ny]{
			dfs(nx, ny, dx, dy, vis, grid, rows, cols)
		}
	}
}

func minDays(grid [][]int) int {
    rows, cols := len(grid), len(grid[0])
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	vis := make([][]bool, rows)
	for i := 0; i < rows; i++ {
		vis[i] = make([]bool, cols)
	}

	clr(vis, rows, cols)
	cnt := 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if vis[i][j] == false && grid[i][j] == 1 {
				dfs(i, j, dx, dy, vis, grid, rows, cols)
				cnt++
			}
		}
	}

	if cnt > 1 || cnt == 0{
		return 0
	}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 1 {
				grid[i][j] = 0
				clr(vis, rows, cols)
				cnt = 0
				for ii := 0; ii < rows; ii++ {
					for jj := 0; jj < cols; jj++ {
						if vis[ii][jj] == false && grid[ii][jj] == 1 {
							dfs(ii, jj, dx, dy, vis, grid, rows, cols)
							cnt++
						}
					}
				}

				grid[i][j] = 1
				if cnt > 1 || cnt == 0{
					return 1
				}
			}
		}
	}

	return 2
}