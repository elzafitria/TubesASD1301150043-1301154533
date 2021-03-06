#include <iostream>
#include "tubes.h"

using namespace std;

int IDcabang=0;
int IDkaryawan = 0;

void createcabang (List &l)
{
    first(l)=NULL;
    last(l)=NULL;
}

address_cabang alokasi_cabang(cabang a)
{
    address_cabang p = new elmcabang;
    info_cabang(p) = a;
    (p)->next=NULL;
    prev(p)=NULL;
    firstkaryawan(p)=NULL;
    return p;
}

address_karyawan alokasi_karyawan (karyawan b)
{
    address_karyawan p = new elmkaryawan;
    info_karyawan(p) = b;
    (p)->next=NULL;
    return p;
}

void insertfirst_cabang(List &l, address_cabang p)
{
    if (first(l) != NULL && last(l) !=NULL)
    {
        (p)->next=first(l);
        prev(first(l))=p;
        first(l)=p;

    }
    else
    {
        first(l)=p;
        last(l)=p;
    }
}

void insertlast_cabang (List &l, address_cabang p)
{
    if(first(l) == NULL)
    {
        insertfirst_cabang(l,p);
    }
    else
    {
        prev(p)=last(l);
        (last(l))->next=p;
        last(l)=p;
        (p)->next = NULL;
    }
}

void insertafter_cabang (List &l, address_cabang p, address_cabang prec)
{
    if(first(l) == NULL)
    {
        insertfirst_cabang(l,p);
    }
    else if ((last(l))->next == NULL)
    {
        insertlast_cabang (l,p);
    }
    else
    {
        (p)->next = (prec)->next;
        prev(p)=prec;
        prev((prec)->next)=p;
        (prec)->next=p;
    }
}

void insertfirst_karyawan (address_cabang &p, address_karyawan &q)
{
    if(firstkaryawan(p)==NULL)
        firstkaryawan(p)=q;
    else
    {
        (q)->next=firstkaryawan(p);
        firstkaryawan(p)=q;
    }
}

void insertlast_karyawan (address_cabang &p, address_karyawan &q)
{
    if (firstkaryawan(p)== NULL)
    {
        insertfirst_karyawan(p,q);
    }
    else
    {
        address_karyawan a = firstkaryawan(p);
        while((a)->next!=NULL)
        {
            a=(a)->next;
        }
        (a)->next=q;
    }
}

void insertafter_karyawan(address_cabang &p, address_karyawan &q, int x)
{
    address_karyawan prec = firstkaryawan(p);
    if (prec == NULL)
    {
        insertfirst_karyawan(p,q);
    }
    else
    {
        while(info_karyawan(prec).id_karyawan!=x)
        {
            prec = (prec)->next;
        }
        if ((prec)->next == NULL)
        {
            insertlast_karyawan(p,q);
        }
        else
        {
            (q)->next=(prec)->next;
            (prec)->next=q;
        }
    }
}

void deletefirst_cabang (List &l, address_cabang p)
{
    if (first(l)==NULL)
    {
        cout<<"Tidak ada data";
    }
    else if (first(l) == last(l))
    {
        first(l) = NULL;
        last(l) = NULL;
    }
    else
    {
        p=first(l);
        first(l)=(first(l))->next;
        (p)->next=NULL;
        prev(first(l))=NULL;
    }
}

void deletelast_cabang (List &l, address_cabang p)
{
    if (first(l) == NULL)
    {
        cout<<"Tidak ada data";
    }
    else if (first(l) == last(l))
    {
        first(l)=NULL;
        last(l)=NULL;
    }
    else
    {
        p=last(l);
        last(l)=prev(last(l));
        prev(p)=NULL;
        (last(l))->next=NULL;
    }
}

void deleteafter_cabang (List &l, address_cabang &p, address_cabang prec)
{
    if(p == first(l))
    {
        deletefirst_cabang(l,p);
    }
    else if (p == last(l))
    {
        deletelast_cabang(l,p);
    }
    else
    {
        prec = prev(p);
        (prec)->next = (p)->next;
        prev((p)->next)=prec;
        prev(p)=NULL;
        (p)->next=NULL;
    }
}

void deletefirst_karyawan(address_cabang &p, address_karyawan &q)
{
    //if (firstkaryawan(p) != NULL)
    //{
        q=firstkaryawan(p);
        if((q)!=NULL)
        {
            q=firstkaryawan(p);
            firstkaryawan(q)=(q)->next;
            (q)->next=NULL;
        }
        else
        {
            cout<<"Data tidak ada";
        }
    ////}
}

void deletelast_karyawan(address_cabang &p, address_karyawan &q)
{
    q=firstkaryawan(p);
    if(q!=NULL)
    {
        while((q)->next!=NULL)
            q=(q)->next;
        q=(q)->next;
        (q)->next=NULL;
    }
    else
    {
        cout<<"Data tidak ada";
    }
}

