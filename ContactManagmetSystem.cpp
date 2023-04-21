#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;


class contact

{

    private:

    char fName[20]; // First Name
    char lName[20]; // Last Name
    char address[50]; // Address
    char email[30]; // Email

    long long phoneNo; // Telefon Numarasi

    public:

    void BilgileriGir()

    {

        cout<<"Birinci Adinizi Giriniz: ";
        cin>>fName;

        cout<<"Soyadinizi Giriniz: ";
        cin>>lName;

        cout<<"Adresinizi Giriniz: ";
        cin>>address;

        cout<<"Emailinizi Giriniz: ";
        cin>>email;
        
        cout<<"Telefon Numaranizi Giriniz: ";
        cin>>phoneNo;


    }

    void BilgileriYazdir()

    {

        cout<<"Birinci Ad: "<<fName<<endl;
        cout<<"Soyad: "<<lName<<endl;
        cout<<"Adres: "<<address<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Telefon Numarasi: "<<phoneNo<<endl;

    }

    void DosyayaYazdir()

    {

        char ch;    // Dosya sonuna kadar okuma yapmak icin
        ofstream f1; // Dosya yazma islemi icin
        f1.open("contact.dat",ios::binary | ios::app); // Dosya acma islemi

        do 

        {

            BilgileriGir();
            f1.write((char*)this,sizeof(*this)); // Dosyaya yazma islemi
            cout<<"Baska bir kayit yapmak istiyor musunuz? (E/H): ";
            cin>>ch;

        } 
        
        while (ch == 'E' || ch == 'e');

        cout<<"Kayitlar Dosyaya Yazildi."<<endl;
        f1.close(); // Dosya kapatma islemi
        
    }

    void DosyaOkuma()

    {

        ifstream f2;
        f2.open("contact.dat",ios::binary); // Dosya acma islemi

        cout<<"\n______________________________________________________\n";
        cout<<"BILGILER LISTELENIYOR...";
        cout<<"\n______________________________________________________\n";

        while (!f2.eof()) // dosya sonuna kadar okuma yapma islemi!

        {

            if (f2.read((char*)this,sizeof(*this))) // Dosyadan okuma islemi
            {

                BilgileriYazdir();
                cout<<"\n______________________________________________________\n";

            }

        }

        f2.close(); // Dosya kapatma islemi

    }

    void DosyalariArama()

    {


        ifstream f3;
        long long phone;
        cout<<"Aramak istediginiz telefon numarasini giriniz: ";
        cin>>phone;

        f3.open("contact.dat",ios::binary); // Dosya acma islemi

        while (!f3.eof())

        {

            if(f3.read((char*)this,sizeof(*this)))

            {

                if (phone == phoneNo)

                {

                    
                    BilgileriYazdir();
                    return ;
                    
                }

            }
            
        }

        cout<<"\nKayit Bulunamadi!";
        f3.close(); // Dosya kapatma islemi

    }

    void DosyaSilme()

    {

        long long phone;
        int sayac = 0;

        ofstream f4;
        ifstream f5;

        f5.open("contact.dat",ios::binary); // Dosya acma islemi
        f4.open("temp.dat",ios::binary); // Dosya acma islemi

        cout<<"Silmek istediginiz telefon numarasini giriniz: ";
        cin>>phone;

        while (!f5.eof())

        {

            if (f5.read((char*)this,sizeof(*this)))

            {

                if (phoneNo != phone)

                {
                        
                    f4.write((char*)this,sizeof(*this));

                }
                
               else sayac = 1;

                }


                }

                f5.close(); // Dosya kapatma islemi
                f4.close(); // Dosya kapatma islemi

                remove("contact.dat"); // Dosya silme islemi
                rename("temp.dat","contact.dat"); // Dosya ismini degistirme islemi

                sayac == 1 ? cout<<"\nKayit Silindi!" : cout<<"\nKayit Bulunamadi!";

            }

            void bilgileriDuzenle()

            {

                long long phone;
                fstream f6;

                cout<<"Bilgileri Duzenle:";
                cout<<"\n______________________________________________________\n";
                cout<<"Duzenlemek istediginiz telefon numarasini giriniz: ";
                cin>>phone;

                f6.open("contact.dat",ios::binary | ios::in | ios::out); // Dosya acma islemi

                while (!f6.eof())

                {

                    if(f6.read((char*)this,sizeof(*this)))

                    {

                        if (phoneNo == phone)

                        {

                            cout<<"Yeni Kayitlari Giriniz:";
                            BilgileriYazdir();
                        
                            int pos = -1 * sizeof(*this);
                            f6.seekp(pos,ios::cur);
                            f6.write((char*)this,sizeof(*this));
                            cout<<"\nKayit Guncellendi!";
                            return ;

                        }

                    }


                    
                }

                cout<<"\nKayit Bulunamadi!";
                f6.close(); // Dosya kapatma islemi

    }

};

int main()

{
   
   system("cls");
   system("color 3F");

   cout<<"\n\n\n\n\n KISI KAYIT SISTEMI";
   getch();
  
   while(1)

   {

    contact c1;
    int secim;

    system("cls");
    system("color 03");

    cout<<"\nKISI KAYIT SISTEMI";
    cout<<"\nMENU";
    cout<<"\n______________________________________________________\n";
    cout<<"[1] Kayit Ekle";
    cout<<"\n[2] Kayitlari Listele";
    cout<<"\n[3] Kayitlari Arama";
    cout<<"\n[4] Kayitlari Sil";
    cout<<"\n[5] Kayitlari Duzenle";
    cout<<"\n[6] Cikis";
    cout<<"\n______________________________________________________\n";
    cout<<"Seciminiz: ";
    cin>>secim;

    switch (secim)

    {

        case 1: 

        system("cls");
        c1.DosyayaYazdir();
        break;

        case 2: 
        
        system("cls");
        c1.DosyaOkuma();
        break;

        case 3: 
       
        system("cls");
        c1.DosyalariArama();
        break;

        case 4: 

        system("cls");
        c1.DosyaSilme();
        break;

        case 5: 

        system("cls");
        c1.bilgileriDuzenle();
        break;

        case 6: 
        
        system("cls");
        cout<<"\nProgramdan Cikiliyor..."<<endl;
        exit(0);
        break;

        default: 

        cout<<"\nHatali Secim!";
        continue;


    }

    int secim2;
    cout<<"\n\n[1] Ana Menuye Don";
    cout<<"\n[2] Cikis";
    cout<<"\nSeciminiz: ";
    cin>>secim2;

    switch(secim2)

    {

        case 1: 

        system("cls");
        break;

        case 2: 

        system("cls");
        cout<<"\nProgramdan Cikiliyor..."<<endl;
        exit(0);
        break;

        default: 

        cout<<"\nHatali Secim!";
        continue;


    }

   }

   return 0;

}