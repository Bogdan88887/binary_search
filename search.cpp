#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

std::pair<int, int> binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int steps = 0;

    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return {mid, steps}; // Возвращаем индекс и количество шагов
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return {-1, steps}; // Если не найдено, возвращаем -1 и количество шагов
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

    auto [index, steps] = binarySearch(randomNumbers, target);

    if (index != -1) {
        std::cout << "Элемент " << target << " найден на индексе " << index 
                  << " за " << steps << " шагов." << std::endl;
    } else {
        std::cout << "Элемент " << target << " не найден в массиве. Всего шагов: " << steps << "." << std::endl;
    }

    return 0;
}
