/* Author : PES1201700241, Saahil Jain */

typedef struct my_modules
{
    char *name;
    unsigned int size;
    unsigned int instances;
    unsigned int number_of_dependencies;
    char **dependencies;
    unsigned int status;
    unsigned long int offset;
}Module;

void module_initializer(
    Module *module, 
    char *name, 
    unsigned int size, 
    unsigned int instances, 
    unsigned int number_of_dependencies, 
    char **dependencies, 
    unsigned int status, 
    unsigned long int offset
    );

void module_reader();

void parser(Module *module, char *line);

int linecounter();