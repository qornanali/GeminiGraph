/*
Nama file : scene.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT untuk mendefinisikan aksi callback yang didapat saat menjalankan Freeglut pada suatu event tertentu
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __SCENE_H__
#define  __SCENE_H__

/* Method callback yang dipanggil freeglut saat inisiasi sudah selesai dan akan menampilkan objek. */
void onWorldDisplay();

/* Method callback yang dipanggil freeglut saat tidak ada event callback lain yang berjalan. */
void onWorldIdle();

/* Method callback yang dipanggil freeglut saat window berubah ukuran. */
void onWorldReshape(int w, int h); 

/* Method callback yang dipanggil freeglut saat ada key special yang ditekan oleh pengguna. */
void onSpecialKeyClicked(int key, int x, int y ); 

/* Method callback yang dipanggil freeglut saat ada normal key yang ditekan oleh pengguna */
void onNormalKeyClicked(unsigned char key, int x, int y);

/* Method callback yang dipanggil freeglut saat pengguna menahan klik pada tombol mouse dan melakukan pergerakan mouse */
void onMotionMouseClicked(int x, int y);

/* Method callback yang dipanggil freeglut saat pengguna mengklik tombol mouse. */
void onButtonMouseClicked(int button, int state, int x, int y);

/* Method callback yang dipanggil freeglut ketika mouse bergerak secara pasif di window. */
void onPassiveMouseActived(int x, int y);



#endif
