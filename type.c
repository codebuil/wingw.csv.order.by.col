#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 6000

int main(int argc, char *argv[]) {
    char *ptr= (char*) malloc(6000001);
    int size=0;


    printf("\033c\033[44;37m\n");
    if (ptr == NULL) {
        printf("out of memory.\r\n");
        exit(1);
    }
    if (argc != 2) {
        free(ptr);
        printf("Usage: %s filename\r\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int i;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    size=fread(ptr,1, 6000000, fp);
    fclose(fp);
    if (size>6000000-5){
        free(ptr);
        printf("out of memory\r\n");
    }
    
        // Split line into fields
        i = 0;
        fields[i] = strtok(ptr, "\n");
        while (fields[i] != NULL && i < MAX_FIELDS) {
            i++;
            fields[i] = strtok(NULL, "\n");
        }

        // Print fields separated by tabs
        for (int j = 0; j < i; j++) {
            printf("%s\n", fields[j]);
        }
        
    

    fclose(fp);
    free(ptr);
    return 0;
}
