#include <iostream>
#include <stdio.h>
using namespace std;
 
unsigned string_len(char* str) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

int deletePunctuation(char* arr, char znak, char* newarr) {
    int count = 0;
    int index = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == znak) {
            count++;
            if (count <= 1) {
                newarr[index] = arr[i];
                index++;
            }
        }
        else {
            newarr[index] = arr[i];
            index++;
            count = 0;
        }
        newarr[index] = '\0';
    }
    return 1;
}

int deleteTochka(char* arr, char znak, char* newarr, int new_len) {
    int count = 0;
    int index = 0;
    for (int i = 0; i < new_len; i++) {
        if (arr[i] == znak) {
            count++;
            if (count <= 3) {
                newarr[index] = arr[i];
                index++;
            }
        }
        else {
            newarr[index] = arr[i];
            index++;
            count = 0;
        }
        newarr[index + 1] = '\0';
    }
    return 1;
}

int BookvaMal(char* arr, int newlength) {
    const int bookva = 32;
    if (arr[0] >= 97 and arr[0] <= 122)
        arr[0] -= bookva;
    for (int i = 1; i < newlength - 2; i++) {
        if (arr[i] == ' ' and arr[i - 1] == '.' and arr[i + 1] >= 97 and arr[i + 1] <= 122) {
            arr[i + 1] -= bookva;
        }
        if (arr[i] == ' ' and arr[i - 1] != '.' and arr[i + 1] >= 65 and arr[i + 1] <= 90) {
            arr[i + 1] += bookva;
        }
        if (arr[i] != ' ' and (arr[i - 2] != '.' and arr[i - 1] != '.') and arr[i] >= 65 and arr[i] <= 90)
            arr[i] += bookva;
    }
    return 1;
}
int Number(char* arr, char* newarr, int newlength) {
    int index = 0;
    for (int i = 0; i < newlength; i++) {
        if (arr[i] < 48 or arr[i]>57) {
            newarr[index] = arr[i];
            index++;
        }
        newarr[index + 1] = '\0';
    }
    return 1;
}

int Number2(char* arr, char* podstroka, char* newarr) {
    int len1 = string_len(arr);
    int len2 = string_len(podstroka);
    int count = 0;
    int index = 0;
    for (int i = 0; i <= len1; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (arr[i + j] != podstroka[j])
                break;
        }
        if (j != len2) {
            newarr[index] = arr[i];
            index++;
        }
        else {
            i = i + len2 - 1;
        }
        newarr[index + 1] = '\0';
    }
    return 1;
}

int linearSearch(char* arr, char* podstroka) {
    int length1 = string_len(arr);
    int length2 = string_len(podstroka);
    int count = 0;
    for (int i = 0; i <= length1 - length2; i++) {
        int j;
        for (j = 0; j < length2; j++) {
            if (arr[i + j] != podstroka[j])
                break;
        }
        if (j == length2)
            count++;
    }
    return count;
}

int main() {
    setlocale(0, "");
    int const len = 100;
    char stroka[len];
    char newstroka[len];
    int newlength;
    cout << "Введите вашу строку: " << endl;
    cin.getline(stroka, len);
    cin.sync();
    char Znak1[len];
    deletePunctuation(stroka, ' ', Znak1);
    char Znak2[len];
    deletePunctuation(Znak1, ',', Znak2);
    char Znak3[len];
    deletePunctuation(Znak2, '!', Znak3);
    char Znak4[len];
    deletePunctuation(Znak3, '?', Znak4);
    char Znak5[len];
    deletePunctuation(Znak4, '/', Znak5);
    char Znak6[len];
    deletePunctuation(Znak5, ':', Znak6);
    char Znak7[len];
    deletePunctuation(Znak6, ';', Znak7);
    char Znak8[len];
    deletePunctuation(Znak7, '(', Znak8);
    char Znak9[len];
    deletePunctuation(Znak8, ')', Znak9);
    char Znak10[len];
    deletePunctuation(Znak9, '[', Znak10);
    char Znak11[len];
    deletePunctuation(Znak10, ']', Znak11);
    char Znak12[len];
    deletePunctuation(Znak11, '-', Znak12);
    char Znak13[len];
    deletePunctuation(Znak12, '\"', Znak13);
    int newlength2 = string_len(Znak5);
    deleteTochka(Znak5, '.', newstroka, newlength2);
    BookvaMal(newstroka, newlength2);
    cout << "Ваша строка: " << endl << newstroka << endl;
    char newstroka2[len];
    Number(newstroka, newstroka2, newlength2);
    cout << "Ваша строка без чисел: " << endl << newstroka2 << endl;
    cout << "Введите последовательность которую нужно удалить: " << endl;
    char posled[len];
    cin.getline(posled, len);
    cin.sync();
    int posledlength = string_len(posled);
    char newstroka3[len];
    Number2(newstroka, posled, newstroka3);
    cout << "Ваша строка: " << endl << newstroka3 << endl;
    cout << "Линейный поиск: " << endl;
    char podstroka[len];
    cin.getline(podstroka, len);
    cin.sync();
    int count = linearSearch(newstroka, podstroka);
    cout << count << " подстрок было найдено " << endl;
}