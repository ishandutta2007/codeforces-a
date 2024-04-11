package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader
var out *bufio.Writer

////////////////////////////////////////////////

func solve() {
	a := ReadInt()
	b := ReadInt()
	c := ReadInt()

	x := a - 1
	y := Abs(b-c) + c - 1

	if x < y {
		Println(1)
	} else if x == y {
		Println(3)
	} else {
		Println(2)
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := 1
	t = ReadInt()

	for i := 0; i < t; i++ {
		solve()
	}
}

func ReadInt() int {
	var x int
	fmt.Fscan(in, &x)
	return x
}

func ReadInts(n int) []int {
	a := make([]int, n)
	for i, _ := range a {
		a[i] = ReadInt()
	}
	return a
}

func Print(a ...any) {
	fmt.Fprint(out, a...)
}

func Println(a ...any) {
	fmt.Fprintln(out, a...)
}

type IntPair struct {
	x int
	y int
}

func Iota(a []int, start int) {
	for i := 0; i < len(a); i++ {
		a[i] = start
		start++
	}
}

func NextPermutation(a []int) bool {
	n := len(a)
	pos := n - 2
	for ; pos >= 0; pos-- {
		if a[pos] < a[pos+1] {
			break
		}
	}
	if pos == -1 {
		return false
	}
	for i := n - 1; i >= 0; i-- {
		if a[i] > a[pos] {
			a[i], a[pos] = a[pos], a[i]
			Reverse(a[pos+1 : n])
			break
		}
	}
	return true
}

func Reverse(a []int) {
	n := len(a)
	for i := 0; i < n/2; i++ {
		a[i], a[n-i-1] = a[n-i-1], a[i]
	}
}

func RemoveIf(a []int, cond func(int) bool) []int {
	n := len(a)
	pos := 0
	for i := 0; i < n; i++ {
		if !cond(a[i]) {
			a[pos] = a[i]
			pos++
		}
	}
	return a[0:pos]
}

func Min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func Max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func Abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}