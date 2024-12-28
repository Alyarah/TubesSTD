#include "RutePengiriman.h"

using namespace std;

void createGudang(string namaGudang, adrGudang &v){
    v = new gudang;
    namaGudang(v) = namaGudang;
    firstRute(v) = NULL;
    nextGudang(v) = NULL;
}
void initGraph(graph &G){
    firstGudang(G) = NULL;
}
void addGudang(graph &G, string namaGudang){

    adrGudang v;
    createGudang(namaGudang, v);
    if(firstGudang(G) == NULL){
        firstGudang(G) = v;
    }else{
        adrGudang w = firstGudang(G);
        while(nextGudang(w) != NULL){
            w = nextGudang(w);
        }
        nextGudang(w) = v;
    }

}

void createRute(char destVertexID, int biaya, int jumlahHari, adrRute &e) {
    e = new rute;
    destVertexID(e) = destVertexID;
    biaya(e) = biaya;
    jumlahHari(e) = jumlahHari;
    nextRute(e) = NULL;
}

void buildGraph(graph &G){
    initGraph(G);
    addGudang(G, "A");
    addGudang(G, "B");
    addGudang(G, "C");
    addGudang(G, "D");
    addGudang(G, "E");

    adrGudang A = firstGudang(G);
    adrGudang B = nextGudang(A);
    adrGudang C = nextGudang(B);
    adrGudang D = nextGudang(C);
    adrGudang E = nextGudang(D);

    if (A != NULL && B != NULL && C != NULL && D != NULL && E != NULL) {
        adrRute ruteAB, ruteAC, ruteAD;
        adrRute ruteBC, ruteBD, ruteBE;
        adrRute ruteCD, ruteCE;
        adrRute ruteDE;
        adrRute ruteEA;

        createRute('B', 10000, 1, ruteAB);
        createRute('C', 21000, 3, ruteAC);
        createRute('D', 29000, 5, ruteAD);

        createRute('C', 8000, 1, ruteBC);
        createRute('D', 18000, 3, ruteBD);
        createRute('E', 45000, 7, ruteBE);

        createRute('D', 10000, 2, ruteCD);
        createRute('E', 16000, 4, ruteCE);

        createRute('E', 21000, 2, ruteDE);

        createRute('A', 60000, 7, ruteEA);

        firstRute(A) = ruteAB;
        nextRute(ruteAB) = ruteAC;
        nextRute(ruteAC) = ruteAD;

        firstRute(B) = ruteBC;
        nextRute(ruteBC) = ruteBD;
        nextRute(ruteBD) = ruteBE;

        firstRute(C) = ruteCD;
        nextRute(ruteCD) = ruteCE;

        firstRute(D) = ruteDE;

        firstRute(E) = ruteEA;
    }
}



int pilihMenu(){
    int input = 0;

    cout << "================MENU=================" << endl;
    cout << "1. Menambah rute pengiriman" << endl;
    cout << "2. Menampilkan semua data pengiriman" << endl;
    cout << "3. Cek data berdasarkan harga " << endl;
    cout << "4. Cek data berdasarkan hari " << endl;
    cout << "0. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Masukkan menu : ";
    cin >> input;
    return input;
}

void printAllData(graph &G){
    cout << "Rute pengiriman yang tersedia: \n";
    adrGudang v = firstGudang(G);
    while(v != NULL){
        cout << "Gudang: " << namaGudang(v)<<endl;
        adrRute e = firstRute(v);
        while (e != NULL) {
            cout << "  Rute ke gudang " << destVertexID(e) << ": (" << jumlahHari(e)
            << " hari) " << biaya(e) << endl;
            e = nextRute(e);
        }
        v = nextGudang(v);
    }
    cout << " " << endl;
}

void cekHarga(graph G, string asal, string tujuan, int Max) {

    adrGudang gudangAsal = firstGudang(G);

    adrRute rute = firstRute(gudangAsal);
    bool ditemukan = false;

    while (rute != NULL) {
        if (destVertexID(rute) == tujuan[0] && biaya(rute) <= Max) {
            cout << "Rute ditemukan: " << asal << " ke " << tujuan << ", Harga: " << biaya(rute) << endl;
            ditemukan = true;
        }
        rute = nextRute(rute);
    }

    if (!ditemukan) {
        cout << "Tidak ada rute yang sesuai." << endl;

    }
}

void cekHari(graph G, string asal, string tujuan, int hari) {
    adrGudang gudangAsal = firstGudang(G);
    bool ditemukan = false;

    while (gudangAsal != NULL && namaGudang(gudangAsal) != asal) {
        gudangAsal = nextGudang(gudangAsal);
    }

    if (gudangAsal != NULL) {
        adrRute rute = firstRute(gudangAsal);
        while (rute != NULL) {

            if (destVertexID(rute) == tujuan[0] && jumlahHari(rute) == hari) {
                cout << "Rute ditemukan dari Gudang " << asal
                     << " ke Gudang " << tujuan
                     << " dengan jumlah hari: " << jumlahHari(rute)
                     << " dan biaya: " << biaya(rute) << endl;
                ditemukan = true;
            }
            rute = nextRute(rute);
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada rute yang sesuai dengan asal, tujuan, dan jumlah hari tersebut." << endl;
    }
}

void tambahRute(graph &G) {
    string asal, tujuan;
    int biayaRute, jumlahHari;

    cout << "Masukkan asal pengiriman: ";
    cin >> asal;
    cout << "Masukkan tujuan pengiriman: ";
    cin >> tujuan;
    cout << "Masukkan biaya pengiriman: ";
    cin >> biayaRute;
    cout << "Masukkan jumlah hari pengiriman: ";
    cin >> jumlahHari;

    adrGudang gudangAsal = firstGudang(G);
    while (gudangAsal != NULL && namaGudang(gudangAsal) != asal) {
        gudangAsal = nextGudang(gudangAsal);
    }

    if (gudangAsal != NULL) {
        adrRute ruteBaru;
        createRute(tujuan[0], biayaRute, jumlahHari, ruteBaru);
        adrRute lastRute = firstRute(gudangAsal);
        if (lastRute == NULL) {
            firstRute(gudangAsal) = ruteBaru;
        } else {
            while (nextRute(lastRute) != NULL) {
                lastRute = nextRute(lastRute);
            }
            nextRute(lastRute) = ruteBaru;
        }
        cout << "Rute dari " << asal << " ke " << tujuan << " berhasil ditambahkan." << endl;
    } else {
        cout << "Gudang asal tidak ditemukan!" << endl;
    }
}
