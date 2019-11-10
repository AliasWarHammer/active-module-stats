/* Authors : PES1201700241, Saahil Jain 
           : PES1201700190, Mithali Shashidhar 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_reader.h"
#include "acquire_modinfo.h"

#define READ_FILE "/proc/modules" 

void module_initializer(
    Module *module, 
    char *name, 
    unsigned int size, 
    unsigned int instances, 
    unsigned int number_of_dependencies, 
    char *dependencies, 
    unsigned int status, 
    unsigned long int offset
    )
{
    strcpy(module->name, name);
    module->size = size;
    module->instances = instances;
    module->number_of_dependencies = number_of_dependencies;
    strcpy(module->dependencies, dependencies);
    module->status = status;
    module->offset = offset;
}

void module_reader()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    int number_of_lines = linecounter();

    Module module[256];
    int position = 0;
    fp = fopen(READ_FILE, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Unable to read file");
    }
    position = 0;
    int insert = 0;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        insert = 0;
        insert = parser(&module[position], line);
        position += insert;
    }
    fclose(fp);
}

int linecounter()
{
    FILE *fp; 
    int count = 0; 
    char *line = NULL;
    size_t len = 0;
    size_t read;
    fp = fopen(READ_FILE, "r"); 
    if (fp == NULL) 
    { 
        fprintf(stderr, "Error: Unable to read file");
    } 
    while ((read = getline(&line, &len, fp)) != -1)
    {
        count += 1;
    }
    fclose(fp); 
    return count; 
}

int parser(Module *module, char *line)
{
    char *name = (char *)malloc(sizeof(char)*250);
    unsigned int size;
    unsigned int instances;
    unsigned int number_of_dependencies = 0;
    char *dependencies = (char *)malloc(sizeof(char)*250);
    unsigned int status;
    unsigned long int offset;
	
    char* token = strtok(line, " "); 
    strcpy(name, token);

    token = strtok(NULL, " ");
    size = atoi(token);

    token = strtok(NULL, " ");
    instances = atoi(token);

    token = strtok(NULL, " ");
    char c = ',';
    for (int i=0;i<strlen(token);i++)
    {
        if (token[i] == c) 
            number_of_dependencies++; 
    }
    if(number_of_dependencies > 0)
    {
        strcpy(dependencies, token);
        
    }
    else
    {
        strcpy(dependencies, "NULL");
    }
    token = strtok(NULL, " ");
    if(strcmp(token, "Live")==0)
    {
    	status = 0;
    }
    else if(strcmp(token, "Loading")==0)
    {
    	status = 1;
    }
    else if(strcmp(token, "Unloading")==0)
    {
    	status = 2;
    }

    token = strtok(NULL, " ");
    offset = (int)strtol(token, NULL, 0);
    if(instances>0)
    {
        fprintf(stdout, "name:           %s\n", name);
        fprintf(stdout, "size:           %d\n", size);
        fprintf(stdout, "instances:      %d\n", instances);
        fprintf(stdout, "dependencies_c: %d\n", number_of_dependencies);
        fprintf(stdout, "dependencies:   %s\n", dependencies);
        fprintf(stdout, "status:         %d\n", status);
        fprintf(stdout, "offset:         0x%x\n", offset);
        modinfo(name);
        fprintf(stdout, "\n");
        return 1;
    }
    return 0;
}