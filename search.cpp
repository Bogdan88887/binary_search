#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int steps = 0;

    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return steps;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr(100);
    std::iota(arr.begin(), arr.end(), 0);
    std::shuffle(arr.begin(), arr.end(), std::default_random_engine(std::random_device{}()));

    std::vector<int> randomNumbers(arr.begin(), arr.begin() + 10);
    std::sort(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Сгенерированный отсортированный массив: ";
    for (int num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int target;
    std::cout << "Введите число для поиска: ";
    std::cin >> target;

    int steps = binarySearch(randomNumbers, target);

    if (steps != -1) {
        std::cout << "Элемент " << target << " найден за " << steps << " шагов." << std::endl;
    } else {
        std::cout << "Элемент " << target << " не найден в массиве." << std::endl;
    }

    return 0;
}
