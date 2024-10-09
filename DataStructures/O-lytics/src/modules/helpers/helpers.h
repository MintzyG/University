#pragma once

#include<stdio.h>

typedef struct oLog oLog;
typedef enum LogLevel LogLevel;

enum LogLevel {
  OFF,
  WARN,
  TRACE,
  ALL
};

struct oLog {
  enum LogLevel log_level;

  FILE* file;

  void (*Log)(oLog* log, char* message, const char* context, enum LogLevel);
  void (*SetLevel)(oLog* self, enum LogLevel);
  void (*CloseLogs)(oLog* self);
};

oLog* InitLog(void);
void Uninplemented(const char*);
void PrintData(int* data, int size);
