type pair struct {
    first int
    second int
}

func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    grid := [int(1e3 + 5)][int(1e3 + 5)]byte{}
    for i := 0; i < int(1e3 + 5); i++ {
        for j := 0; j < int(1e3 + 5); j++ {
            grid[i][j] = '/'
        }
    }

    cell := pair{0, 0}
    i, n := 0, len(s)

    for {
        if cell.first == numRows {
            cell.first -= 2
            cell.second++

            for cell.first > -1 && i < n {
                grid[cell.first][cell.second] = s[i]
                cell.first--
                cell.second++
                i++
            }
        }

        if cell.first == -1 {
            cell.first += 2
        }

        if i >= n {
            break
        }

        grid[cell.first][cell.second] = s[i]
        cell.first++
        i++
    }

    var ans string
    for i := 0; i < int(1e3 + 5); i++ {
        for j := 0; j < int(1e3 + 5); j++ {
            if grid[i][j] != '/' {
                ans += string(grid[i][j])
            }
        }
    }

    return ans
}