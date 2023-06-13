#include<stdio.h>
#include<stdlib.h>
#include "mod.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int choix1,choix2,choix3;
    
    system("cls");// pour balayer la sortie standart 

    printf("\nBienvenue dans notre programme de gestion\n\n");

    do
    {
        printf("\n\n************Menu_Principal************\n\n");
        printf("1.Gestion des etudiants\n");
        printf("2.Gerer les matieres\n");
        printf("3.Gestion des classes\n");
        printf("4.Gestion des notes\n");
        printf("5.Matieres et Classes\n");
        printf("0.Quitter\n\n\n");

        printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
        scanf("%d",&choix1);

        switch(choix1)
        {
            case 1:
                do
                {
                                
                    sous_menu();

                    scanf("%d",&choix2);
                    getchar();


                    switch(choix2)
                        {
                        case 1:

                            ajout_etudiant();

                         break;

                        case 2:

                            modification_etudiant();

                            break;

                        case 3:

                            affichage_etudiant();

                            break;

                        case 4:

                            suppression_etudiant();

                            break;

                        case 5: 

                            afficher_etudiants();

                           break;

                        case 0:
                                //retour
                            break;

                        default:

                                printf("Merci de faire attention a ce que vous saisissez");
                                    
                            break;
                        }
                }while (choix2!=0);// Permet à l'utilisateur de rester dans ce sous menu tant qu'il le veut
            
            break;

            case 2:

                do
                {
                    
                    sous_menu();

                    scanf("%d",&choix2);
                    getchar();


                    switch(choix2)
                        {

                        case 1:
                                 
                            ajout_matiere();

                            break;

                        case 2:

                            modification_matiere();

                            break;

                        case 3:

                            affichage_matiere();

                            break;

                        case 4:

                            suppression_matiere();

                            break;

                        case 5:

                            afficher_matieres();

                            break;

                        case 0:
                                //retour
                            break;

                        default:
                                printf("Merci de faire attention a ce que vous saisissez");
                                    
                            break;

                        }
                }while (choix2!=0);// Permet à l'utilisateur de rester dans ce sous menu tant qu'il le veut
                

            break;

            case 3:

                do
                {
                    printf("\n\n************Sous_Menu************\n\n");
                    printf("1.Ajout\n");
                    printf("2.Modification\n");
                    printf("3.Recherche\n");
                    printf("4.Suppression\n");
                    printf("5.Affichage de la liste\n");
                    printf("6.Afficher les etudiants d'une classe\n");
                    printf("0.Retour au Menu Principal\n\n\n");

                    printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
                    scanf("%d",&choix2);
                    getchar();

                    switch(choix2)
                    {
                        case 1:
                                 
                            ajout_classe();

                         break;

                        case 2:

                            modification_classe();

                         break;

                        case 3:

                            affichage_classe();

                         break;

                        case 4:

                            suppression_classe();

                         break;

                        case 5:

                            afficher_classes();

                         break;

                        case 6:

                            etudiants_classe();

                         break;

                        case 0:
                                //retour
                         break; 

                        default:

                            printf("Merci de faire attention a ce que vous saisissez");
                                    
                         break;    
                    }
            
                }while (choix2!=0);// Permet à l'utilisateur de rester dans ce sous menu tant qu'il le veut
                

            break;

            case 4:

                do
                {
                                
                    printf("\n\n************Sous_Menu************\n\n");
                    printf("1.Ajouter\n");
                    printf("2.Modification\n");
                    printf("3.Supprimer\n");
                    printf("4.Consulter\n");
                    printf("0.Pour retourner au Menu Principal\n\n");

                    printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
                    scanf("%d",&choix2);
                
                    switch(choix2)
                    {
                        case 1:

                           do
                           {
                                printf("\najouter des notes pour: \n");
                                printf("1.un etudiant dans plusieurs matieres\n");
                                printf("2.un etudiant dans toutes ses matieres\n");
                                printf("3.une classe dans une seule matieres\n");

                                printf("0.Retour Sous Menu\n\n");

                                printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
                                scanf("%d",&choix3);
                                getchar();


                                switch (choix3)
                                {
                                    case 1:

                                        ajout_notes();

                                    break;

                                    case 2:

                                        ajout_etudiants_matiere();

                                    break;

                                    case 3:

                                        ajout_notes_classe();

                                    break;

                                    case 0:
                                        //retour
                                    break;
                                
                                    default:

                                        printf("Merci de faire attention a ce que vous saisissez");
                                    
                                    break;
                                }

                            } while (choix3!=0);
                           

                        break;

                        case 2:

                            modification_notes();

                        break;

                        case 3:

                           suppression_notes();

                        break;

                        case 4:

                                printf("\n\n\nconsulter les notes : \n\n\n");
                                printf("1.d'un etudiant dans une matiere\n");
                                printf("2.d'un etudiant dans toutes ses matieres\n");
                                printf("3.d'une classe dans une matieres\n");

                                printf("0.Retour Sous Menu\n\n");

                                printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
                                scanf("%d",&choix3);
                                getchar();

                                switch (choix3)
                                {
                                case 1:
                                    
                                    notes_etudiant_matiere ();                              

                                break;
                                case 2:
                                    
                                    notes_etudiant_matieres();

                                break;
                                case 3:
                                    
                                    notes_etudiants_matiere();

                                break;
                                case 0:
                                    // retour
                                break;
                                
                                default:
                                break;
                                }

                        break;

                        case 0: 
                                //retour
                        break;

                        default:

                            printf("Merci de faire attention a ce que vous saisissez");
                                    
                        break;
                    } 

                }while (choix2!=0);// Permet à l'utilisateur de rester dans ce sous menu tant qu'il le veut
                

            break;

            case 5:
                do
                {
                    printf("\n\n************Sous_Menu************\n\n");
                    printf("1.Associer\n");
                    printf("2.Disssocier\n");
                    printf("3.voir association\n");
                    printf("0.Retour au Menu Principal\n\n");

                    printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
                    scanf("%d",&choix3);
                    getchar();


                    switch (choix3)
                    {
                        case 1:
                            associer();
                        break;
                        case 2:
                            dissocier();
                        break;

                        case 3:
                            voir_association();
                        break;

                        case 0: 
                            //retour
                        break;
                        
                        default:
                            printf("Merci de faire attention a ce que vous saisissez");
                        break;

                    }
                } while (choix3!=0);
                
            break;

            case 0:

                printf("\n\n\n Merci de votre attention et a la prochaine\n\n\n");

                exit(EXIT_FAILURE);
                    
            break; 
            
            default:

                printf("Merci de nous avoir fait confiance");
                                    
            break;
        }
    }while(choix1!=0); // Puisque nous avons déjà une option pour quitter le programme(quitter)  
                // cette boucle permet aussi un retour au menu precedent de faire autant de manipulation que l'on veut
}