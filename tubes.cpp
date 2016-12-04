#include "tubes.h"
void createListcabang(List_cabang &L)
{

    first(L) = NULL;
}

address_cabang alokasicabang(infotype_cabang x)
{


    address_cabang P;
    P = new elmlist_cabang;
    info(P) = x;
    next(P) = NULL;
    createListkaryawan(karyawan(P));
    return P;
}

void insertFirstcabang(List_cabang &L, address_cabang P)
{

    address_cabang Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLastcabang(List_cabang &L, address_cabang P)

{
    address_cabang Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }

}
void insertAftercabang(List_cabang &L, address_cabang Prec, address_cabang P)
{
    if (first(L) == NULL)
    {
        insertFirstcabang(L,P);
    }
    else if (next(Prec) == first(L))
    {
        insertLastcabang(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstcabang(List_cabang &L, address_cabang &P)
{
    address_cabang Q;
    if (first(L) != NULL)
    {
        P = first(L);
        if(next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            Q = first(L);
            while (next(Q) != first(L))
            {
                Q=next(Q);
            }
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
            next(Q) = first(L);

        }
    }
}
void deleteAftercabang(List_cabang &L, address_cabang Prec, address_cabang &P)
{
    if (next(Prec) == first(L))
    {
        P = first(L);
        first(L) = next(P);
        next(Prec) = first(L);
        next(P) = NULL;
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void deleteLastcabang(List_cabang &L, address_cabang &P)
{
    address_cabang Q;
    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            Q = first(L);
            while (next(next(Q)) != first(L))
            {
                Q =next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
            next(P) = NULL;
//dealokasi(P);
        }
    }
}


void printInfocabang(List_cabang L)
{
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_cabang P = first(L);
    if(first(L)!=NULL)
    {
        do
        {
            cout<<"ID CABANG            : "<<info(P).id_cabang<<endl;
            cout<<"NAMA CABANG          : "<<info(P).nama_cabang<<endl;
            cout<<"ALAMAT CABANG        : "<<info(P).alamat_cabang<<endl;
            cout<<"KOTA CABANG          : "<<info(P).kota_cabang<<endl;
            cout<<"NAMA KEPALA CABANG   : "<<info(P).kepala_cabang<<endl;
            printInfokaryawan(karyawan(P));
            P = next(P);
        }
        while(info(P).id_cabang !=info(first(L)).id_cabang);
    }
}

address_cabang findElmcabang(List_cabang L, infotype_cabang x)
{

       address_cabang P = first(L);
    if ( first(L) == NULL){
        return NULL;
    }
    else{
        do {
            if(info(P).id_cabang == x.id_cabang) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
}




void createListkaryawan(List_karyawan &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_karyawan alokasikaryawan(infotype_karyawan x)
{
    address_karyawan P = new elmlist_karyawan;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstkaryawan(List_karyawan &L, address_karyawan P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastkaryawan(List_karyawan &L, address_karyawan P)
{
    if(first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}
void insertAfterkaryawan(List_karyawan &L,address_karyawan Prec,address_karyawan P){
    if (first(L) == NULL){
        insertFirstkaryawan(L,P);
    }
    else if (Prec == last(L)){
        insertLastkaryawan(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void printInfokaryawan(List_karyawan L)
{
    address_karyawan P = first(L);
    while(P !=NULL)
    {
        cout<<"ID KARYAWAN          : "<<info(P).id_karyawan<<endl;
        cout<<"NAMA KARYAWAN        : "<<info(P).nama_karyawan<<endl;
        cout<<"JABATAN KARYAWAN     : "<<info(P).jabatan_karyawan<<endl;
        cout<<"TGL LAHIR KARYAWAN   : "<<info(P).tgl_lahir<<endl;
        cout<<"ALAMAT KARYAWAN      : "<<info(P).alamat<<endl;
        P = next(P);
    }
}

void deleteFirstkaryawan(List_karyawan &L, address_karyawan &P)
{
    if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}
void deleteLastkaryawan(List_karyawan &L, address_karyawan &P)
{
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
}
void deleteAfterkaryawan(List_karyawan &L,address_karyawan Prec, address_karyawan &P)
{
    if (Prec == last(L))
    {
        deleteLastkaryawan(L,P);
    }
    else{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}
}

address_karyawan findElmkaryawan(List_karyawan L, infotype_karyawan x)
{
    address_karyawan P = first(L);
    while(P != NULL)
    {
        if(info(P).id_karyawan ==x.id_karyawan)
        {
            return P;
        }
        else
            return NULL;
            P = next(P);
    }

}
