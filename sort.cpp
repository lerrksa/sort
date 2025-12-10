#include <iostream>
#include "bibl .h"

//ГНОМЬЯ СОРТИРОВКА
void gnome_sort_asc(int* arr, int n) {//по возрастанию
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {//если текущий элемент больше или равен предыдущему, идем дальше
            index++;
        }
        else {//если текущий элемент меньше предыдущего, меняем их местами
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;//и отступаем на шаг назад
        }
    }
}
void gnome_sort_desc(int* arr, int n) {//по убыванию
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] <= arr[index - 1]) {//если текущий элемент меньше или равен предыдущему, идем дальше
            index++;
        }
        else {//если текущий элемент больше предыдущего, меняем их местами
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;//и отступаем на шаг назад
        }
    }
}

//СОРТИРОВКА ПРОСТЫМ ВЫБОРОМ
void selection_sort_asc(int* arr, int n) {//по возрастанию
    for (int i = 0; i < n - 1; i++) {//проходим по всем элементам массива, кроме последнего
        int min_index = i;//предполагаем, что мин. элемент находится на позиции i

        //ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;//нашли новый мин. элемент
            }
        }
        //если мин. элемент не на текущей позиции, меняем их местами
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
void selection_sort_desc(int* arr, int n) {//по убыванию
    for (int i = 0; i < n - 1; i++) {//проходим по всем элементам массива, кроме последнего
        int max_index = i;//предполагаем, что макс. элемент находится на позиции i

        //ищем максимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;//нашли новый макс. элемент
            }
        }
        //если макс. элемент не на текущей позиции, меняем их местами
        if (max_index != i) {
            int temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}

//СОРТИРОВКА ПАРНЫМ ОБМЕНОМ
void odd_even_sort_asc(int* arr, int n) {//по возрастанию
    bool is_sorted = false;

    while (!is_sorted) {
        is_sorted = true;

        //проходим по нечётным индексам
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {//сравниваем
                //обмен, если порядок нарушен
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                is_sorted = false;
            }
        }
        //проходим по чётным индексам
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {//сравниваем 
                //обмен, если порядок нарушен
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                is_sorted = false;
            }
        }
    }
}
void odd_even_sort_desc(int* arr, int n) {//по убыванию
    bool is_sorted = false;

    while (!is_sorted) {
        is_sorted = true;

            //проходим по нечётным индексам
            for (int i = 1; i < n - 1; i += 2) {
                if (arr[i] < arr[i + 1]) {//сравниваем
                    //обмен, если порядок нарушен(для убывания проверяем наоборот)
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    is_sorted = false;
                }
            }
        //проходим по чётным индексам
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] < arr[i + 1]) {//сравниваем
                //обмен, если порядок нарушен(для убывания проверяем наоборот)
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                is_sorted = false;
            }
        }
    }
}

//СОРТИРОВКА ШЕЛЛА
void shell_sort_asc(int* arr, int n) {//по возрастанию
    //начинаем с большого промежутка, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            //сохраняем текущий элемент
            int temp = arr[i];

            //сдвигаем ранее отсортированные элементы, пока не найдем правильное место для arr[i]
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            //вставляем сохраненный элемент в правильную позицию
            arr[j] = temp;
        }
    }
}
void shell_sort_desc(int* arr, int n) {//по убыванию
    //начинаем с большого промежутка, затем уменьшаем его
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            //сохраняем текущий элемент
            int temp = arr[i];

            //сдвигаем ранее отсортированные элементы, пока не найдем правильное место для arr[i]
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) { //(для убывания меняем условие)
                arr[j] = arr[j - gap];
            }
            //вставляем сохраненный элемент в правильную позицию
            arr[j] = temp;
        }
    }
}

