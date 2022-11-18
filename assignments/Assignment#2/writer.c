#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char **argv)
{
    openlog(NULL, 0, LOG_USER);
    
    if(argc != 3)
    {
        syslog(LOG_ERR, "ERROR: Invalid Number of Arguments.");
        syslog(LOG_USER, "Total number of arguments should be 2.");
        syslog(LOG_USER, "The order of the arguments should be:");
        syslog(LOG_USER, "  1)File Directory Path");
        syslog(LOG_USER, "  2)String to be written in the specified directory path");

        return 1;
    }
    
    char* fileName = argv[1];
    char* str = argv[2];
    FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen(fileName, "w");

    if(fptr == NULL)
    {
        // syslog(LOG_ERR, "Error opening file = %d", fptr);   
        return 1;      
    }

    syslog(LOG_DEBUG, "Writing %s to %s", str, fileName);
    fprintf(fptr,"%s",str);
    fclose(fptr);

    return 0;
}