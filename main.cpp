#include <iostream>
#include <string>

using namespace std;

class Contact{
    public:
        Contact() : namaKontak(""), nomorTelepon("") {}

        Contact(string inputKontak, string inputNomor){
            Contact::namaKontak = inputKontak;
            Contact::nomorTelepon = inputNomor; 
        }

        string getNamaKontak(){
            return namaKontak;
        }

        string getNomorTelepon(){
            return nomorTelepon;
        }

        void displayInfoKontak(){
            cout << "Nama Kontak: " << namaKontak << endl;
            cout << "Nomor Telepon: " << nomorTelepon << endl;
        }

        void displayNamaKontak(){
            cout << "Nama Kontak: " << namaKontak << endl;
        }

    private:
        string namaKontak;
        string nomorTelepon;
};

class PhoneBook{
    public:
        PhoneBook() : jumlah(0) {};

        void addKontak(string inputNama, string inputNomor){  
            if (jumlah < 8) {  
                daftarKontak[jumlah] = Contact(inputNama, inputNomor);  
                jumlah++;  
                cout << "Kontak berhasil ditambahkan." << endl;  
            }else{  
                cout << "Batas kontak sudah tercapai. Kontak terlama akan diganti." << endl;    
                for (int i = 1; i < 8; i++) {  
                    daftarKontak[i - 1] = daftarKontak[i];  
                }  
                daftarKontak[7] = Contact(inputNama, inputNomor);
                cout << "Kontak terlama dihapus." << endl;  
            }  
        }  

        void displayDaftarKontak(){
            for(int i = 0; i < jumlah; i++){
                daftarKontak[i].displayNamaKontak();
            }
        }

        void searchKontak(string inputNama) {  
            for (int i = 0; i < jumlah; i++) {  
                if (daftarKontak[i].getNamaKontak() == inputNama) {  
                    daftarKontak[i].displayInfoKontak();  
                    return;  
                }  
            }  
            cout << "Kontak tidak ditemukan." << endl;  
        }  
    private:
        Contact daftarKontak[8];
        int jumlah;
};

int main(int argc, char const *argv[]){
    PhoneBook phoneBook;  
    int pilihan;  
  
    do {  
        cout << "Silahkan input angka dengan perintah berikut:" << endl;  
        cout << "1. ADD" << endl;  
        cout << "2. SEARCH" << endl;  
        cout << "3. EXIT" << endl;  
  
        cout << "Masukkan angka: ";  
        cin >> pilihan;  
  
        if (pilihan == 1) {  
            string nama, nomor;  
            cout << "Masukkan nama kontak: ";  
            cin >> nama;  
            cout << "Masukkan nomor telepon: ";  
            cin >> nomor;  
            phoneBook.addKontak(nama, nomor);  
        } else if (pilihan == 2) {  
            string nama;
            phoneBook.displayDaftarKontak();  
            cout << "Masukkan nama kontak yang dicari: ";  
            cin >> nama;  
            phoneBook.searchKontak(nama);  
        } else if (pilihan == 3) {  
            cout << "Keluar dari program." << endl;  
        } else {  
            cout << "Hanya bisa input angka 1, 2, atau 3" << endl;  
        }  
    } while (pilihan != 3);  
  
    return 0; 
}
