#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n; in >> n; //считывание размера матрицы
    int** a = new int* [n]; //создание дин. массива для записи матрицы
    for (int i = 0; i < n; i++) //считывание массива из файла
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            in >> a[i][j];
    }
    //создание вспомогательных динамических массивов
    int* src = new int[n]; for (int i = 0; i < n; i++) src[i] = 0;
    int* des = new int[n]; for (int i = 0; i < n; i++) des[i] = 0;
    int csrc = 0;
    int cdes = 0;
    int f1, f2;
    for (int i = 0; i < n; i++)
    {
        f1 = f2 = 0;
        for (int j = 0; j < n; j++) // сумма элементов строк
            f1 += a[i][j];
        for (int j = 0; j < n; j++) //сумма элементов столбцов
            f2 += a[j][i];
        if (f1 == 0)
        {
            cdes++;
            des[i] = i + 1;
        }
        if (f2 == 0)
        {
            csrc++;
            src[i] = i + 1;
        }
    }
    /*нахождение с помощью ранее созданных массивов стоков и истоков в графе, запись результатов в выходной файл*/
    bool istoki = false, stoki = false;
    //out << csrc;
    for (int i = 0; i < n; i++)
        if (src[i] != 0)
        {
            istoki = true;
            out << src[i] << ' ';
        }
    if (istoki == false) out << "Истоки не найдены ";

    out << '\n';

    for (int i = 0; i < n; i++)
        if (des[i] != 0)
        {
            stoki = true;
            out << des[i] << ' ';
        }
    if (stoki == false) out << "Cтоки не найдены ";

    in.close();
    out.close();
    for (int i = 0; i < n; i++) //очистка памяти от динамических массивов
        delete[] a[i];
    delete[] a;
    return 0;
}
