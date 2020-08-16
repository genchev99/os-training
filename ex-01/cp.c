#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  
  int source_fd = open(argv[1], O_RDONLY);
  
  if (source_fd == -1) {
    // Handle source file error
    printf("There was an error with the source file!");
    return 1;
  }
  
  int destination_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
  
  if (destination_fd == -1) {
    // Handle destination file error
    printf("There was an error with the destination file!");
    return 2;
  }
  
  // Write content to destination file  
  char byte_buffer[1];
  
  while (read(source_fd, byte_buffer, 1) > 0) {
    write(destination_fd, byte_buffer, 1);
  }
  
  close(source_fd);
  close(destination_fd);
  
  return 0;
}
