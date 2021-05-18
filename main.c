#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fonctions.h"
#include <time.h>


int main(void)
{
    //***Initialisation des Variables*********
    
    int choix,TailleProgramme;
    char NomProgramme[255];
    time_t t;
    Prog * PrecedentProg = malloc(sizeof(Prog));
    Prog * ProgAjouter = malloc(sizeof(Prog));
    Prog * DebutProg = malloc(sizeof(Prog));
    PrecedentProg = NULL;
    time(&t);

    //**************L'intialisation des pages ********
    int num;
    Page * Precedent, * DebutPage;
    Precedent = malloc(sizeof(Page));
    DebutPage = malloc(sizeof(Page));
    DebutPage = Initialisation(NULL,1);
    Precedent = DebutPage;
    for(num=2; num <=25; num++) {
        Precedent = Initialisation(Precedent,num);
    }




    //************************* Taille Libres de la mémoires
    //************************* A chaque fois on ajoute un programme x = x-taille/100
    //Lorsqu'on supprime un programme on ajoute x = taille/100 + x
    int TailleLibreMemoire = 2500;
    
    printf("\n\t\t      Projet : ASE   \t\t");

    printf("\n\tDate actuelle : %s",ctime(&t));

    printf(" ----------------------------------------------------------- \n");
    printf("|                                                           |\n");
    printf("|                   Memoire centrale                        |\n");
    printf("|                                                           |\n");
    printf(" ----------------------------------------------------------- \n");
	/*Retourner au menu a chaque fois.*/
	while (choix != 10) {
		/*le Menu.*/
		color_text(-1);
		printf(" ----------------------------------------------------------- \n");
		printf("|                            MENU                           |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 1 |             Charger un nouveau programme              |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 2 |          Terminer l'execution d'un programme          |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 3 |             Afficher tous les programmes              |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 4 |                     Rechercher                        |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 5 |            Afficher tous les pages libres             |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 6 |                 Afficher la Memoire                   |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 7 |             Afficher les pages occupées               |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 8 |               Defragmenter la Memoire                 |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 9 |               Reinitialiser la Memoire                |\n");
		printf(" ----------------------------------------------------------- \n");
		printf("| 10|                        Quitter                        |\n");
		printf(" ----------------------------------------------------------- \n");
        
        
        //********************* La saisie du choix *****************************
        
		printf("\nEntrer votre choix : >>\t");
		scanf("%d", &choix);
		
		
		
		//*********************l'insertion du programme ************************
		
		if (choix == 1) {
		    printf("entrer le nom du prog :\t");
            scanf("%s",&NomProgramme);
            printf("entrer la taille du prog :\t");
            scanf("%d",&TailleProgramme);
            if(TailleProgramme>0)
            {
                if (TailleProgramme<=TailleLibreMemoire){
                    int x = TrouverProg(DebutProg, NomProgramme);
                        if (x==0){
                            Page * TempPage = malloc(sizeof(Page));
                            TempPage = DebutPage;
                            int NbrPages = TailleToPages(TailleProgramme);
                            TailleLibreMemoire= TailleLibreMemoire-NbrPages*100;
                            //****Creer le programme 
                            ProgAjouter = CreerProgramme(TailleProgramme,NomProgramme);
                            //*** Ajouter le programme au liste chainé des programmes
                            AjouterProg(PrecedentProg,ProgAjouter);
                            if(PrecedentProg==NULL){
                                DebutProg= ProgAjouter;
                            }
                            PrecedentProg = ProgAjouter;
                            //*****Affectation des pages 
                            while(NbrPages!=0)
                            {
                                if (TempPage->ProgMemoire==NULL){
                                    TempPage->ProgMemoire = PrecedentProg;
                                    NbrPages = NbrPages-1;
                                }
                                TempPage=TempPage->suivant;
                            }
                            printf("\nProgramme ajouté avec succès.\n");
                        }
                        else{
                            printf("Programme déja ajouté\n\n");
                        }
                }
                else{
                    printf("\n\nStockage disponible insuffisant.\n\n");
                    
                }
                EtatMemoire(TailleLibreMemoire);
            }
            else
            {
                printf("Taille <=0!!\n");
            }
		}
		
		
		//********************* La supression d'un programme *******************
		
		else if(choix ==2){
		    printf("Entrer le nom du prog à terminer:\t");
		    scanf("%s",NomProgramme);
		    int test = TrouverProg(DebutProg, NomProgramme);
            if (test==1)
            {
            		    Prog * tmp;
            		    int x=0;
            		    if (strcmp(DebutProg->Nom,NomProgramme)==0)
            		    {
            		        tmp =DebutProg->suivant;
            		        x=1;
            		    }
            		    TailleProgramme = ViderPage(DebutPage, NomProgramme);
            		    if (strcmp(PrecedentProg->Nom,NomProgramme)!=0){
            		        SupprimerProg(DebutProg, NomProgramme);
            		    }
            		    else{
            		        PrecedentProg=NULL;
            		        SupprimerProg(DebutProg, NomProgramme);
            		        Prog * test=DebutProg;
            		        while (test!=NULL){
            		            PrecedentProg=test;
            		            test=test->suivant;
            		        }
            		    }
            		    TailleLibreMemoire=TailleLibreMemoire+TailleToPages(TailleProgramme)*100;
            		    EtatMemoire(TailleLibreMemoire);
            		    if(x==1)
            		    {
            		        DebutProg = tmp;
            		    }
            }
        	else{
            		     printf("Programme n'existe pas!!\n\n");
            	}
		    
		}
		
		
		//********************* L'affichage de tous les programmes *************
		
		else if(choix ==3){
		    if (TailleLibreMemoire!=2500){
		             AfficherProg(DebutProg,DebutPage);
		    }
		    else{
		        printf("Aucun programme n'est ajouté!!\n");
		    }
		}
		
		
		//********************* La recherche ***********************************
		
		else if(choix ==4){
		    printf("Entrez le Nom de programme a rechercher :\t");
		    scanf("%s",NomProgramme);
		    chercher(DebutProg, DebutPage, NomProgramme);
		}
		
		//********************* L'affichage des pages libres *******************
		
		else if(choix ==5){
		    if (TailleLibreMemoire!=0){
		        AfficherPage(DebutPage);
		    }
		    else{
		        printf("Toutes les pages sont occupées.\n");
		    }
		}
		
		//********************* L'affichage de la mémoire **********************
		
		else if(choix ==6){
		    AfficherMemoire(DebutPage);
		    printf("\t\t\t\t\t\tTaille disponible :%d pages.\n",TailleToPages(TailleLibreMemoire));
		}
		
		//********************* L'affichage des Pages occupées *****************
		
		else if(choix ==7){
		    AfficherPageOccuper(DebutPage);
		}
		
		//********************* La Defragmentation de la mémoire ***************
		
		else if(choix==8)
		{
		    if(TailleLibreMemoire!=2500){
    		    int i =1;
    		    Page * tmp = DebutPage;
    		    while (i<=25){
    		        tmp->ProgMemoire=NULL;
    		        tmp=tmp->suivant;
    		        i=i+1;
    		    }
    		    DebutPage = Defragmenter(DebutPage,DebutProg);
    		    printf("Memoire est bien defragmenté.\n");
		    }
		    else{
		        printf("Memoire est déja vide!!\n");
		    }
		}
		
		//********************* La reinitialisation de la mémoire **************
		
		else if(choix==9){
		    if(TailleLibreMemoire!=2500){
    		    Prog * tmp = DebutProg;
    		    while (tmp != NULL) 
    		    {
    		        strcpy(NomProgramme,tmp->Nom);
    		        int test = TrouverProg(DebutProg, NomProgramme);
                     if (test==1)
                    {
                    		    Prog * tmp;
                    		    int x=0;
                    		    if (strcmp(DebutProg->Nom,NomProgramme)==0)
                    		    {
                    		        tmp =DebutProg->suivant;
                    		        x=1;
                    		    }
                    		    TailleProgramme = ViderPage(DebutPage, NomProgramme);
                    		    printf("%s :",NomProgramme);
                    		    SupprimerProg(DebutProg, NomProgramme);
                    		    TailleLibreMemoire=TailleLibreMemoire+TailleToPages(TailleProgramme)*100;
                    		    if(x==1)
                    		    {
                    		        DebutProg = tmp;
                    		    }
                    }
                    tmp = tmp->suivant;
                }
    		    printf("Memoire est reinitialisé\n");
    		    PrecedentProg = NULL;
		    }
		    else
		    {
		       printf("Memoire est déja vide!!\n"); 
		    }
		}
		
		//********************* Quitter ****************************************
		else if(choix==10){
		    printf("A Bientôt");
		}
		
		else{
		    printf("Verifier votre choix.\n");
		}
	}
}
