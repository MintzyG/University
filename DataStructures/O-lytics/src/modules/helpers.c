#include "helpers.h"
#include "string.h"
#include "stdlib.h"

#include <stdio.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};

void Uninplemented(const char* func) {
  errno = ENOSYS;
  printf("%s: %s\n Exiting!!!",func, strerror(errno));
  exit(1);
}

void SetupLog() {
  if (stat("./logs", &st) == -1) {
    mkdir("./logs", 0700);
  }

  remove("./logs/log.txt");
}

void SetLevel(oLog* logger, enum LogLevel level) {
  logger->log_level = level;
}

void Log(oLog* log, char* message, const char* func, enum LogLevel match) {
  if (log->log_level == ALL) {
    char* ptr = calloc(256, 1);
    printf("[ALL](%s): %s\n", func, message);
  } else if ((int)match <= (int)log->log_level) {
    char* ptr = calloc(256, 1);
    switch (match) {
      case WARN:
        sprintf(ptr, "[WARN](%s): %s\n", func, message);
        fprintf(log->file, "%s", ptr);
        break;
      case TRACE:
        sprintf(ptr, "[TRACE](%s): %s\n", func, message);
        fprintf(log->file, "%s", ptr);
        break;
      default:
      case OFF:
        break;
    }
    free(ptr);
  }
}

void CloseLogs(oLog* logs) {
  fclose(logs->file);
}

oLog* InitLog(void) {
  oLog* l = calloc(1, sizeof *l);

  SetupLog();

  *l = (oLog) {
    .log_level = OFF,
    .Log = Log,
    .SetLevel = SetLevel,
    .file = fopen("./logs/log.txt", "w"),
    .CloseLogs = CloseLogs
  };
  return l;
}

void PrintData(int* data, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }
  printf("\n\n");
}