//ПОРАЗРЯДНАЯ СОРТИРОВКА
void radix_sort_asc(int* arr, int n) {//по возрастанию
    if (n <= 1) return;
    //находим максимальное число
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) max_num = arr[i];
    }

    int* temp = new int[n];//создаем временный массив

    //сортируем по каждому разряду
    for (int digit_place = 1; max_num / digit_place > 0; digit_place *= 10) {
        int count[10] = { 0 };//счетчик цифр 0-9

        //считаем, сколько раз встречается каждая цифра
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / digit_place) % 10;
            count[digit]++;
        }
        //преобразуем счетчик в позиции
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        //строим временный массив
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / digit_place) % 10;
            temp[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        //копируем обратно
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
    delete[] temp;
}
void radix_sort_desc(int* arr, int n) {//по убыванию
    if (n <= 1) return;
    //находим максимальное число
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) max_num = arr[i];
    }

    int* temp = new int[n];//создаем временный массив

    //сортируем по каждому разряду
    for (int digit_place = 1; max_num / digit_place > 0; digit_place *= 10) {
        int count[10] = { 0 };//счетчик цифр 0-9

            //считаем, сколько раз встречается каждая цифра
            for (int i = 0; i < n; i++) {
                int digit = (arr[i] / digit_place) % 10;
                count[digit]++;
            }
        //для убывания: накапливаем справа налево
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
        //строим временный массив
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / digit_place) % 10;
            temp[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        //копируем обратно
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
    delete[] temp;
}

//БЫСТРАЯ СОРТИРОВКА
void quick_sort_asc(int* arr, int n) {//по возрастанию
    //если массив маленький, ничего не делаем
    if (n <= 1) return;

    //выбираем опорный элемент (последний)
    int pivot = arr[n - 1];

    //делим массив на три части:
    int left[1000];  //для чисел меньше pivot
    int middle[1000]; //для чисел равных pivot
    int right[1000]; //для чисел больше pivot

    int left_count = 0;
    int middle_count = 0;
    int right_count = 0;

    //распределяем числа по массивам
    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            left[left_count] = arr[i];
            left_count++;
        }
        else if (arr[i] == pivot) {
            middle[middle_count] = arr[i];
            middle_count++;
        }
        else {
            right[right_count] = arr[i];
            right_count++;
        }
    }

    //рекурсивно сортируем левую и правую части
    quick_sort_asc(left, left_count);
    quick_sort_asc(right, right_count);

    //собираем результат обратно в исходный массив
    int index = 0;

    //левые элементы (они уже отсортированы)
    for (int i = 0; i < left_count; i++) {
        arr[index] = left[i];
        index++;
    }
    //средние элементы (все равны pivot)
    for (int i = 0; i < middle_count; i++) {
        arr[index] = middle[i];
        index++;
    }
    //правые элементы (они уже отсортированы)
    for (int i = 0; i < right_count; i++) {
        arr[index] = right[i];
        index++;
    }
}
void quick_sort_desc(int* arr, int n) {//по убыванию
    //если массив маленький, ничего не делаем
    if (n <= 1) return;

    //выбираем опорный элемент (последний)
    int pivot = arr[n - 1];

    //делим массив на три части:
    int left[1000];  //для чисел БОЛЬШЕ pivot (для убывания)
    int middle[1000]; //для чисел равных pivot
    int right[1000]; //для чисел МЕНЬШЕ pivot (для убывания)

    int left_count = 0;
    int middle_count = 0;
    int right_count = 0;

    //распределяем числа по массивам
    for (int i = 0; i < n; i++) {
        if (arr[i] > pivot) { //для убывания: больше идет влево
            left[left_count] = arr[i];
            left_count++;
        }
        else if (arr[i] == pivot) {
            middle[middle_count] = arr[i];
            middle_count++;
        }
        else {  //для убывания: меньше идет вправо
            right[right_count] = arr[i];
            right_count++;
        }
    }

    //рекурсивно сортируем левую и правую части
    quick_sort_desc(left, left_count);
    quick_sort_desc(right, right_count);

    //собираем результат обратно в исходный массив
    int index = 0;

    //левые элементы (большие, уже отсортированы по убыванию)
    for (int i = 0; i < left_count; i++) {
        arr[index] = left[i];
        index++;
    }
    //средние элементы (все равны pivot)
    for (int i = 0; i < middle_count; i++) {
        arr[index] = middle[i];
        index++;
    }
    //правые элементы (меньшие, уже отсортированы по убыванию)
    for (int i = 0; i < right_count; i++) {
        arr[index] = right[i];
        index++;
    }
}