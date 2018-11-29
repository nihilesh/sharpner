package main

import("fmt")

func add(a, b float64) float64{
	return a+b
}

func main() {
	var a, b float64 = 3.1, 2.4
	fmt.Println(add(a, b))
}
