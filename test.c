#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <wait.h>


int main() {
    int pid = fork();
    int stat;
    if(pid == 0){
        execlp("gcc", "gcc", "-o", "test.out", "main.c",NULL);
        perror("Error in: execlp");
        exit(0);
    }
    wait(&stat);
    int input = open("input.txt", 'r');
    int out = open("output.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    dup2(input, 0);
    dup2(out, 1);
    pid = fork();
    if(pid == 0){
        execlp("./test.out", "./test.out",NULL);
        perror("Error in: execlp");
        exit(0);
    }
    wait(&stat);
    close(input);
    close(out);
    return 0;
}