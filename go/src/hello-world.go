package main

import "fmt"

func main() {
	fmt.Println( "Hello World" )
	describe(1, "one")
	//describe("one", 1)
}

func describe(i int, j string) {
	fmt.Println(i, j)
}

