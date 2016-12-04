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




/*void daftar()
{
    clrscr();
    infotype_cabang x;
    cout<<"----------DAFTAR--------"<<endl;
    cout<<"ID : ";
    cin>>x.id_User;
    if (findElmcabang(LP,x) != NULL)
    {
        cout<<"ID already exist."<<endl;
        getch();
        mainMenu();
    }
    else
    {
        cout<<"   Password      : ";
        cin>>x.password;
        cout<<"   Nama      : ";
        cin>>x.nama;
        cout<<"   Email       : ";
        cin>>x.email;
        cout<<"   Phone Number  : ";
        cin>>x.no_hp;
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
                if (info(next(Q)).id_User < x.id_User)
                {
                    tempP = next(tempP);
                }
                Q = next(Q);
            }
            insertAftercabang(LP,tempP,P);
        }
        cout<<"Berhasil Terdaftar"<<endl;
        getch();
        mainMenu();
    }
}


void login()
{
    clrscr();
    infotype_cabang x;
    address_cabang P;
    cout<<"--------LOGIN---------"<<endl;
    cout<<"    ID  : ";
    cin>>x.id_User;
    cout<<"   Password  : ";
    cin>>x.password;
    P = findElmcabang(LP,x);
    if (P != NULL)
    {
        if (info(P).password == x.password)
        {
            menuUser(LP,P);
        }
        else
        {
            cout<<"Salah Password"<<endl;
            getch();
            login();
        }
    }
    else
    {
        cout<<"Id Tidak Terdaftar"<<endl;
        getch();
        mainMenu();
    }
}

void admin()
{
    string username,pass;
    cout<<"---------ADMIN--------"<<endl;
    cout<<"   Username  : ";
    cin>>username;
    cout<<"   Password  : ";
    cin>>pass;
    if (username == "admin")
    {
        if (pass == "admin123")
        {
            menuAdmin();
        }
    }
    else
    {
        cout<<"SAlah Salah Salah"<<endl;
        getch();
        mainMenu();
    }
}

void menuUser(List_cabang &L,address_cabang &P)
{
    int pil;
    //int j = 0;
    infotype_cabang x;
    infotype_karyawan XC;
    clrscr();
    cout<<"--------Menu User-------"<<endl;
    cout<<"   Welcome  "<<info(P).nama<<" ("<<info(P).id_User<<")!"<<endl;
    cout<<"   1. Lihat Tiket Tersedia"<<endl;
    cout<<"   2. Beli Tiket"<<endl;
    cout<<"   3. Lihat Transaksi"<<endl;
    cout<<"   4. Edit Profile"<<endl;
    cout<<"   5. Back"<<endl;
    cout<<"   Select: ";
    cin>>pil;
    switch (pil)
    {
    case 1 :
    {
        printInfokaryawan(LC);
        getch();
        menuUser(L,P);
        break;
    }
    case 2:
    {
        printInfokaryawan(LC);
        if (first(LC) == NULL)
        {
            cout<<"Tiket Tidak Tersedia";
            getch();
            menuUser(LP,P);
        }
        else
        {
            cout<<"Masukkan ID Tiket yg dibeli: ";
            cin>>XC.id_Tiket;
            address_karyawan C = findElmkaryawan(LC,XC);
            address_karyawan tempC = first(LC);
            address_karyawan findC;
            address_karyawan delC = C;
            insertFirstkaryawan(karyawan(P),C);
            if (first(LC) == last(LC))
            {

                deleteFirstkaryawan(LC,delC);
            }
            else
            {
                do
                {
                    if(info(next(tempC)).id_Tiket == XC.id_Tiket)
                    {
                        findC = tempC;
                    }
                    tempC = next(tempC);
                }
                while(tempC != last(LC));
                deleteAfterkaryawan(LC,findC,delC);
            }
        }
        getch();
        menuUser(L,P);
        break;
    }
    case 3:
    {
        printInfokaryawan(karyawan(P));
        getch();
        menuUser(L,P);
        break;
    }
    case 4:
        cout<<"Name: ";
        cin>>info(P).nama;
        cout<<"Password: ";
        cin>>info(P).password;
        cout<<"Email: ";
        cin>>info(P).email;
        cout<<"Phone Number: ";
        cin>>info(P).no_hp;
        cout<<"Edit Profile successful!"<<endl;
        getch();
        menuUser(L,P);
        break;
    case 5:
        mainMenu();
        break;
    }

}

void menuAdmin()
{
    int pil;
    cout<<"-------MENU ADMIN--------"<<endl;
    cout<<"   1. View User"<<endl;
    cout<<"   2. Delete User"<<endl;
    cout<<"   3. Tambah Tiket"<<endl;
    cout<<"   Pilih: ";
    cin>>pil;
    switch(pil)
    {
    case 1:
        printInfocabang(LP);
        getch();
        menuAdmin();
        break;

    case 3:
        tambahtiket();
    }
}
/*void tambahtiket()
{
    clrscr();
    infotype_karyawan P;
    infotype_karyawan x;
    cout<<"--------Tambah Tiket--------"<<endl;
    cout<<"  ID Tiket         : ";
    cin>>x.id_Tiket;
    if (findElmkaryawan(LC,x) != NULL)
        {
        cout<<"ID already exist."<<endl;
        getch();

    }
    else
    {
        cout<<"   Harga Tiket : ";
        cin>>x.harga_Tiket;
        cout<<"   Kota asal : ";
        cin>>x.kota_asal;
        cout<<"   Kota Tujuan :";
        cin>>x.kota_tujuan;
        //cout<<info(P).id_User;

        address_karyawan Q = first(LC);
        address_karyawan tempC = first(LC);
        address_karyawan C = alokasikaryawan(x);
        if (first(LC) == NULL)
        {
            insertFirstkaryawan(LC,C);
            cout<<"A";
        }

        else
        {
            cout<<"1";
            while (Q != last(LC))
            {
                cout<<"A";
                if (first(LC) == last(LC))
                {
                    cout<<"B";
                    if (info(first(LC)).id_Tiket > x.id_Tiket)
                    {
                        insertLastkaryawan(LC,C);
                    }
                    else if (info(first(LC)).id_Tiket < x.id_Tiket)
                    {
                        insertFirstkaryawan(LC,C);
                    }
                }

                else if(info(next(Q)).id_Tiket < x.id_Tiket)
                {
                    tempC = next(tempC);
                    cout<<"C";
                }
                Q = next(Q);
            }
            insertAfterkaryawan(LC,tempC,C);
        }
        getch();
        menuAdmin();
    }*/





