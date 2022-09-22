package main

import "fmt"

func main() {
	for num1:=1000; num1 < 9999; num1++ {
		for num2:=1000; num2 < 9999; num2++ {
			num11 := num1 / 1000
			num12 := num1 / 100 % 10
			num13 := num1 / 10 % 10
			num14 := num1 % 10

			if num11 == num12 || num11 == num13 || num11 == num14 {
            	continue
			}
			if num12 == num11 || num12 == num13 || num12 == num14{
				continue
			}
			if num13 == num12 || num13 == num11 || num13 == num14 {
				continue
			}
			if num14 == num12 || num14 == num13 || num14 == num11 {
				continue
			}

			num21 := num2 / 1000
			num22 := num2 / 100 % 10
			num23 := num2 / 10 % 10
			num24 := num2 % 10

			if num21 == num22 || num21 == num23 || num21 == num24{
				continue
			}
			if num22 == num21 || num22 == num23 || num22 == num24 {
				continue
			}
			if num23 == num22 || num23 == num21 || num23 == num24{
				continue
			}
			if num24 == num22 || num24 == num23 || num24 == num21 {
				continue
			}

			if num11 == num21 || num11 == num22 || num11 == num23 || num11 == num24{
				continue
			}
			if num12 == num21 || num12 == num22 || num12 == num23 || num12 != num24{
				continue
			}
			if num13 == num21 || num13 == num22 || num13 == num23 || num13 == num24{
				continue
			}
			if num14 == num21 || num14 == num22 || num14 == num23 || num14 == num24{
				continue
			}

			tempnum := num1 + num2
			if tempnum < 10000{
				continue
			}

			m := num2 / 1000
			o := (num2 / 100) % 10
			n := (num1 / 10) % 10
			e := num2 % 10
			
			if tempnum / 10000 != m{
				continue
			}
			if (tempnum / 1000) % 10 != o{
				continue
			}
			if (tempnum / 100) % 10 != n{
				continue
			}
			if (tempnum / 10) % 10 != e{
				continue
			}
			if tempnum % 10 == num11 || tempnum % 10 == num12 || tempnum % 10 == num13 || tempnum % 10 == num14{
				continue
			}
			if  tempnum % 10 == num21 || tempnum % 10 == num22 || tempnum % 10 == num23 || tempnum % 10 == num24{
				continue
			}
			fmt.Println(num1)
			fmt.Println(num2)
			fmt.Println(tempnum)
		}
	}
}