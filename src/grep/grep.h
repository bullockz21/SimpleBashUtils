#ifndef GREP_H
#define GREP_H

typedef struct arguments {
  int e, i, v, c, l, n, h, s, f, o;
  char* pattern;
  int len_pattern;
  int mem_pattern;
} arguments;
#endif
