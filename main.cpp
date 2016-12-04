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
    int cariIDcabang;
    int cariIDkaryawan;
while(pilihan!=10)
{

    system("CLS");
    cout<<"                 DATABASE KARYAWAN PT.JADI TERUS             "<<"\n";
    cout<<"============================================================="<<"\n";
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
    cout<<"==============================================================="<<"\n";
    cout<<"Pilihan: ";
    cin>>pilihan;

    if (pilihan==1)
    {
        int cekIDcabang;
        system("CLS");
        cabang x;
        if (first(l) == NULL)
        {
            add_cabang(x);
            p=alokasi_cabang(x);
            insertfirst_cabang(l,p);
            system("CLS");
            cout<<"Data berhasil diinput"<<endl;
            cout<<"---------------------"<<endl<<endl;
            //printinfo_cabang(l);
        }
        else
        {
            system("CLS");
            cout<<"Cek kesediaan ID yang ingin dibuat"<<endl;
            cin>>cariIDcabang;
            if(findelm_cabang(l,cariIDcabang)!=NULL)
            {
                cout<<"ID sudah ada";
                getch();
            }
            else
            {
                address_cabang Q = first(l);
                address_cabang temp = first(l);
                while ((Q)->next != NULL)
                {
                    if(info_cabang((Q)->next).id_cabang < x.id_cabang)
                    {
                        temp=(temp)->next;
                    }
                    Q=(Q)->next;
                }
                add_cabang(x);
                insertafter_cabang(l,temp,Q);
                cout<<"Data berhasil diinput"<<endl;
                cout<<"---------------------"<<endl<<endl;
            }
            //insertlast_cabang(l,p);

            //printinfo_cabang(l);
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
        cin>>cariIDcabang;
        p=findelm_cabang(l,cariIDcabang);
        if(p!=NULL)
        {
            cout<<"Masukan ID karyawan yang ingin diinputkan: ";
            cin>>cariIDkaryawan;
            if(findelm_karyawan(p,cariIDkaryawan)!=NULL)
            {
                cout<<"ID sudah ada";
                getch();
            }
            else
            {
                /*address_karyawan Q = firstkaryawan(p);
                address_karyawan temp = firstkaryawan(p);
                address_karyawan y;
                while ((Q)!= NULL)
                {
                    if(info_karyawan((Q)->next).id_karyawan < cariIDkaryawan)
                    {
                        temp=(temp)->next;
                    }
                    Q=(Q)->next;
                }

                insertafter_karyawan(p,temp,cariIDkaryawan);
                add_karyawan(b,p);
                insertlast_karyawan(p,q);
                cout<<"Data berhasil diinput"<<endl;
                cout<<"---------------------"<<endl<<endl;*/
            }
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
            cout<<"Tidak ada data cabang"<<endl;
        }
        getch();
    }

    else if (pilihan ==3)
    {
        system("CLS");
        cout<<"Masukan ID cabang yang ingin dicari: ";
        cin>>cariIDcabang;
        p=findelm_cabang (l, cariIDcabang);
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
        cin>>cariIDcabang;
        p=findelm_cabang(l,cariIDcabang);
        if(p!=NULL)
        {
            cout<<endl<<"Masukan ID karyawan yang ingin dicari: ";
            cin>>cariIDkaryawan;
            q=findelm_karyawan(p,cariIDkaryawan);
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
        cin>>cariIDcabang;
        p=findelm_cabang(l,cariIDcabang);
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
        cin>>cariIDcabang;
        p=findelm_cabang(l,cariIDcabang);
        if(p!=NULL)
        {
            cout<<endl<<"Masukan ID karyawan yang ingin dicari: ";
            cin>>cariIDkaryawan;
            q=findelm_karyawan(p,cariIDkaryawan);
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
        cin>>cariIDcabang;
        address_cabang p=findelm_cabang(l,cariIDcabang);
        if(p==NULL)
        {
            cout<<"Cabang tidak ditemukan";
        }
        else
        {
            deleteafter_cabang(l,p,prec);
            cout<<"Data cabang telah terhapus berikut data karyawannya"<<endl<<endl;
            if(p==NULL)
            {
                cout<<"Data terhapus";
            }
        }
        getch();

    }

    else if (pilihan ==8)
    {
        system("CLS");
        address_cabang p;
        address_karyawan q;
        printinfo_cabang(l);
        cout<<"Masukan ID cabang dimana data karyawan ingin dihapus"<<endl<<endl;
        cin>>cariIDcabang;
        p=findelm_cabang(l,cariIDcabang);
        if(p!=NULL)
        {
            printinfo_karyawan(p,q);
            cout<<endl<<"Masukan ID karyawan yang ingin dihapus: ";
            cin>>cariIDkaryawan;
            deleteafter_karyawan(p, q, cariIDkaryawan);
            cout<<"Data telah terhapus";

        }
        getch();
    }

    else if (pilihan ==9)
    {
        system("CLS");
        printinfo_semua(l);
        getch();
    }

    else if (pilihan ==10)
    {
        system("CLS");
        cout<<"Terima Kasih"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Egriano Aristianto (1301150043)"<<endl;
        cout<<"Elza Fitria D (1301154533)"<<endl;
    }
}



}


