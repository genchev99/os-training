#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *args[]) {
  int fd = open(args[1], O_CREAT|O_WRONLY);
  
  if (fd == -1) {
    printf("There was an error with the destination file!");
    
    return 1;
  }
  
  char buffer[1];
  
  while (read(0, buffer, 1)) {
    write(fd, buffer, 1);
    
    if (buffer[0] == '\t') {
      write(2, ">>>", 3);
    } else {
      write(2, buffer, 1);
    }
  }
  
  close(fd);
    
  return 0;
}
