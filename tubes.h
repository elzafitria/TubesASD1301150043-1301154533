#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;



#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define karyawan(P) P->karyawan
#define next(P) P->next
#define prev(P) P->prev




typedef struct elmlist_cabang *address_cabang;
typedef struct karyawan infotype_karyawan;
typedef struct elmlist_karyawan *address_karyawan;
typedef struct cabang infotype_cabang;
struct cabang
{
    int id_cabang;
    string nama_cabang;
    string alamat_cabang;
    string kota_cabang;
    string kepala_cabang;
};

struct karyawan
{
    int id_karyawan;
    string nama_karyawan;
    string jabatan_karyawan;
    string tgl_lahir;
    string alamat;
};


struct List_cabang {
    address_cabang first;
};


struct elmlist_karyawan{
    infotype_karyawan info;
    address_karyawan next;
    address_karyawan prev;
};

struct List_karyawan{
    address_karyawan first;
    address_karyawan last;
};
struct elmlist_cabang {
    infotype_cabang info;
    address_cabang next,prev;
    List_karyawan karyawan;

};




void createListcabang(List_cabang &L);
void insertFirstcabang(List_cabang &L, address_cabang P);
void insertAftercabang(List_cabang &L, address_cabang Prec, address_cabang P);
void insertLastcabang(List_cabang &L, address_cabang P);
void deleteFirstcabang(List_cabang &L, address_cabang &P);
void deleteLastcabang(List_cabang &L, address_cabang &P);
void deleteAftercabang(List_cabang &L, address_cabang Prec, address_cabang &P);
address_cabang alokasicabang(infotype_cabang x);
void dealokasicabang(address_cabang &P);
address_cabang findElmcabang(List_cabang L, infotype_cabang x);
void printInfocabang(List_cabang L);

void createListkaryawan(List_karyawan &L);
void insertFirstkaryawan(List_karyawan &L, address_karyawan P);
void insertLastkaryawan(List_karyawan &L, address_karyawan P);
void insertAfterkaryawan(List_karyawan &L,address_karyawan Prec, address_karyawan P);
void deleteFirstkaryawan(List_karyawan &L, address_karyawan &P);
void deleteLastkaryawan(List_karyawan &L, address_karyawan &P);
void deleteAfterkaryawan(List_karyawan &L,address_karyawan Prec, address_karyawan &P);
address_karyawan alokasikaryawan(infotype_karyawan x);
void dealokasikaryawan(address_karyawan &P);
address_karyawan findElmkaryawan(List_karyawan L, infotype_karyawan x);
void printInfokaryawan(List_karyawan L);

#endif // RESERV_H_INCLUDED
