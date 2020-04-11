#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

int matrixA[4][2];
int matrixb[2][5];
int matrixc[4][5];

int baris = 0;
int kolom = 0;

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

int main() {
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

  printf("Matrix B : \n");
  for (int i = 0; i < 2; i++) {
    /* code */
    for (int j = 0; j < 5; j++) {
      /* code */
      matrixb[i][j] = rand()%19+1;
      printf("%2d", matrixb[i][j]);
    }
    printf("\n");
  }

  pthread_t tid[20];

  for (int i = 0; i < 20; i++) {
    /* code */
    pthread_create(&(tid[i]), NULL, &buat_kali, NULL);
  }

  for (int i = 0; i < 20; i++) {
    /* code */
    pthread_join(tid[i], NULL);
  }


  printf("Hasil kali A dan B :\n");
  for (int i = 0; i < 4; i++) {
    /* code */
    for (int j = 0; j < 5; j++) {
      printf("%4d", matrixc[i][j]);
      /* code */
    }
    printf("\n");
  }

    return 0;
}
