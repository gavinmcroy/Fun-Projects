package main

import (
	"fmt"
)

func main() {
	grades := [...]int{97, 85, 93}
	students := [...]string{"Lisa", "Ahmed", "Arnold"}
	students1 := []string{"Lisa", "Ahmed", "Arnold"} //slice instead of array
	i := 42
	//var myVariable string = "Hello everyone"
	fmt.Printf("%d %T \n", i, i)
	fmt.Println(grades)
	fmt.Println(students[1])

	var matrix [3][3]int
	matrix[0] = [3]int{1, 2, 3}
	matrix[1] = [3]int{1, 2, 3}
	matrix[2] = [3]int{1, 2, 3}
	//fmt.Println(matrix)

	//myArray := [...]int{1, 2, 3, 4, 5, 6, 7}
	//fmt.Println(myArray)
	var a []int
	a = append(a, 1)
	fmt.Println(len(a))
	fmt.Println(cap(a))

	fmt.Println(students1)
	myAwesomeStuff()

}

func myAwesomeStuff() {
	a := [...]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	b := a[:]   //slice all elements
	c := a[3:]  // slice from 4th element to end
	d := a[:6]  //slice first 6 elements
	e := a[3:6] //slice 4,5,6 elements
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
}
