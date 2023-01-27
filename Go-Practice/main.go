package main

import (
	"fmt"
)

func main() {
	i := 42
	x := 42.9999
	var y complex64 = 2 + 1i
	var test int = int(x)
	var myVariable string = "Hello everyone"
	fmt.Printf("%d %T \n", i, i)
	fmt.Println(myVariable)
	fmt.Println(test)
	fmt.Println(y)

}
