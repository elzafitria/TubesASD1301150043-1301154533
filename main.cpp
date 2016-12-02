#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tubes.h"
#include "tubes.cpp"


using namespace std;

int main()
{
    List l;
    cabang a;
    karyawan b;
    address_cabang p;
    address_karyawan q;
    createcabang(l);
    int pilihan=0;
    int cariID;
while(pilihan!=10)
{

    cout<<"                 DATABASE KARYAWAN PT.JADI TERUS             "<<"\n";
    cout<<"============================================================="<<"\n";
    system("CLS");
    cout<<"Menu: "<<"\n";
    cout<<"1. Tambah cabang "<<"\n";
    cout<<"2. Tambah Karyawan "<<"\n";
    cout<<"3. Cari cabang berdasarkan ID "<<"\n";
    cout<<"4. Cari karyawan berdasarkan ID "<<"\n";
    cout<<"5. Edit data cabang "<<"\n";
    cout<<"6. Edit data karyawan "<<"\n";
    cout<<"7. Hapus data cabang "<<"\n";
    cout<<"8. Hapus data karyawan "<<"\n";
    cout<<"9. Munculkan data keseluruhan"<<"\n";
    cout<<"10. Exit"<<"\n";
    cin>>pilihan;

    if (pilihan==1)
    {
        system("CLS");
        cabang x;
        add_cabang(x);
        if (first(l) == NULL)
        {
            p=alokasi_cabang(x);
            insertlast_cabang(l,p);
            system("CLS");
            cout<<"Data berhasil diinput"<<endl;
            cout<<"---------------------"<<endl<<endl;
            printinfo_cabang(l);
        }
        else
        {
            insertlast_cabang(l,p);
            system("CLS");
            cout<<"Data berhasil diinput"<<endl;
            cout<<"---------------------"<<endl<<endl;
            printinfo_cabang(List(l));
        }
        getch();
    }
    else if (pilihan ==2)

    {
        system("CLS");
        cout<<"Data cabang tersedia"<<endl;
        cout<<"--------------------"<<endl<<endl;
        printinfo_cabang(l);
        cout<<endl;
        cout<<"Masukan ID Cabang yang ingin diinputkan: ";
        cin>>cariID;
        p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            cout<<endl;
            karyawan y;
            add_karyawan(y,p);
            address_karyawan q=alokasi_karyawan(y);
            insertlast_karyawan(p,q);
            system("CLS");
            cout<<"Data berhasil diinput"<<endl<<endl;
            printinfo_karyawan(p,q);
        }
        else
        {
            cout<<"Tidak ada data cabang";
        }
        getch();
    }

    else if (pilihan ==3)
    {
        system("CLS");
        cout<<"Masukan ID cabang yang ingin dicari: ";
        cin>>cariID;
        p=findelm_cabang (l, cariID);
        if (p!=NULL)
        {
            printinfo_cabang(l);
        }
        else
        {
            cout<<"Data tidak ditemukan";
        }
        getch();
    }


    else if (pilihan ==4)
    {
        system("CLS");
        cout << "Data cabang yang tersedia" << endl;
        cout <<"--------------------------" << endl<<endl;
        printinfo_cabang(l);
        cout<<endl;
        cout<<"Masukan ID cabang: ";
        cin>>cariID;
        p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            cout<<endl<<"Masukan ID karyawan yang ingin dicari: ";
            cin>>cariID;
            q=findelm_karyawan(p,cariID);
            if(q!=NULL)
            {
                printinfo_karyawan(p,q);
            }
            else
            {
                cout<<"Data tidak ditemukan";
            }
        }
        else
        {
            cout<<"Data tidak ditemukan";
        }
        getch();
    }

    else if (pilihan ==5)
    {
        system("CLS");
        cout<<"Data cabang yang tersedia" << endl
            <<"-------------------------" << endl<<endl;
        printinfo_cabang(l);
        cout<<endl;
        cout<<"Masukan ID cabang yang ingin diubah: "<<endl;
        cin>>cariID;
        p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            cout<<"ID CABANG            : ";
            cout<<info_cabang(p).id_cabang;
            cout<<endl;
            cout<<"NAMA CABANG          : ";
            cout<<endl;
            cin>>info_cabang(p).nama_cabang;
            cout<<"ALAMAT CABANG        : ";
            cout<<endl;
            cin>>info_cabang(p).alamat_cabang;
            cout<<"KOTA CABANG          : ";
            cout<<endl;
            cin>>info_cabang(p).kota_cabang;
            cout<<"NAMA KEPALA CABANG   : ";
            cout<<endl;
            cin>>info_cabang(p).kepala_cabang;
            cout<<endl;
            cout<<"Data telah diubah";
        }
        else
        {
            cout<<"Data tidak ditemukan";
        }
        getch();
    }

    else if (pilihan ==6)
    {
        system("CLS");
        cout << "Data cabang yang tersedia" << endl;
        cout <<"--------------------------" << endl<<endl;
        printinfo_cabang(l);
        cout<<endl;
        cout<<"Masukan ID cabang: ";
        cin>>cariID;
        p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            cout<<endl<<"Masukan ID karyawan yang ingin dicari: ";
            cin>>cariID;
            q=findelm_karyawan(p,cariID);
            if(q!=NULL)
            {
                cout<<"ID KARYAWAN          : ";
                cout<<info_karyawan(q).id_karyawan;
                cout<<endl;
                cout<<"NAMA KARYAWAN        : ";
                cin>>info_karyawan(q).nama_karyawan;
                cout<<endl;
                cout<<"JABATAN KARYAWAN     : ";
                cin>>info_karyawan(q).jabatan_karyawan;
                cout<<endl;
                cout<<"TGL LAHIR KARYAWAN   : ";
                cin>>info_karyawan(q).tgl_lahir;
                cout<<endl;
                cout<<"ALAMAT KARYAWAN      : ";
                cin>>info_karyawan(q).alamat;
                cout<<endl;
                cout<<"Data telah diubah";
            }
            else
            {
                cout<<"Data tidak ditemukan";
            }
        }
        else
        {
            cout<<"Data tidak ditemukan";
        }
        getch();
    }

    else if (pilihan ==7)
    {
        system("CLS");
        address_cabang prec;
        address_karyawan q;
        printinfo_cabang(l);
        cout<<"Masukan ID cabang yang ingin dihapus: ";
        cin>>cariID;
        address_cabang p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            while(firstkaryawan(p)!=NULL)
            {
                deletefirst_karyawan(p,q);
            }
            /*deleteafter_cabang(l,p,prec);*/
            cout<<"Data cabang telah terhapus berikut data karyawannya"<<endl<<endl;
            if(p==NULL)
            {
                cout<<"Data terhapus";
            }
            else
            {
                cout<<"Cabang tidak ditemukan";
            }
            getch();
        }
    }

    else if (pilihan ==8)
    {
        system("CLS");
        address_cabang p;
        address_karyawan q;
        printinfo_cabang(l);
        cout<<"Masukan ID cabang dimana data karyawan ingin dihapus"<<endl<<endl;
        cin>>cariID;
        p=findelm_cabang(l,cariID);
        if(p!=NULL)
        {
            printinfo_karyawan(p,q);
            cout<<endl<<"Masukan ID karyawan yang ingin dihapus: ";
            cin>>cariID;
            deleteafter_karyawan(p, q, cariID - 1);
            cout<<"Data telah terhapus";

        }
        getch();
    }

    else if (pilihan ==9)
    {
        system("CLS");
        printinfo_semua (l);
        getch();
    }

    else if (pilihan ==10)
    {
        cout<<"Terima Kasih"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Egriano Aristianto (1301150043)"<<endl;
        cout<<"Elza Fitria D (1301154533)"<<endl;
    }
}



}


