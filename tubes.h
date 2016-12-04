#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <string>

#define info_cabang(p) (p)->info_cabang
#define prev(p) (p)->prev
#define info_karyawan(p) (p)->info_karyawan
#define first(l) ((l).first)
#define last(l) ((l).last)
#define firstkaryawan(p) (p)->firstkaryawan
/*#define lastkaryawan(p) (p)->lastkaryawan*/

using namespace std;

typedef struct elmcabang *address_cabang;
typedef struct elmkaryawan *address_karyawan;

struct cabang
{
    int id_cabang;
    string nama_cabang;
    string alamat_cabang;
    string kota_cabang;
    string kepala_cabang;
};

struct elmcabang
{
    cabang info_cabang;
    address_cabang next;
    address_cabang prev;
    address_karyawan firstkaryawan;
};

struct karyawan
{
    int id_karyawan;
    string nama_karyawan;
    string jabatan_karyawan;
    string tgl_lahir;
    string alamat;
};

struct elmkaryawan
{
    karyawan info_karyawan;
    address_karyawan next;
    address_karyawan firstkaryawan;
};

struct List
{
    address_cabang first;
    address_cabang last;
};

void createcabang (List &l);

address_cabang alokasi_cabang (cabang a);
address_karyawan alokasi_karyawan (karyawan b);

void insertfirst_cabang (List &l, address_cabang p);
void insertfirst_karyawan (address_cabang &p, address_karyawan &q);

void insertafter_cabang (List &l, address_cabang p, address_cabang prec );
void insertafter_karyawan (address_cabang &p, address_karyawan &q, int x);

void insertlast_cabang (List &l, address_cabang p);
void insertlast_karyawan (address_cabang &p, address_karyawan &q);

void deletefirst_cabang (List &l, address_cabang p);
void deletefirst_karyawan (address_cabang &p, address_karyawan &q);

void deleteafter_cabang (List &l, address_cabang &p, address_cabang prec);
void deleteafter_karyawan (address_cabang &p, address_karyawan &q, int y);

void deletelast_cabang (List &l, address_cabang p );
void deletelast_karyawan (address_cabang &p, address_karyawan &q);

address_cabang findelm_cabang (List l, int x);
address_karyawan findelm_karyawan (List l, int y);

void printinfo_cabang (List l );
void printinfo_karyawan (address_cabang &p, address_karyawan q);

void add_cabang(cabang &x);
void add_karyawan (karyawan &y, address_cabang &p);

void printinfo_semua (List l);

#endif // TUBES_H_INCLUDED

