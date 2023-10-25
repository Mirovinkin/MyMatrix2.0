// MyMatrix2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>

using namespace std;

template<typename T, typename K>
class MyMatrix
{
private:
    T** _matrix;
    K _rows, _cols;
public:
    MyMatrix() {};
    MyMatrix(const T** Matrix) : _matrix(Matrix) {};

    void SetMatrix(const K& Rows, const K& Cols) {
        _rows = Rows;
        _cols = Cols;
        _matrix =  new T * [_rows];
        for (int i = 0; i < _rows; i++)
        {
            _matrix[i] = new T[_cols]{};
        }

        cout << "Заполните массив";
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                cout << "Введите " << j + 1 << " элемент" << i + 1 << " строки";
                cin >> _matrix[i][j];
            }
        }
    }
    void SetRandMatrix(const K& Rows, const K& Cols) {
        _rows = Rows;
        _cols = Cols;
        srand(time(NULL));
        _matrix = new T * [_rows];

        for (int i = 0; i < _rows; i++)
        {
            _matrix[i] = new T[_cols]{};
        }

        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                _matrix[i][j] = 1 + rand() % 100;
            }
        }
        cout << "Массив заполнен рандомно числами от 1 до 100";
    }
    
    void PrintMatrix() {
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                cout << _matrix[i][j] << endl;
            }
            cout << endl;
        }
    }
    void ClearMatrix(T** Matrix, K Rows) {
        for (int i = 0; i < Rows; i++)
        {
            delete[] Matrix[i];
        }
        delete[] Matrix;
    }

    T** operator + (T** MatrixN) {
        T** matrixRes = new T * [_rows];

        for (int i = 0; i < _rows; i++)
        {
            MatrixRes[i] = new T[_cols]{};
        }

        for (int i = 0, k = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                matrixRes[k++] = _matrix[i][j] + MatrixN[i][j];
            }
        }
        return matrixRes;
    }

    T** operator - (T** MatrixN) {
        T** matrixRes = new T * [_rows];

        for (int i = 0; i < _rows; i++)
        {
            MatrixRes[i] = new T[_cols]{};
        }

        for (int i = 0, k = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                matrixRes[k++] = _matrix[i][j] - MatrixN[i][j];
            }
        }
        return matrixRes;
    }

    T** operator + (T** MatrixN) {
        T** matrixRes = new T * [_rows];

        for (int i = 0; i < _rows; i++)
        {
            MatrixRes[i] = new T[_cols]{};
        }

        for (int i = 0, k = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                matrixRes[k++] = _matrix[i][j] * MatrixN[i][j];
            }
        }
        return matrixRes;
    }

    T** operator + (T** MatrixN) {
        T** matrixRes = new T * [_rows];

        for (int i = 0; i < _rows; i++)
        {
            MatrixRes[i] = new T[_cols]{};
        }

        for (int i = 0, k = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                matrixRes[k++] = _matrix[i][j] / MatrixN[i][j];
            }
        }
        return matrixRes;
    }
T MatrixMax() {
        T max = 0;
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                if (max(_matrix[i][j], _matrix[i][j + 1])) {
                    max = _matrix[i][j];
                }
                else {
                    continue;
                }
            }
        }

        return max;
    }

    T MatrixMin() {
        T min = 0;
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                if (min(_matrix[i][j], _matrix[i][j + 1])) {
                    max = _matrix[i][j];
                }
                else {
                    continue;
                }
            }
        }

        return min;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
