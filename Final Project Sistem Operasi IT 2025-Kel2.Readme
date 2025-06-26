# Final Project Sistem Operasi IT

## Peraturan
1. Waktu pengerjaan dimulai hari Kamis (19 Juni 2025) setelah soal dibagikan hingga hari Rabu (25 Juni 2025) pukul 23.59 WIB.
2. Praktikan diharapkan membuat laporan penjelasan dan penyelesaian soal dalam bentuk Readme(github).
3. Format nama repository github “Sisop-FP-2025-IT-[Kelas][Kelompok]” (contoh:Sisop-FP-2025-IT-A01).
4. Setelah pengerjaan selesai, seluruh source code dan semua script bash, awk, dan file yang berisi cron job ditaruh di github masing - masing kelompok, dan link github dikumpulkan pada form yang disediakan. Pastikan github di setting ke publik.
5. Commit terakhir maksimal 10 menit setelah waktu pengerjaan berakhir. Jika melewati maka akan dinilai berdasarkan commit terakhir.
6. Jika tidak ada pengumuman perubahan soal oleh asisten, maka soal dianggap dapat diselesaikan.
7. Jika ditemukan soal yang tidak dapat diselesaikan, harap menuliskannya pada Readme beserta permasalahan yang ditemukan.
8. Praktikan tidak diperbolehkan menanyakan jawaban dari soal yang diberikan kepada asisten maupun praktikan dari kelompok lainnya.
9. Jika ditemukan indikasi kecurangan dalam bentuk apapun di pengerjaan soal final project, maka nilai dianggap 0.
10. Pengerjaan soal final project sesuai dengan modul yang telah diajarkan.

## Kelompok x

Nama | NRP
--- | ---
Salomo | 502722063
Muhammad Fatihul Qolbi Ash Shiddiqi | 5027241023
Rayhan Agnan Kusuma | 5027241092
Muhammad Ahsani Taqwiim Rakhman | 5027241099

## Deskripsi Soal

Signal Interceptor
Buat program dimana ketika Ctrl+C (SIGINT), Ctrl+Z (SIGTSTP), atau kill (SIGKILL) akan menunjukkan pesan khusus untuk demonstrasi cara kerja signal, tambahkan demonstrasi SIGNAL sebanyak mungkin.

### Catatan

- Program ini dibuat untuk mendemonstrasikan bagaimana proses dapat menangkap dan menangani berbagai sinyal yang dikirim oleh sistem operasi atau user.  
- SIGKILL tidak dapat diintercept oleh program, sehingga program akan menampilkan pesan bahwa sinyal ini tidak dapat ditangani secara custom.  
- Selain SIGINT, SIGTSTP, dan SIGKILL, program juga meng-handle sinyal lain seperti SIGQUIT, SIGTERM, SIGUSR1, SIGUSR2, SIGALRM, SIGPIPE, SIGCHLD, dan SIGCONT sebagai demonstrasi tambahan.  
- Program menggunakan fungsi `signal()` dari pustaka `<signal.h>` untuk mendaftarkan handler sinyal.  
- Program berjalan terus menerus hingga dihentikan dengan sinyal yang tidak bisa diintercept (misal: SIGKILL) atau perintah `kill -9`.  
- Struktur repository mengikuti standar yang telah ditentukan agar mudah di-maintain dan dikembangkan.
  
Struktur repository:
```
signal-interceptor/          ← root repo
├── src/                     ← semua kode sumber
│   └── signal_interceptor.c
├── bin/                     ← hasil kompilasi (binaries)
│   └── signal_interceptor
├── Makefile                 ← rules untuk build & clean
├── README.md                ← dokumentasi singkat cara pakai
└── .gitignore               ← file/dir yang tidak di–tracking Git
```

## Pengerjaan

### Poin 1: Menangani Sinyal SIGINT (Ctrl+C), SIGTSTP (Ctrl+Z), dan SIGKILL

#### Teori

Sinyal adalah mekanisme komunikasi asinkron yang digunakan sistem operasi untuk mengirim notifikasi ke proses. SIGINT dan SIGTSTP merupakan sinyal yang dikirim dari terminal ketika pengguna menekan Ctrl+C dan Ctrl+Z. SIGKILL adalah sinyal terminasi paksa yang tidak dapat ditangani atau diabaikan oleh proses.

#### Solusi

- Program mendaftarkan handler khusus untuk SIGINT dan SIGTSTP menggunakan fungsi `signal()`.  
- Ketika sinyal diterima, program mencetak pesan khusus yang menjelaskan sinyal tersebut dan tidak langsung menghentikan proses.  
- Untuk SIGKILL, program tidak bisa mendaftarkan handler karena sifat sinyal ini yang tidak bisa diintercept. Program akan menampilkan pesan di awal bahwa SIGKILL tidak dapat ditangani secara custom.  

### Poin 2: Demonstrasi Penanganan Sinyal Lainnya

#### Teori

Selain sinyal utama, ada banyak sinyal lain yang bisa dikirim ke proses, seperti SIGQUIT (Ctrl+\\), SIGTERM (kill default), SIGUSR1 dan SIGUSR2 (sinyal khusus pengguna), SIGALRM (timer alarm), SIGPIPE (penulisan ke pipe tanpa pembaca), SIGCHLD (perubahan status proses anak), dan SIGCONT (melanjutkan proses yang dihentikan).

#### Solusi

- Program mendaftarkan handler untuk sinyal-sinyal tersebut dan mencetak pesan yang sesuai saat sinyal diterima.  
- Sebagai contoh, ketika SIGALRM diterima, program mencetak pesan bahwa timer alarm telah berakhir.  
- Program juga menggunakan fungsi `alarm()` untuk mengirim SIGALRM setelah waktu tertentu sebagai demonstrasi.

**Video Menjalankan Program**

https://github.com/user-attachments/assets/1407d3c4-d94d-475b-b71e-b357d90da034

## Daftar Pustaka

W. R. Stevens and S. A. Rago, Advanced Programming in the UNIX Environment, 3rd ed., Addison-Wesley, 2013.
M. Kerrisk, The Linux Programming Interface: A Linux and UNIX System Programming Handbook, No Starch Press, 2010.
IEEE Std 1003.1-2017, "POSIX.1-2017 — Signal Concepts." [Online]. Available: https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/signal.h.html
