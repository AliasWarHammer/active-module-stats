#include <stdio.h>
#define COMMAND_LEN 64
#define DATA_SIZE 2048

int main(int argc,char *argv[])
{

    FILE *pf;
    char command[COMMAND_LEN];
    char data[DATA_SIZE];

    // Execute a process listing
    sprintf(command, "modinfo ");

    // Setup our pipe for reading and execute our command.
    pf = popen(command, "r");

    if(!pf)
    {
        fprintf(stderr, "Error: Could not open pipe for output.\n");
        return;
    }

    // Grab data from process execution
    while(fgets(data, DATA_SIZE , pf))
    {
        fprintf(stdout, "%s",data);
    }

    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");

    return 0;
}