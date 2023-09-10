#include <stdio.h>
#define SIZE 1024
void main(){
int pfd[2], nread, pid;
char buf[SIZE];
if(-1 == pipe(pfd)){
perror("pipe failed");
exit(1);
}
if(0 > (pid = fork())){
perror("fork failed");
exit(2);
}
if(0 == pid){/* child */
close(pfd[1]);
while ((nread = read(pfd[0], buf, SIZE)) != 0)
printf("child read %s\n", buf);
close(pfd[0]);
}
else{/* parent */
close(pfd[0]);
strcpy(buf, "hello...");
/* include null terminator in write */
write(pfd[1], buf, strlen(buf)+1);
close(pfd[1]);
}
}

