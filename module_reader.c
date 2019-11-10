/* Authors : PES1201700241, Saahil Jain 
           : PES1201700190, Mithali Shashidhar 
           : */
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include "module_reader.h"

void module_initializer(
    Module *module, 
    char *name, 
    unsigned int size, 
    unsigned int instances, 
    unsigned int number_of_dependencies, 
    char **dependencies, 
    unsigned int status, 
    unsigned long int offset
    )
{
    strcpy(module->name, name);
    module->size = size;
    module->instances = instances;
    module->number_of_dependencies = number_of_dependencies;
    module->dependencies = (char **)malloc(sizeof(char *)*number_of_dependencies);
    for(int i=0 ; i<number_of_dependencies ; i++)
    {
        module->dependencies[i] = (char *)malloc(sizeof(char)*250);
        strcpy(module->dependencies[i], dependencies[i]);
    }
    module->status = status;
    module->offset = offset;
}

void module_reader()
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int number_of_lines = linecounter();
    Module *module[number_of_lines];
    for(int i=0; i<number_of_lines ; i++)
    {
        module[i] = (module *)malloc(sizeof(module));
    }
    int position = 0;
    fp = fopen("/tmp/module.txt", "r");
    if (fp == NULL)
    {
        fprintf(2, "** Unable to read file");
    }
    int position = 0;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf("%s", line);
        parser(module[position], line);
        position += 1;
    }
    fclose(fp);
    for(int i=0; i<number_of_lines ; i++)
    {
        
    }
}

int linecounter()
{
    FILE *fp; 
    int count = 0; 
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("/tmp/module.txt", "r"); 
    if (fp == NULL) 
    { 
        fprintf(2, "** Unable to read file");
    } 
    while ((read = getline(&line, &len, fp)) != -1)
    {
        count += 1;
    }
    fclose(fp); 
    return count; 
}

void parser(Module *module, char *line)
{
    char *name;
    unsigned int size;
    unsigned int instances;
    unsigned int number_of_dependencies;
    char **dependencies;
    unsigned int status;
    unsigned long int offset;

    //

    module_initializer(module, name, size, instances, number_of_dependencies, dependencies, status, offset)
}