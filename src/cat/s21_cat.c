#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arguments {
  int b, n, s, E, T, v;
} arguments;

arguments argument_parser(int argc, char** argv) {
  arguments args = {0};
  struct option long_options[] = {{"number", no_argument, NULL, 'n'},
                                  {"number-noblank", no_argument, NULL, 'b'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {0, 0, 0, 0}};

  int opt;
  while ((opt = getopt_long(argc, argv, "bnEeTtsv", long_options, 0)) != -1) {
    switch (opt) {
      case 'b':
        args.b = 1;
        break;
      case 'E':
        args.E = 1;
        break;
      case 'n':
        args.n = 1;
        break;
      case 's':
        args.s = 1;
        break;
      case 'e':
        args.E = 1;
        args.v = 1;
        break;
      case 't':
        args.T = 1;
        args.v = 1;
        break;
      case 'T':
        args.T = 1;
        break;
      case '?':
        perror("ERROR");
        exit(1);
        break;
      default:
        break;
    }
  }

  return args;
}

char v_output(char ch) {
  if (ch == '\n' || ch == '\t') return ch;
  if (ch > 0 && ch <= 31) {
    putchar('^');
    ch += 64;
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }
  return ch;
}

void outline(arguments* args, char* line, int n) {
  for (int i = 0; i < n; i++) {
    if (args->T && line[i] == '\t')
      printf("^I");
    else {
      if (args->E && line[i] == '\n') {
        putchar('$');
      } else if (args->v) {
        line[i] = v_output(line[i]);
      }
      putchar(line[i]);
    }
  }
}

void output(arguments* args, char** argv) {
  FILE* file = fopen(argv[optind], "r");
  if (file == NULL) {
    perror("ERROR");
    exit(1);
  }

  char* line = NULL;
  size_t memline = 0;
  ssize_t read;

  int line_count = 1;
  int empty_count = 0;

  while ((read = getline(&line, &memline, file)) != -1) {
    if (line[0] == '\n') {
      empty_count++;
    } else {
      empty_count = 0;
    }

    if (args->s && empty_count > 1) {
      continue;
    }

    if (args->n || args->b) {
      if (args->b && line[0] != '\n') {
        printf("%6d\t", line_count);
        line_count++;
      } else if (args->n && !args->b) {
        printf("%6d\t", line_count);
        line_count++;
      }
    }

    outline(args, line, read);
  }

  free(line);
  fclose(file);
}

int main(int argc, char* argv[]) {
  arguments args = argument_parser(argc, argv);
  output(&args, argv);
  return 0;
}