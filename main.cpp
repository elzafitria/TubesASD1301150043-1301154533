#include <iostream>

#include "tubes.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

List_cabang LP;
List_karyawan LC;
address_karyawan AC;
address_cabang AP;
infotype_cabang XP;
infotype_karyawan XC;

void mainMenu();
void clrscr();
void daftar();
void login();
void admin();
void menuUser(List_cabang &L,address_cabang &P);
void menuAdmin();
void tambahtiket();

int main()
{
    createListcabang(LP);
    createListkaryawan(LC);
    int pil=0;
    while(pil!=10)
    {
        system("CLS");
        int pil;
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
        cin>>pil;
        {
        if(pil==1)
            {
            /*daftar();
            break;*/
                system("CLS");
                infotype_cabang x;
                cout<<"Cek kesediaan ID yang ingin dibuat"<<endl;
                cout<<"ID : ";
                cin>>x.id_cabang;
                if (findElmcabang(LP,x) != NULL)
                {
                    cout<<"ID sudah ada"<<endl;
                    getch();
                }
                else
                {
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
                    address_cabang Q = first(LP);
                    address_cabang tempP = first(LP);
                    address_cabang P = alokasicabang(x);
                    if (first(LP) == NULL)
                    {
                        insertFirstcabang(LP,P);
                    }
                    else
                    {
                        while (next(Q) != first(LP))
                        {
                            if (info(next(Q)).id_cabang < x.id_cabang)
                            {
                                tempP = next(tempP);
                            }
                            Q = next(Q);
                        }
                        insertAftercabang(LP,tempP,P);
                    }
                    cout<<"Data berhasil diinput"<<endl;
                    cout<<"---------------------"<<endl<<endl;
                    getch();
                }
            }
        else if (pil==2)
            /*login();
            break;*/
            {
                system("CLS");
                infotype_karyawan P;
                infotype_karyawan x;
                cout<<"Cek ID Karyawan"<<endl;
                cout<<"ID Karyawan: ";
                cin>>x.id_karyawan;
                if (findElmkaryawan(LC,x) != NULL)
                    {
                        cout<<"ID Sudah ada"<<endl;
                        getch();

                    }
                else
                    {
                        cout<<"ID KARYAWAN          : ";
                        cin>>x.id_karyawan;
                        cout<<"NAMA KARYAWAN        : ";
                        cin>>x.nama_karyawan;
                        cout<<"JABATAN KARYAWAN     : ";
                        cin>>x.jabatan_karyawan;
                        cout<<"TGL LAHIR KARYAWAN   : ";
                        cin>>x.tgl_lahir;
                        cout<<"ALAMAT KARYAWAN      : ";
                        cin>>x.alamat;

                        /*address_karyawan Q = first(LC);
                        address_karyawan tempC = first(LC);
                        address_karyawan C = alokasikaryawan(x);*/
                        if (first(LC) == NULL)
                        {
                            insertFirstkaryawan(LC,AC);
                        }

                        /*else
                        {
                            while (Q != last(LC))
                            {
                                if (first(LC) == last(LC))
                                {
                                    if (info(first(LC)).id_karyawan > x.id_karyawan)
                                    {
                                        insertLastkaryawan(LC,C);
                                    }
                                    else if (info(first(LC)).id_karyawan < x.id_karyawan)
                                    {
                                        insertFirstkaryawan(LC,C);
                                    }
                                }

                                else if(info(next(Q)).id_karyawan < x.id_karyawan)
                                {
                                    tempC = next(tempC);

                                }
                                Q = next(Q);
                            }
                            insertAfterkaryawan(LC,tempC,C);
                        }
                        getch();*/
                    }
            }
        else if (pil==3)
            {
            /*admin();
            break;*/
                infotype_cabang x;
                system("CLS");
                cout<<"Masukan ID cabang yang ingin dicari: ";
                cin>>x.id_cabang;
                cout<<"====================================";
                cout<<endl;
                if (findElmcabang(LP,x) != NULL)
                    {
                        printInfocabang(LP);
                        /*cout<<"ID CABANG:           : ";
                        cout<<x.id_cabang;
                        cout<<endl;
                        cout<<"NAMA CABANG          : ";
                        cout<<x.nama_cabang;
                        cout<<endl;
                        cout<<"ALAMAT CABANG        : ";
                        cout<<x.alamat_cabang;
                        cout<<endl;
                        cout<<"KOTA CABANG          : ";
                        cout<<x.kota_cabang;
                        cout<<endl;
                        cout<<"NAMA KEPALA CABANG   : ";
                        cout<<x.kepala_cabang;
                        cout<<endl;*/
                    }
                else
                {
                    cout<<"Data tidak ditemukan";
                }
                getch();
            }
        else if (pil==4)
            {
            /*exit(10);
            break;*/
                system("CLS");
                infotype_karyawan x;
                cout<<"Masukan ID karyawan yang ingin dicari: ";
                cin>>x.id_karyawan;
                cout<<"====================================";
                if (findElmkaryawan(LC,x) != NULL)
                    {
                        cout<<"ID KARYAWAN          : ";
                        cout<<x.id_karyawan;
                        cout<<endl;
                        cout<<"NAMA KARYAWAN        : ";
                        cout<<x.nama_karyawan;
                        cout<<endl;
                        cout<<"JABATAN KARYAWAN     : ";
                        cout<<x.jabatan_karyawan;
                        cout<<endl;
                        cout<<"TGL LAHIR KARYAWAN   : ";
                        cout<<x.tgl_lahir;
                        cout<<endl;
                        cout<<"ALAMAT KARYAWAN      : ";
                        cout<<x.alamat;
                        cout<<endl;
                    }
                else
                {
                    cout<<"Data tidak ditemukan";
                }
                getch();
            }
        else if (pil==5)
            {

                system("CLS");
                infotype_cabang x;
                cout<<"Masukan ID cabang yang ingin diedit: ";
                cin>>x.id_cabang;
                cout<<"======================================";
                if (findElmcabang(LP,x) != NULL)
                {
                    cout<<"ID CABANG:           : ";
                    cin>>x.id_cabang;
                    cout<<endl;
                    cout<<"NAMA CABANG          : ";
                    cin>>x.nama_cabang;
                    cout<<endl;
                    cout<<"ALAMAT CABANG        : ";
                    cin>>x.alamat_cabang;
                    cout<<endl;
                    cout<<"KOTA CABANG          : ";
                    cin>>x.kota_cabang;
                    cout<<endl;
                    cout<<"NAMA KEPALA CABANG   : ";
                    cin>>x.kepala_cabang;
                    cout<<endl;
                    cout<<"====================="<<endl;
                    cout<<"Data telah diedit";
                }
                else
                    cout<<"Data tidak ditemukan";
                getch();
            }

        else if (pil==6)
            {
                system("CLS");
                infotype_karyawan x;
                cout<<"Masukan ID karyawan yang ingin diedit: ";
                cin>>x.id_karyawan;
                cout<<"====================================";
                if (findElmkaryawan(LC,x) != NULL)
                    {
                        cout<<"ID KARYAWAN          : ";
                        cin>>x.id_karyawan;
                        cout<<endl;
                        cout<<"NAMA KARYAWAN        : ";
                        cin>>x.nama_karyawan;
                        cout<<endl;
                        cout<<"JABATAN KARYAWAN     : ";
                        cin>>x.jabatan_karyawan;
                        cout<<endl;
                        cout<<"TGL LAHIR KARYAWAN   : ";
                        cin>>x.tgl_lahir;
                        cout<<endl;
                        cout<<"ALAMAT KARYAWAN      : ";
                        cin>>x.alamat;
                        cout<<endl;
                        cout<<"====================="<<endl;
                        cout<<"Data telah diedit";
                    }
                else
                {
                    cout<<"Data tidak ditemukan";
                }
            }
        else if (pil==7)
        {
            system("CLS");
            printInfocabang(LP);
            infotype_cabang x;
            if (first(LP)==NULL)
            {
                cout<<"Data tidak ada"<<endl;
                getch();
            }
            else
            {
                cout<<"Input ID cabang: ";
                cin>>x.id_cabang;
                address_cabang tempP = first(LP);
                if(findElmcabang(LP,x)==NULL)
                {
                    cout<<"ID tidak ada"<<endl;
                    getch();
                }
                else
                {
                    address_cabang P = findElmcabang(LP,x);
                    if(P==first(LP))
                    {
                        deleteFirstcabang(LP,P);
                    }
                    else if(next(P)==first(LP))
                    {
                        deleteLastcabang(LP,P);
                    }
                    else
                    {
                        do
                        {
                            if(next(tempP)==P)
                            {
                                deleteAftercabang(LP,tempP,P);
                            }
                            tempP=next(tempP);
                        }while(P!=first(LP));
                    }
                }
                cout<<"Cabang telah terhapus"<<endl;
                getch();
            }

        }

        else if (pil==8)
        {
            printInfokaryawan(LC);
            if(first(LC)==NULL)
            {
                cout<<"Data tidak tersedia";
                getch();
            }
            else
            {
                cout<<"Masukan ID karyawan: ";
                cin>>XC.id_karyawan;
                address_karyawan C = findElmkaryawan(LC,XC);
                address_karyawan tempC = first(LC);
                address_karyawan findC;
                address_karyawan delC=C;
                if(C==first(LC))
                {
                    deleteFirstkaryawan(LC,delC);
                }
                else if (C==last(LC))
                {
                    deleteLastkaryawan(LC,C);
                }
                else
                {
                    while(tempC != last(LC))
                    {
                        if (next(tempC)==C)
                        {
                            deleteAfterkaryawan(LC,tempC,C);
                        }
                        tempC=next(tempC);
                    }
                }
            }
            getch();
        }

        else if (pil==9)
        {
            system("CLS");
            printInfocabang(LP);
            getch();
            /*AP = first(LP);
            infotype_cabang x;
            while (AP!=NULL)
            {
                    cout<<"ID CABANG:           : ";
                    cout<<x.id_cabang;
                    cout<<endl;
                    cout<<"NAMA CABANG          : ";
                    cout<<x.nama_cabang;
                    cout<<endl;
                    cout<<"ALAMAT CABANG        : ";
                    cout<<x.alamat_cabang;
                    cout<<endl;
                    cout<<"KOTA CABANG          : ";
                    cout<<x.kota_cabang;
                    cout<<endl;
                    cout<<"NAMA KEPALA CABANG   : ";
                    cout<<x.kepala_cabang;
                    cout<<endl;
                    cout<<"---------------------------"<<endl;
                    cout<<endl;
                    printInfokaryawan(LC);
                    cout<<endl;
                    AP=next(AP);
            }*/

        }
        else if (pil==10)
        {
            system("CLS");
            cout<<"Terima Kasih"<<endl;
            cout<<"---------------------------"<<endl;
            cout<<"Egriano Aristianto (1301150043)"<<endl;
            cout<<"Elza Fitria D (1301154533)"<<endl;
        }
    }



    }
    return 0;
}
