#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

// Handler untuk SIGINT (Ctrl+C)
void sigint_handler(int sig) {
    printf("\nIntercepted SIGINT (Ctrl+C)! Saya tidak akan berhenti!\n");
    printf("Gunakan Ctrl+\\ (SIGQUIT) untuk keluar dengan core dump\n");
    printf("Atau 'kill -9 %d' untuk memaksa berhenti\n", getpid());
}

// Handler untuk SIGTSTP (Ctrl+Z)
void sigtstp_handler(int sig) {
    printf("\nIntercepted SIGTSTP (Ctrl+Z)! Proses tidak di-suspend\n");
    printf("Gunakan 'fg' untuk mengembalikan proses ke foreground\n");
}

// Handler untuk SIGQUIT (Ctrl+\)
void sigquit_handler(int sig) {
    printf("\nIntercepted SIGQUIT (Ctrl+\\)! Membuat core dump dan keluar...\n");
    signal(SIGQUIT, SIG_DFL); // Kembalikan ke handler default
    raise(SIGQUIT);           // Kirim ulang sinyal
}

// Handler untuk SIGTERM (kill default)
void sigterm_handler(int sig) {
    printf("\nIntercepted SIGTERM (kill)! Membersihkan sumber daya...\n");
    printf("Gunakan 'kill -9' jika ingin memaksa berhenti\n");
    exit(0);
}

// Handler untuk SIGUSR1
void sigusr1_handler(int sig) {
    printf("\nIntercepted SIGUSR1! Ini adalah sinyal khusus pengguna 1\n");
}

// Handler untuk SIGUSR2
void sigusr2_handler(int sig) {
    printf("\nIntercepted SIGUSR2! Ini adalah sinyal khusus pengguna 2\n");
}

// Handler untuk SIGHUP
void sighup_handler(int sig) {
    printf("\nIntercepted SIGHUP! Terminal terputus atau sesi login berakhir\n");
}

// Handler untuk SIGALRM
void sigalrm_handler(int sig) {
    printf("\nIntercepted SIGALRM! Timer alarm telah berakhir\n");
}

// Handler untuk SIGCHLD
void sigchld_handler(int sig) {
    printf("\nIntercepted SIGCHLD! Proses child telah berubah status\n");
}

// Handler untuk SIGCONT
void sigcont_handler(int sig) {
    printf("\nIntercepted SIGCONT! Proses melanjutkan eksekusi\n");
}

// Handler untuk SIGPIPE
void sigpipe_handler(int sig) {
    printf("\nIntercepted SIGPIPE! Menulis ke pipe yang tidak ada pembaca\n");
}

int main() {
    // Daftarkan handler untuk berbagai sinyal
    signal(SIGINT, sigint_handler);    // Ctrl+C
    signal(SIGTSTP, sigtstp_handler);  // Ctrl+Z
    signal(SIGQUIT, sigquit_handler);  // Ctrl+\
    signal(SIGTERM, sigterm_handler);  // kill tanpa opsi
    signal(SIGUSR1, sigusr1_handler);  // Sinyal khusus pengguna 1
    signal(SIGUSR2, sigusr2_handler);  // Sinyal khusus pengguna 2
    signal(SIGHUP, sighup_handler);    // Hangup
    signal(SIGALRM, sigalrm_handler);  // Alarm
    signal(SIGCHLD, sigchld_handler);  // Child process berubah
    signal(SIGCONT, sigcont_handler);  // Lanjutkan proses
    signal(SIGPIPE, sigpipe_handler);  // Pipe rusak

    printf("=== Demonstrasi Signal Interceptor ===\n");
    printf("PID Proses ini: %d\n", getpid());
    printf("Coba kirim sinyal ke proses ini dengan:\n");
    printf("1. Tekan Ctrl+C (SIGINT)\n");
    printf("2. Tekan Ctrl+Z (SIGTSTP)\n");
    printf("3. Tekan Ctrl+\\ (SIGQUIT)\n");
    printf("4. Jalankan 'kill %d' (SIGTERM)\n", getpid());
    printf("5. Jalankan 'kill -USR1 %d' (SIGUSR1)\n", getpid());
    printf("6. Jalankan 'kill -USR2 %d' (SIGUSR2)\n", getpid());
    printf("7. Jalankan 'kill -HUP %d' (SIGHUP)\n", getpid());
    printf("8. Jalankan 'kill -ALRM %d' (SIGALRM)\n", getpid());
    printf("9. Jalankan 'kill -CHLD %d' (SIGCHLD)\n", getpid());
    printf("10. Jalankan 'kill -CONT %d' (SIGCONT)\n", getpid());
    printf("11. Jalankan 'kill -PIPE %d' (SIGPIPE)\n", getpid());
    printf("12. Jalankan 'kill -KILL %d' (SIGKILL) - tidak bisa diintercept\n", getpid());
    printf("\nProgram akan berjalan terus sampai dihentikan...\n");

    // Set alarm untuk demonstrasi SIGALRM
    alarm(30);

    // Loop utama
    while(1) {
        time_t now = time(NULL);
        printf("Menunggu sinyal... (%ld)\n", now);
        
        // Untuk demonstrasi SIGPIPE
        if (now % 60 == 0) {
            int fd[2];
            if (pipe(fd) == -1) {
                perror("pipe");
            } else {
                close(fd[0]); // Tutup read end
                write(fd[1], "test", 5); // Akan memicu SIGPIPE
                close(fd[1]);
            }
        }
        
        sleep(5);
    }

    return 0;
}
