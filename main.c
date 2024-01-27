#include "csv_handler.h"
#include <stdio.h>
int main(){
  String_Builder builder= readfile("/home/johnson/sources/c/climate.csv");
  printf("Count is:  %i",builder.count);
  printTable(builder);
  return 0;
}
