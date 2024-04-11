#include<stdio.h>
#include "find_name.h"


int find_name(FILE *file, char name)
{
    int found=0;
    char ch;
    if(file== NULL)
    {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
        return -1;
    }
    while((ch = fgetc(file)) != EOF)
    {
        if(ch== name)
        {
            found=1;
            break;
        }
    }
    fclose(file); 
    
    return found;
}