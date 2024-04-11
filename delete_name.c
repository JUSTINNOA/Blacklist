#include<stdio.h>
#include "delete_name.h"

void delete_name(FILE *file, char name)
{
    FILE *tempFile=fopen("tempfile.txt","w");

    if(file==NULL||tempFile==NULL)
    {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
         return -1; 
    }
    char ch;
    while((ch = fgetc(file)) != EOF)
    {
        if(ch!= name)
        {
            fputc(ch, tempFile);
        }
    }
    fclose(file); 
    fclose(tempFile);
   return 0;
}