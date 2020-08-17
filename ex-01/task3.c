#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
  int source_fd = open(args[1], O_RDONLY);
  
  if (source_fd == -1) {
    perror("There was an error with the source file!");
    
    exit(1);
  }
  
  int destination_fd = open(args[2], O_APPEND|O_WRONLY, 0664);
  
  if (destination_fd == -1) {
    perror("There was a problem with the destination file!");
    
    exit(2);
  }
  
  char buffer[1];
  int counter = 0;
  
  while (read(source_fd, buffer, 1)) {
    if (counter < 3) {
      write(destination_fd, buffer, 1);
    }
    
    write(1, buffer, 1);
    
    counter++;
    
    if (buffer[0] == '\n') {
      counter = 0;
    }
  }
  
  return 0;
}
