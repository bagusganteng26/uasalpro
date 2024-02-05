#include <stdio.h>
#include <string.h>

struct Barang {
  char kode[10];
  char nama[50];
  int jumlah;
  double harga;
};

int findBarangIndex(struct Barang inventaris[], int n, char kodeCari[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(inventaris[i].kode, kodeCari) == 0) {
      return i;
    }
  }
  return -1; // Return -1 if not found
}

void tambahBarang(struct Barang inventaris[], int *n) {
  // Kode untuk menambahkan barang
  printf("Masukkan kode barang: ");
  scanf("%s", inventaris[*n].kode);
  printf("Masukkan nama barang: ");
  scanf(" %[^\n]s", inventaris[*n].nama);
  printf("Masukkan jumlah barang: ");
  scanf("%d", &inventaris[*n].jumlah);
  printf("Masukkan harga barang: ");
  scanf("%lf", &inventaris[*n].harga);

  (*n)++;
}

void cariBarang(struct Barang inventaris[], int n) {
  // Kode untuk mencari barang
  char kodeCari[10];
  printf("Masukkan kode barang yang dicari: ");
  scanf("%s", kodeCari);

  int index = findBarangIndex(inventaris, n, kodeCari);
  if (index != -1) {
    printf("Barang ditemukan:\n");
    printf("Kode: %s\n", inventaris[index].kode);
    printf("Nama: %s\n", inventaris[index].nama);
    printf("Jumlah: %d\n", inventaris[index].jumlah);
    printf("Harga: %.2lf\n", inventaris[index].harga);
  } else {
    printf("Barang tidak ditemukan.\n");
  }
}

void updateBarang(struct Barang inventaris[], int n) {
  // Kode untuk update barang
  char kodeUpdate[10];
  printf("Masukkan kode barang yang akan diupdate: ");
  scanf("%s", kodeUpdate);

  int index = findBarangIndex(inventaris, n, kodeUpdate);
  if (index != -1) {
    printf("Masukkan data baru:\n");
    printf("Nama barang: ");
    scanf(" %[^\n]s", inventaris[index].nama);
    printf("Jumlah barang: ");
    scanf("%d", &inventaris[index].jumlah);
    printf("Harga barang: ");
    scanf("%lf", &inventaris[index].harga);

    printf("Barang berhasil diupdate.\n");
  } else {
    printf("Barang tidak ditemukan.\n");
  }
}

void hapusBarang(struct Barang inventaris[], int *n) {
  // Kode untuk hapus barang
  char kodeHapus[10];
  printf("Masukkan kode barang yang akan dihapus: ");
  scanf("%s", kodeHapus);

  int index = findBarangIndex(inventaris, *n, kodeHapus);
  if (index != -1) {
    // Pindahkan elemen terakhir ke posisi yang akan dihapus
    inventaris[index] = inventaris[(*n) - 1];
    (*n)--;
    printf("Barang berhasil dihapus.\n");
  } else {
    printf("Barang tidak ditemukan.\n");
  }
}

void tampilBarang(struct Barang inventaris[], int n) {
  // Kode untuk menampilkan semua barang
  printf("Daftar Barang:\n");
  for (int i = 0; i < n; i++) {
    printf("Kode: %s\n", inventaris[i].kode);
    printf("Nama: %s\n", inventaris[i].nama);
    printf("Jumlah: %d\n", inventaris[i].jumlah);
    printf("Harga: %.2lf\n", inventaris[i].harga);
    printf("------------------------------\n");
  }
}

int main() {
  struct Barang inventaris[100];
  int n = 0;

  while (1) {
    int menu;

    printf("Menu:\n");
    printf("1. Tambah Barang\n");
    printf("2. Cari Barang\n");
    printf("3. Update Barang\n");
    printf("4. Hapus Barang\n");
    printf("5. Tampil Barang\n");
    printf("6. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        tambahBarang(inventaris, &n);
        break;
      case 2:
        cariBarang(inventaris, n);
        break;
      case 3:
        updateBarang(inventaris, n);
        break;
      case 4:
        hapusBarang(inventaris, &n);
        break;
      case 5:
        tampilBarang(inventaris, n);
        break;
      case 6:
        printf("Terima kasih");
        return 0; // Keluar dari program
      default:
        printf("Menu tidak valid. Silakan pilih menu lain.\n");

    }
  }

  return 0;
}
