#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"add_name.h"
#include"find_name.h"
#include"delete_name.h"

void add_name(FILE *file, char *name);
void find_name(FILE *file, char *name);
void delete_name(FILE *file, char *name);

int main(){
    FILE *file= fopen("names.txt","a+");

    if(file==NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }
    int choix;
    char name[100];
    do{
        printf("\n Menu:\n");
        printf("1.Ajouter un nom\n");
        printf("2.Rechercher un nom\n");
        printf("3.Supprimer un nom\n");
        printf("0.Quitter\n");
        printf("choix:\n");
        scanf("%d",&choix);

        switch(choix){
            case 1:
            printf("Entrez le nom à ajouter:");
            scanf("%s",name);
            add_name(file,name);
            break;
            case 2:
            printf("Entrez le nom à rechercher:");
            scanf("%s",name);
            if(find_name(file,name))
            {
                printf("le nom \"%s\" a été trouver.\n",name);
            }else{
                printf("le nom \"%s\" n'a pas été trouver.\n",name);
            }
            break;
            case 3:
            printf("Entrez le nom à supprimer:");
            scanf("%s",name);
            delete_name(file,name);
            break;
            case 0:
            printf("Requet executer avec success!\n");
            break;
            default:
            printf("Choix invalide. veuillez réessayer.\n");
        }
    }while(choix!=0);
    fclose(file);

    return 0;
}