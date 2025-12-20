//===---------------------------------------------------*- C -*---===
//: hello_world.c
//
// BY  : John Kaul
//
// DESCR:
// A "hello world" example c program for the drist application.
//
// RUN:
// cc -o hello_world hello_world.c && ./hello_world
//===-------------------------------------------------------------===

#include <stdio.h>

/**
 * Main
 * @param argc            :   number of args
 * @param argv[]          :   array of arguments
 *
 * @return int
 */
int main(int argc, char *argv[]) {
  printf("Hello world!\n");
  return 0;
} ///:~
