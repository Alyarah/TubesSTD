#ifndef RUTEPENGIRIMAN_H_INCLUDED
#define RUTEPENGIRIMAN_H_INCLUDED
#define firstGudang(G) G.firstGudang
#define nextGudang(v) v->nextGudang
#define firstRute(v) v->firstRute
#define namaGudang(v) v->namaGudang
#define nextRute(e) e->nextRute
#define destVertexID(e) e->destVertexID
#define biaya(e) e->biaya
#define jumlahHari(e) e->jumlahHari
#include <iostream>

using namespace std;

typedef struct gudang *adrGudang;
typedef struct rute *adrRute;
struct gudang{
    string namaGudang;
    adrGudang nextGudang;
    adrRute firstRute;
};
struct rute{
    char destVertexID;
    int biaya;
    int jumlahHari;
    adrRute nextRute;
};

struct graph{
    adrGudang firstGudang;
};

void createGudang(string namaGudangBaru, adrGudang &v);
void initGraph(graph &G);
void addGudang(graph &G, string namaGudangBaru);
void buildGraph(graph &G);
void createRute(int biaya, int jumlahHari, adrRute &e);
int pilihMenu();
void printAllData(graph &G);
void cekHarga(graph G, string asal, string tujuan, int Max);
void cekHari(graph G, string asal, string tujuan, int hari);
void tambahRute(graph &G);
#endif // RUTEPENGIRIMAN_H_INCLUDED
