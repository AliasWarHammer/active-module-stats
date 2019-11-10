#include <stdio.h>
#include <string.h>

/*
This function calls the df command using the popen function.
The popen() function executes the specified command (in our case - df).
It creates a pipe between the calling program and the executed command, 
  and returns a pointer to a stream that can be used to either read from or write to the pipe.
*/
void df_call(){
    char buf[1000];
    int i;
        FILE *fp = popen("df", "r");

    fscanf(fp, "%s", buf);
    if(feof(fp))
        return;
    printf("%s\t\t", buf);

    for(i=0; i<4; i++)
    f   scanf(fp, "%s", buf);

    printf("%s\n", buf);

    for(i=0; i<2; i++)
        fscanf(fp, "%s", buf);

    while (1){
        fscanf(fp, "%s", buf);

        if(feof(fp))
            break;

        printf("%s\t\t", buf);

        for(i=0; i<4; i++)
            fscanf(fp, "%s", buf);

        if(strlen(buf) < 3)
            printf("\t%s\n", buf);
        else
            printf("%s\n", buf);
        fscanf(fp, "%s", buf);
    }
    pclose(fp);
}

int main() {
df_call();
}