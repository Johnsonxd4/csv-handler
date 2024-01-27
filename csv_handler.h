#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <strings.h>

#ifndef READ_CSV
#define READ_CSV

typedef struct {
	char * content;
	int count;
	size_t capacity;
}String_Builder;

String_Builder readfile(char * filepath);
void printTable(String_Builder csv_data);


String_Builder readfile(char * filepath){
  FILE* fptr;
  char * content = NULL; 
  int fsize = 0;
  fptr = fopen(filepath,"r");
  printf("reading file in the path: %s\n", filepath); 


  if (NULL == fptr) {
    printf("could not read the file. error %i", errno);
    exit(EXIT_FAILURE);
  }
  fseek(fptr,0,SEEK_END);
  fsize = ftell(fptr);
  rewind(fptr);

  String_Builder builder = (String_Builder) { .content = (char *) malloc(sizeof(char) *fsize),.count = fsize};
  fread(builder.content,1,builder.count,fptr);
  
  return builder;
}

void printTable(String_Builder csv_data) {
	int line_size = 0;
	int index = 0;
	char * token;
	char * subtoken;
	while((token =strsep(&csv_data.content,"\n"))){

	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	while ((subtoken =strsep(&token,","))) {
		printf("%s\t\t",subtoken);
	}
	printf("\n");
	}
		
}

#endif
