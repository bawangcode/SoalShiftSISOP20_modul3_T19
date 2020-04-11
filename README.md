# SoalShiftSISOP20_modul3_T19

## Nama Angggota

- Adeela Nurul Fadhila [05311840000001]
- Muhammad Zulfikar Fauzi [05311840000012]

# Nomor 1

# Nomor 2

# Nomor 3

# Nomor 4

Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri
jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap
pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan
setiap batunya memiliki warna yang berbeda.
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat
mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di
pilar tersebut. Norland menghampiri setiap pilar secara bergantian.

- __Batu mulia pertama.__ Emerald. Batu mulia yang berwarna hijau mengkilat. Pada
batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:

  1. Buatlah program C dengan nama "4a.c", yang berisi program untuk
melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
  2. Tampilkan matriks hasil perkalian tadi ke layar.
  
- __Batu kedua__ adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya
adalah:

  1. Buatlah program C kedua dengan nama "4b.c". Program ini akan
mengambil variabel hasil perkalian matriks dari program "4a.c" (program
sebelumnya), dan tampilkan hasil matriks tersebut ke layar.
(Catatan!: gunakan shared memory)
  2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan format seperti matriks.

    Contoh: misal array [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...],

    maka:

    1 2 6 24
    120 720 ... ...
    ...

    (__Catatan!__ : Harus menggunakan Thread dalam penghitungan faktorial)

- __Batu ketiga__ adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan
teka-teki berikut!

  1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak
memiliki hubungan terhadap program yang lalu.
  2. Pada program ini, Norland diminta mengetahui jumlah file dan
folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
IPC, Norland mengerjakannya dengan semangat.

  (__Catatan!__ : Harus menggunakan IPC Pipes)

Begitu batu terakhir berhasil didapatkan. Gemuruh yang semakin lama semakin
besar terdengar. Seluruh tempat berguncang dahsyat, tanah mulai merekah. Sebuah
batu yang di atasnya terdapat kotak kayu muncul ke atas dengan sendirinya.

Sementara batu tadi kembali ke posisinya. Tanah kembali menutup, seolah tidak
pernah ada lubang merekah di atasnya satu detik lalu.
Norland segera memasukkan tiga buah batu mulia Emerald, Amethys, Onyx pada
Peti Kayu. Maka terbukalah Peti Kayu tersebut. Di dalamnya terdapat sebuah harta
karun rahasia. Sampai saat ini banyak orang memburu harta karun tersebut.
Sebelum menghilang, dia menyisakan semua petunjuk tentang harta karun tersebut
melalui tulisan dalam buku catatannya yang tersebar di penjuru dunia. "One Piece
does exist".

#### Link code soal 4 :

##### Soal 4a : [shift4a](https://github.com/bawangcode/SoalShiftSISOP20_modul3_T19/blob/master/soal4/soal4a.c)

##### Soal 4c : [shift4c](https://github.com/bawangcode/SoalShiftSISOP20_modul3_T19/blob/master/soal4/soal4c.c)

**Pembahasan**\

#### 4a.
``` c
int matrixA[4][2];
int matrixb[2][5];
int matrixc[4][5];
```
- Pertama deklarasikan dulu matriks sesuai yang diinginkan soal.
``` c
void* buat_kali(void* arg) {
  if(kolom >= 5){
    kolom = 0;
    baris++;
  }
  for(int i = 0; i < 2;i++){
    matrixc[baris][kolom] += matrixA[baris][i] * matrixb[i][kolom];
  }
  kolom++;
}
```
- Rumuskan fungsi untuk perkalian matriks.
``` c
srand(time(NULL));
  printf("Matrix A : \n");
  for (int i = 0; i < 4; i++) {
    /* code */
    for (int j = 0; j < 2; j++) {
      matrixA[i][j] = rand()%19+1;
      printf("%2d", matrixA[i][j]);
      /* code */
    }
    printf("\n");
  }
```
- __srand(time(NULL));__ digunakan untuk mengenerate random number.
- Lalu kita gunakan 2 perulangan untuk mengisi matriks A menggunakan __rand()%19+1__, random berfungsi untuk menghasilkan angka random dengan batas angka 1-20 ( __%19+1__).
- Lakukan hal yang sama pada matriks B.
``` c
 pthread_t tid[20];

  for (int i = 0; i < 20; i++) {
    /* code */
    pthread_create(&(tid[i]), NULL, &buat_kali, NULL);
  }
  
  for (int i = 0; i < 20; i++) {
    /* code */
    pthread_join(tid[i], NULL);
  }
```
- Setelah itu kita deklarasikan thread.
- Kita gunakan perulangan untuk menjalankan fungsi __pthread_create__ dengan syntax untuk menjalankan fungsi perkalian tadi.
- Setelah itu kita lakukan __pthread_join()__ untuk masing - masing thread agar __main()__ tidak berhenti sebelum masing - masing thread selesai prosesnya.
``` c
printf("Hasil kali A dan B :\n");
  for (int i = 0; i < 4; i++) {
    /* code */
    for (int j = 0; j < 5; j++) {
      printf("%4d", matrixc[i][j]);
      /* code */
    }
    printf("\n");
  }
```
- Setelah perkalian selesai maka kita tampilkan matriks C menggunakan perulangan.

#### 4c.
``` c
int deskriptor[2];
  pid_t pid;
  pipe(deskriptor);
```
- Pertama - tama kita buat variabel array berdasarkan jumlah pipe yang kita perlukan,. dalam kasus ini karena kita hanya perlu 1 pipe maka __\[2]__ cukup. Lakukan fungsi pipe pada variabel tersebut.
``` c
if (pid == 0) {
    dup2(deskriptor[1], 1);
    close(deskriptor[0]);
    close(deskriptor[1]);
    char *argv[] = {"ls", NULL};
    execv("/bin/ls", argv);
    }
```
- Proses pertama, kita lakukan __ls__ menggunakan __execv()__. Agar output dari execv masuk dalam pipe kita gunakan fungsi __dup2__.
- __dup2__ berfungsi untuk menyamakan isi dari 2 yang disebut, __deskriptor\[1]__ dan __1__. 1 disini adalah STDOUT ( output yang mengarah ke terminal ) sedangkan __deskriptor\[1]__ adalah lubang output dari pipe kita.
- Maka hasil dari ls akan masuk ke dalam pipe.
``` c
if (pid == 0) {
    dup2(deskriptor[0], 0);
    close(deskriptor[0]);
    close(deskriptor[1]);
    char *argv[] = {"wc", "-l", NULL};
    execv("/usr/bin/wc", argv);
  }
```
- Lalu untuk proses selanjutnya kita ambil output dari __ls__ dari pipe kita gunakan sebagai input untuk fungsi __wc__ yang akan dijalankan menggunakan __execv__.
- Caranya adalah melakukan __dup2__ pada __deskriptor\[0]__ dan __0__. 0 disini adalah STDIN atau input. __deskriptor\[0]__ adalah lubang input dari pipe.
- Setelah itu karena outputnya default ( STDOUT ) maka hasil dari dc akan ditampilkan pada terminal.
