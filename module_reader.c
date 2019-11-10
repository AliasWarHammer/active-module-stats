/* Author : PES1201700241, Saahil Jain */
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include "module_reader.h"

void module_initializer(
    Module *module, char *name, 
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
    for(int i=0 ; i<number_of_dependencies ; i++)
    {
        strcpy(module->dependencies[i], dependencies[i]);
    }
    module->status = status;
    module->offset = offset;
}

void module_reader()
{
    
}