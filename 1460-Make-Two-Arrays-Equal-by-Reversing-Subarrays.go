func canBeEqual(target []int, arr []int) bool{
    frqTar := [1001]int{}
	frqArr := [1001]int{}

	for i:= 0; i < len(arr); i++{
		frqTar[target[i]]++
        frqArr[arr[i]]++
	}

	for i := 0; i < len(arr); i++{
		if frqTar[arr[i]] != frqArr[arr[i]]{ 
            return false
        }
	} 

	return true
}