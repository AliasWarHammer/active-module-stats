/* Author : PES1201700241, Saahil Jain */

typedef struct my_modules
{
    char name[256];
    unsigned int size;
    unsigned int instances;
    unsigned int number_of_dependencies;
    char dependencies[500];
    unsigned int status;
    unsigned long int offset;
}Module;

void module_initializer(
    Module *module, 
    char *name, 
    unsigned int size, 
    unsigned int instances, 
    unsigned int number_of_dependencies, 
    char *dependencies, 
    unsigned int status, 
    unsigned long int offset
    );

void module_reader();

int parser(Module *module, char *line);

int linecounter();