void deleteafter_karyawan(address_cabang &p, address_karyawan &q, int y)
{
    q=firstkaryawan(p);
    if (q!= NULL)
    {
        while (info_karyawan(q).id_karyawan!=y)
        {
            q=(q)->next;
        }
        if(q=firstkaryawan(p))
        {
            deletefirst_karyawan(p,q);
        }
        else if ((q)->next==NULL)
        {
            deletelast_karyawan(p,q);
        }
        else
        {
            address_karyawan prec = q;
            q=(prec)->next;
            (prec)->next=(q)->next;
            (q)->next=NULL;
        }
    }
    else
    {
        cout<<"Data kosong";
    }
}

address_cabang findelm_cabang (List l, int x)
{
    address_cabang p;
    p=first(l);
    if (p!=NULL)
    {
        while(p!=NULL)
        {
            if (info_cabang(p).id_cabang==x)
                return p;
            else
                p=(p)->next;
        }
    }
    else
    {
        return NULL;
        cout<<"Data tidak ada"<<endl;
        cout<<endl;
    }
}

address_karyawan findelm_karyawan(address_cabang p, int y)
{
    address_karyawan q;
    q=firstkaryawan(p);
    if(q!=NULL)
    {
        do
        {
            q=(q)->next;
        }
        while (info_karyawan(q).id_karyawan!=y);
    }
    else
    {
        q = NULL;
        cout<<"Data tidak ada"<<endl;;
    }
    return q;
}

void printinfo_cabang (List l)
{
    address_cabang p=first(l);
    if (p!=NULL)
    {
        do
        {
        cout<<"ID CABANG            : "<<info_cabang(p).id_cabang<<endl;
        cout<<"NAMA CABANG          : "<<info_cabang(p).nama_cabang<<endl;
        cout<<"ALAMAT CABANG        : "<<info_cabang(p).alamat_cabang<<endl;
        cout<<"KOTA CABANG          : "<<info_cabang(p).kota_cabang<<endl;
        cout<<"NAMA KEPALA CABANG   : "<<info_cabang(p).kepala_cabang<<endl;
        p=(p)->next;
        }while (p!=NULL);
    }
    else
    {
        cout<<"Data kosong";
        cout<<endl;
    }

    //cout<<"Jumlah data cabang: "<<i;

}

void printinfo_karyawan (address_cabang &p, address_karyawan q)
{
    int j = 0;
    if (firstkaryawan(p)!=NULL)
    {
        q=firstkaryawan(p);
        while((q)->next!=NULL)
        {
            cout<<"ID KARYAWAN          : "<<info_karyawan(q).id_karyawan<<endl;
            cout<<"NAMA KARYAWAN        : "<<info_karyawan(q).nama_karyawan<<endl;
            cout<<"JABATAN KARYAWAN     : "<<info_karyawan(q).jabatan_karyawan<<endl;
            cout<<"TGL LAHIR KARYAWAN   : "<<info_karyawan(q).tgl_lahir<<endl;
            cout<<"ALAMAT KARYAWAN      : "<<info_karyawan(q).alamat<<endl;
            q= (q)->next;
            j++;
            cout<<endl;
            cout<<endl;
        }
    }
    cout<<"Jumlah data karyawan: "<<j;

}

void add_cabang (cabang &x)
{
    //IDcabang++;
    //x.id_cabang = IDcabang;
    cout<<"ID CABANG:           : ";
    cin>>x.id_cabang;
    cout<<"NAMA CABANG          : ";
    cin>>x.nama_cabang;
    cout<<"ALAMAT CABANG        : ";
    cin>>x.alamat_cabang;
    cout<<"KOTA CABANG          : ";
    cin>>x.kota_cabang;
    cout<<"NAMA KEPALA CABANG   : ";
    cin>>x.kepala_cabang;
}

void add_karyawan (karyawan &y, address_cabang &p)
{
    //IDkaryawan++;
    //y.id_karyawan = IDkaryawan;
    cout<<"ID KARYAWAN          : ";
    cin>>y.id_karyawan;
    cout<<"NAMA KARYAWAN        : ";
    cin>>y.nama_karyawan;
    cout<<"JABATAN KARYAWAN     : ";
    cin>>y.jabatan_karyawan;
    cout<<"TGL LAHIR KARYAWAN   : ";
    cin>>y.tgl_lahir;
    cout<<"ALAMAT KARYAWAN      : ";
    cin>>y.alamat;

}

void printinfo_semua (List l)
{
    address_cabang p;
    address_karyawan q;
    p=first(l);
    while (p!=NULL)
    {
        cout<<"ID CABANG            : "<<info_cabang(p).id_cabang<<endl;
        cout<<"NAMA CABANG          : "<<info_cabang(p).nama_cabang<<endl;
        cout<<"ALAMAT CABANG        : "<<info_cabang(p).alamat_cabang<<endl;
        cout<<"KOTA CABANG          : "<<info_cabang(p).kota_cabang<<endl;
        cout<<"NAMA KEPALA CABANG   : "<<info_cabang(p).kepala_cabang<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<endl;
        printinfo_karyawan(p,q);
        cout<<endl;
        p=(p)->next;
    }
}
