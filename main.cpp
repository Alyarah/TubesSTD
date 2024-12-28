#include <iostream>
#include "RutePengiriman.h"

using namespace std;

int main()
{
    graph G;
    buildGraph(G);
    int pilihan = -1;
    while (pilihan != 0) {
        pilihan = pilihMenu();
        switch (pilihan) {
        case 1: {
            tambahRute(G);
            break;
        }
        case 2: {
            printAllData(G);
            break;
        }
        case 3: {
            string asal, tujuan;
            int Max;
            cout << "Asal pengiriman: ";
            cin >> asal;
            cout << "Tujuan pengiriman: ";
            cin >> tujuan;
            cout << "Masukkan harga maksimum: ";
            cin >> Max;
            cekHarga(G, asal, tujuan, Max);

            break;
        }
        case 4: {
            string asal, tujuan;
            int hari;
            cout << "Masukkan asal pengiriman: ";
            cin >> asal;
            cout << "Masukkan tujuan pengiriman: ";
            cin >> tujuan;
            cout << "Masukkan jumlah hari yang diinginkan: ";
            cin >> hari;
            cekHari(G, asal, tujuan, hari);
            break;
        }
        case 0:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
    return 0;
}
