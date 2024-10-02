package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func binarySearch(arr []int, target int) (int, int) {
	low := 0
	high := len(arr) - 1
	steps := 0

	for low <= high {
		steps++
		mid := (low + high) / 2

		if arr[mid] == target {
			return mid, steps
		} else if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1, steps
}

func main() {
	rand.Seed(time.Now().UnixNano())
	arr := rand.Perm(100)[:10]
	sort.Ints(arr)

	fmt.Println("Сгенерированный отсортированный массив:", arr)

	var target int
	fmt.Print("Введите число для поиска: ")
	fmt.Scan(&target)

	result, steps := binarySearch(arr, target)

	if result != -1 {
		fmt.Printf("Элемент %d найден на индексе: %d за %d шагов.\n", target, result, steps)
	} else {
		fmt.Printf("Элемент %d не найден в массиве. Всего шагов: %d.\n", target, steps)
	}
}
