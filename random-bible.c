#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    FILE *fp;
    char * line = NULL;
    char ch;
    int lines = 0;
    int random_line = 0;
    size_t len = 0;
    ssize_t read;

    fp = fopen("bible.txt", "r");
    while(!feof(fp)) {
      ch = fgetc(fp);

      if(ch == '\n') {
        lines++;
      }
    }
    fclose(fp);

    srand(time(NULL));
    random_line = rand() % lines;


    fp = fopen("bible.txt", "r");

    lines = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (lines == random_line) {
          printf("%s", line);
        }
        lines++;
    }

    fclose(fp);
    free(line);
}
