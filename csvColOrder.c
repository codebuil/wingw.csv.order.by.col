#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 60000

int main(int argc, char *argv[]) {
    char *ptr= (char*) malloc(6000001);
    int size=0;
    int t=0;


    printf("\033c\033[44;37m\n");
    if (ptr == NULL) {
        printf("out of memory.\r\n");
        exit(1);
    }
    if (argc != 3) {
        free(ptr);
        printf("Usage: %s filename\r\n", argv[0]);
        return 1;
    }
    t=atoi(argv[2]);
    char *filename = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    char *fieldss[MAX_FIELDS];
    int list1[MAX_FIELDS];
    int counters=0;
    int pointers=0;
    int exange=0;
    int exange2=0;
    int r=0;
    int i;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    size=fread(ptr,1, 6000000, fp);
    fclose(fp);
    ptr[size]=0;
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
            char *ffields=fields[j];
            char *fffields=fields[j];
            fieldss[j]=fields[j];
            if(t>0){
            for(int tt=0;tt<t;tt++){
                fffields=strstr(ffields,",");
                ffields=fffields+1;
                if(ffields==NULL){
                    fieldss[j]=fields[j];
                    tt=t+2;
                }
                else
                {
                    fieldss[j]=ffields;
                }

                }
                }
                  
            }
               
           counters=0;
        if(i>0){
            list1[0]=0;
            counters++;
            if(i>1){
                for (int j = 1; j < i; j++) {
                    exange=j;
                    for(r=0;r<counters;r++){
                        if(strcmp(fieldss[list1[r]],fieldss[exange])==1){
                            exange2=exange;
                            exange=list1[r];
                            list1[r]=exange2;
                        }

                    }
                    list1[counters]=exange;
                    counters++;
                }
            }
            for (int j = 0; j < i; j++){
                printf("%s\n", fieldss[list1[j]]); 
            }  
        }
        
    

    
    free(ptr);
    return 0;
}
