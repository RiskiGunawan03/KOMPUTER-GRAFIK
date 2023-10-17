#include <iostream>

using namespace std;

class Matrix
{
public:
    int data[2][2];

    Matrix()
    {
        // Inisialisasi matriks dengan nilai 0
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    Matrix operator+(const Matrix &other)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other)
    {
        Matrix result;
        result.data[0][0] = this->data[0][0] * other.data[0][0] + this->data[0][1] * other.data[1][0];
        result.data[0][1] = this->data[0][0] * other.data[0][1] + this->data[0][1] * other.data[1][1];
        result.data[1][0] = this->data[1][0] * other.data[0][0] + this->data[1][1] * other.data[1][0];
        result.data[1][1] = this->data[1][0] * other.data[0][1] + this->data[1][1] * other.data[1][1];
        return result;
    }
};

int main()
{
    Matrix matriks1, matriks2, hasil;
    int pilihan;

    cout << "Pilih operasi: " << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cin >> pilihan;

    cout << "Masukkan angka matriks pertama:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Baris " << i + 1 << ", Kolom " << j + 1 << ": ";
            cin >> matriks1.data[i][j];
        }
    }

    cout << "Masukkan angka matriks kedua:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Baris " << i + 1 << ", Kolom " << j + 1 << ": ";
            cin >> matriks2.data[i][j];
        }
    }

    switch (pilihan)
    {
    case 1:
        hasil = matriks1 + matriks2;
        cout << "Hasil tambah:" << endl;
        break;
    case 2:
        hasil = matriks1 - matriks2;
        cout << "Hasil kurang:" << endl;
        break;
    case 3:
        hasil = matriks1 * matriks2;
        cout << "Hasil kali:" << endl;
        break;
    default:
        cout << "Pilihan salah" << endl;
        return 1;
    }

    // Menampilkan hasil
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << hasil.data[i][j] << " ";
        }
        cout << endl;
    }

        return 0;
}
