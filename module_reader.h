/* Author : PES1201700241, Saahil Jain */

// This structure is used to hold the information returned 
// /proc/modules in a structured manner.
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

// Initializes the parameters of the module structure.
// Takes as input the structure variables. 
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

// Reads the list of modules from /proc/modules.
void module_reader();

// Parses each line of /proc/modules/ to extract the values for the required variables in the module structure. 
// Takes as input the module structure and the line to parse.
int parser(Module *module, char *line);

// Counts the number of lines in a file.
int linecounter();