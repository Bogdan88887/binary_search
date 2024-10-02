import random

def binary_search(arr, target):
    low = 0
    high = len(arr) - 1
    steps = 0

    while low <= high:
        steps += 1  # Увеличиваем счетчик на каждом шаге
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid, steps  # Возвращаем индекс и количество шагов
        elif arr[mid] < target:
            low = mid + 1  # Ищем в правой половине
        else:
            high = mid - 1  # Ищем в левой половине

    return -1, steps  # Элемент не найден, возвращаем количество шагов

# Генерация случайного массива
arr = sorted(random.sample(range(1, 101), 10))  # 10 случайных чисел от 1 до 100
print("Сгенерированный отсортированный массив:", arr)

# Запрос числа для поиска у пользователя
target = int(input("Введите число для поиска: "))

# Выполнение бинарного поиска
result, steps = binary_search(arr, target)

# Вывод результата
if result != -1:
    print(f"Элемент {target} найден на индексе: {result} за {steps} шагов.")
else:
    print(f"Элемент {target} не найден в массиве. Всего шагов: {steps}.")
