// В одномерном массиве, состоящем из п вещественных элементов, вычислить:
// 1)  максимальный по модулю элемент массива;
// 2)  сумму элементов массива, расположенных между первым и вторым положительными элементами.
//Преобразовать массив таким образом, чтобы элементы, равные нулю, располага¬лись после всех остальных.

 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 5

 

void swap(int* a, int* b) { // меняет местами элементы
int tmp = *a;
*a = *b;
*b = tmp;
}
void print(int* box, int size) { //вывод массива
int i;
for (i = 0; i < size; ++i) printf("%i ", box[i]);
puts("");
}
void shift(int* beg, int* end) {
while (beg + 1 != end) {
swap(beg, beg + 1);
++beg;
}
}
void stable_partition(int* box, int size) {
int i;
int* end = box + size;
int* last = end - 1;
int stop = size;
for (i = 0; i < stop; ++i) {
while (0 == box[i]) {
shift(&box[i], end);
last = 0;
if (!--stop) break;
}
}
}

 

int main()
{
    int i,j, b;
    int iMax=0, iMin=0;
    int numMaxFirst, count=0, summ=0;

 

    int arr[n];
    
    for(i = 0; i < n; i++)
    { // вводим элементы с клавиатуры
        printf("input element %d: ", i + 1);   scanf("%d", &arr[i]);   
 
        if(arr[i]>0)
        { // если элемент больше положительный запоминаем его для сравнения      
            numMaxFirst=i;// и запоминаем его позицию
        }
    }

 

     for (i = 0; i < n; i++)
    {
     if (abs(arr[i]) > abs(arr[iMax])) {iMax = i; } 
    }
    printf("\nMax element == %d\n", arr[iMax]); //вывод в терминал самого большого по модулю элемента
 
    // ищем первый положительный
    for(i = 0; i < n; i++)
    { 
        if(arr[i]>0)
        { // если элемент больше положительный запоминаем его для сравнения      
            numMaxFirst=i;// и запоминаем его позицию
            break;
        }
    }
 
    // ищем второй положительный элемент
    for(i = 0; i<n; ++i)
    {
        if(arr[i]>0 && i!=numMaxFirst) // нашли положительный элемент
        {
           for(j = numMaxFirst+1; j < i; j++) { //складываем все элементы, которые находятся между 1 и вторым положительным элементом.
            summ+=arr[j];
            }
            printf("\nsumm between positive element: %d \n", summ);
            break;
        }
 
    }

 


int size = sizeof(arr) / sizeof(arr[0]);
print(arr, size);
stable_partition(arr, size);
print(arr, size);
system("pause > nul");
return 0;
}