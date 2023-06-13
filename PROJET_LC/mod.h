#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED


// Là nous avons la structure Classe 

#define trente 30

typedef enum
{
    LICENCE,MASTER
}Niveau;

typedef struct
{
    int code;
    char nom[trente];
    Niveau niveau;
}Classe;

// Là la structure etudiant
typedef struct
{
    int jour;
    int mois;
    int An;
}Date;

#define vingth 20

typedef struct
{
    int numero;
    char nom[trente];
    char prenom[vingth];
    char email[vingth];
    Date date;
    int code;
}Etudiant;


// Ici la structure Matieres

#define quinze 15

typedef struct
{
    int reference;
    char libelle[quinze];
    short coefficient;
}Matieres;


void sous_menu()
{
    printf("\n\n************Sous_Menu************\n\n");
    printf("1.Ajout\n");
    printf("2.Modification\n");
    printf("3.Recherche\n");
    printf("4.Suppression\n");
    printf("5.Affichage de la liste\n");
    printf("0.Retour au Menu Principal\n\n\n");

    printf("Entrer le chiffre correspondant a l'option que vous voulez: ");
            
} // pour eviter la repétition au niveau des sous_menus 


// declarations des variables de types structures

   Etudiant etudiant;
    Classe classe;
    Matieres matieres;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ici bas nous avons notre fonctions de recherche pour les classes

int recherche_classe(int num_recherche)
{
    FILE*c;
    c=fopen("Classe.csv","r");
    int i=0;
    do
    {
        fscanf(c,"%d ; %s ; %u \n",&classe.code,classe.nom,&classe.niveau);
        fflush(stdin);
        if(classe.code==num_recherche) 
        {
            i++;
        }
    }while(!feof(c));

    fclose(c);
    if(i!=0) return 1;
    else return -1;
}

// Ici nous avons la procedure d'ajout de classe 

void ajout_classe()
{
    FILE*c;
    int code;
    c=fopen("Classe.csv","a");
    printf("\n Entrer le code: ");
    scanf("%d",&code);
    
    while(recherche_classe(code)==1)
    {
        printf("\n Ce code existe deja");
        printf("\n Entrer un nouveau code: ");
        scanf("%d",&code);
        getchar();
    }

    classe.code = code;
    printf("Entrer son nom: ");
    gets(classe.nom);
    printf("Entrer son niveau: ");
    scanf("%u",&classe.niveau);

    fprintf(c,"%d ; %s ; %d \n",classe.code,classe.nom,classe.niveau);
    fclose(c);
    printf("Information enregistrer avec succes\n\n");
}

// Ici la procedure d'affichage d'une classe

void affichage_classe()
{
    int code;
    printf("Entrer le code de la classe: ");
    scanf("%d",&code);
    FILE*c;
    c=fopen("Classe.csv","r");
    do
    {
        fscanf(c,"%d ; %s ; %u \n",&classe.code,classe.nom,&classe.niveau);
        fflush(stdin);
        if(code==classe.code)
        {
            printf("\n******Information sur la classe******\n\n");
            printf("Code: %d\n",classe.code);
            printf("Nom: %s\n",classe.nom);
            printf("Niveau: %d\n",classe.niveau);
        }

    }while(!feof(c));
    fclose(c);
}

// Ici notre procedure de suppression d'une classe


void suppression_classe()
{
    int code;
    char reponse;
    printf("Entrer le code de la matiere a supprimer: ");
    scanf("%d",&code);
    
    if(recherche_classe(code)==1)
    {
        printf("\n Voulez vous vraiment supprimer o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')// pour eliminer toutes ambiguités
        {
            FILE*cT,*c;
            c=fopen("Classe.csv","r");
            cT=fopen("ClasseT.csv","a");
            do
            {
                fscanf(c,"%d ; %s ; %u \n",&classe.code,classe.nom,&classe.niveau);
                fflush(stdin);
                if(code!=classe.code)
                {
                   fprintf(cT,"%d ; %s ; %d \n",classe.code,classe.nom,classe.niveau);
                }
            }while(!feof(c));
            fclose(cT);
            fclose(c);
            remove("Classe.csv");
            rename("ClasseT.csv","Classe.csv");
            printf("\nSuppression effectuee avec succees\n");

        }
    }else printf("\nCe code n'existe pas\n");
}

//Ici la modification d'une classe

void modification_classe()
{
    FILE*c,*cT;
    int code;
    char reponse;
    printf("Entrer le code de la classe a modifier: ");
    scanf("%d",&code);
    getchar();
    if(recherche_classe(code)==1)
    {
        printf("\n Voullez vous vraiment modifier les informations de cette classe o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            c=fopen("Classe.csv","r");
            cT=fopen("ClasseT.csv","a");
            do
            {
                fscanf(c,"%d ; %s ; %u \n",&classe.code,classe.nom,&classe.niveau);
                fflush(stdin);
                if(code==classe.code)
                {
                    
                    printf("Entrer le nouveau nom: ");
                    gets(classe.nom);
                    printf("Entrer le nouveau niveau: ");
                    scanf("%u",&classe.niveau);
                    
                }
                fprintf(cT,"%d ; %s ; %d \n",classe.code,classe.nom,classe.niveau);
            

            }while(!feof(c));
            fclose(c);
            fclose(cT);
            remove("Classe.csv");
            rename("ClasseT.csv","Classe.csv");
            printf("\n La modification a Reussi\n");
        }else printf("\nLa modification est annulee\n");
    }else printf("Ce code n'existe pas");
    
}

// Procedure d'affichage de la liste des classes

void afficher_classes()
{
    FILE*c;
    c=fopen("Classe.csv","r");
    printf("\n Voici la liste des Classes\n\n");

    do
    {
        fscanf(c,"%d ; %s ; %u \n",&classe.code,classe.nom,&classe.niveau);
        fflush(stdin);
        printf("%d\t",classe.code);
        printf("%s\t",classe.nom);
        printf("%d\t\n",classe.niveau);
    }while(!feof(c));
    fclose(c);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ici bas nous avons notre fonctions de recherche pour les etudiants (si l'etudiant existe ou pas)

int recherche_etudiant(int num_recherche)
{
    FILE*e;
    e=fopen("etudiant.csv","r");
    int i=0;

    do
    {
        fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
        fflush(stdin);
        if(etudiant.numero==num_recherche) 
        {
            i++;
        }

    }while(!feof(e));

    fclose(e);

    if(i!=0) return 1;
    else return -1;
}

// Ici nous avons la procedure d'ajout dans etudiant 

void ajout_etudiant()
{

    FILE*e;
    int numero;
    e=fopen("etudiant.csv","a");
    
    printf("\n Entrer le numero: ");
    scanf("%d",&numero);
    printf("Entrer le code de la classe: ");// Pour que l'utilisateur ne puisse pas entrer un code de classe qui n'existe pas ou pas encore
    scanf("%d",&etudiant.code);
    getchar();


    if (recherche_classe(etudiant.code)==1)
    {
        do
        {
            if (recherche_etudiant(numero)==1)
            {
                printf("\n Ce numero existe deja");
                printf("\n Entrer un nouveau numero: ");
                scanf("%d",&numero);
            }else break;
                    
        }while(recherche_etudiant(numero)==1);

        
        etudiant.numero = numero;
        printf("Entrer son nom: ");
        gets(etudiant.nom);
        printf("Entrer son prenom: ");
        gets(etudiant.prenom);
        printf("Entrer son email: ");
        gets(etudiant.email);
        printf("Jour de naissance: ");
        scanf("%d",&etudiant.date.jour);
        printf("mois de naissance: ");
        scanf("%d",&etudiant.date.mois);
        printf("annee de naissance: ");
        scanf("%d",&etudiant.date.An);

        fprintf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,etudiant.date.jour,etudiant.date.mois,etudiant.date.An,etudiant.code);
        fclose(e);
        printf("Information enregistrer avec succes\n\n");

    }else printf("\n\n Cette classe n'existe pas encore. Merci de le creer\n");

}

// Ici la procedure d'affichage d'un etudiant

void affichage_etudiant()
{
    int numero;
    printf("Entrer le numero de l'etudiant: ");
    scanf("%d",&numero);
    FILE*e;
    e=fopen("etudiant.csv","r");
    if (recherche_classe(etudiant.code)==1)
    {
        do
        {
            fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
            fflush(stdin);
            if(numero==etudiant.numero)
            {
                printf("\n******Information sur l'etudiant******\n\n");
                printf("Numero: %d  ",etudiant.numero);
                printf("Nom: %s  ",etudiant.nom);
                printf("Prenom: %s  ",etudiant.prenom);
                printf("email: %s  ",etudiant.email);
                printf("Date de naissance: %d-%d-%d  ",etudiant.date.jour,etudiant.date.mois,etudiant.date.An);
                printf("Code classe: %d  ",etudiant.code);
            }else continue;

        }while(!feof(e));
    }else printf("\nCet etudiant n'existe pas encore merci de le creer\n");
    fclose(e);
}

// Ici notre procedure de suppression d'un etudiant
/*Pour cela nous allons creer un autre fichier et y mettre tous les informations sauf celui qu'on ve supprimer puis on supprimer l'ancien
pour renomer le nouveau avec le nom de l'ancien  */

void suppression_etudiant()
{
    int numero;
    char reponse;
    printf("Entrer le numero de l'etudiant a supprimer: ");
    scanf("%d",&numero);
    
    if(recherche_etudiant(numero)==1)
    {
        printf("\n Voulez vous vraiment supprimer o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            FILE*eT,*e;
            e=fopen("etudiant.csv","r");
            eT=fopen("etudiantT.csv","a");
            do
            {
                fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
                fflush(stdin);
                if(numero!=etudiant.numero)
                {
                    fprintf(eT,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,etudiant.date.jour,etudiant.date.mois,etudiant.date.An,etudiant.code);
                }
            }while(!feof(e));
            fclose(eT);
            fclose(e);
            remove("etudiant.csv");
            rename("etudiantT.csv","etudiant.csv");
            printf("\nSuppression effectuee avec succees\n");

        }
    }else printf("\nCe numero n'existe pas\n");
}

//Ici la modification d'un etudiant

void modification_etudiant()
{
    int numero;
    char reponse;
    printf("Entrer le numero de l'etudiant a modifier: ");
    scanf("%d",&numero);
    if(recherche_etudiant(numero)==1)
    {
        printf("\n Voullez vous vraiment modifier les informations de cet etudiant o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            
            FILE*e,*eT;
            e=fopen("etudiant.csv","r");
            eT=fopen("etudiantT.csv","a");
            do
            {
                fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
                fflush(stdin);
                if(numero==etudiant.numero)
                {
                    
                    printf("Entrer le nouveau nom: ");
                    gets(etudiant.nom);
                    printf("Entrer le nouveau prenom: ");
                    gets(etudiant.prenom);
                    printf("Entrer le nouveau email: ");
                    gets(etudiant.email);
                    printf("Jour de naissance: ");
                    scanf("%d",&etudiant.date.jour);
                    printf("mois de naissance: ");
                    scanf("%d",&etudiant.date.mois);
                    printf("annee de naissance: ");
                    scanf("%d",&etudiant.date.An);
                    printf("Entrer le nouveau code classe: ");
                    scanf("%d",&etudiant.code);
                    do
                    {
                        if(recherche_classe(etudiant.code)==-1)
                        {
                            printf("\n Ce code n'existe pas");
                            printf("\n Entrer un nouveau code: ");
                            scanf("%d",&etudiant.code);
                        }else break;
                                
                    }while(recherche_classe(etudiant.code)==-1);
                    
                }
                fprintf(eT,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,etudiant.date.jour,etudiant.date.mois,etudiant.date.An,etudiant.code);

            }while(!feof(e));
            fclose(eT);
            fclose(e);
            remove("etudiant.csv");
            rename("etudiantT.csv","etudiant.csv");
            printf("\n La modification a Reussi\n");
        }else printf("\nLa modification est annulee\n");
    }else printf("Ce numero n'existe pas");
    
}

// Procedure d'affichage de la liste des etudiant

void afficher_etudiants()
{
    FILE*e;
    e=fopen("etudiant.csv","r");
    printf("\n Voici la liste des etudiants (num/nom/prenom/code_classe)\n\n");
    do
    {
        fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
        fflush(stdin);
        printf("%d\t",etudiant.numero);
        printf("%s\t",etudiant.nom);
        printf("%s\t",etudiant.prenom);
        printf("%s,\t",etudiant.email);
        printf("%d\n",etudiant.code);
    }while(!feof(e)); 
    fclose(e);
}

//////////////////////////////////////Affichage des etudiants d'une classe dont le code est fourni/////////////////////////

void etudiants_classe()
{
    int code;

    printf("\nEntrer le code de la classe en question:");
    scanf("%d",&code);

    if(recherche_classe(code)==1)
    {
        FILE*e;
        e=fopen("etudiant.csv","r");
        int k=0;
        do
        {
            fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
            fflush(stdin);
            printf("\n Voici les etudiants de cette classe (num/nom/prenom)\n");
            if(code==etudiant.code)
            {
                printf("%d\t",etudiant.numero);
                printf("%s\t",etudiant.nom);
                printf("%s\n",etudiant.prenom);
                k++;
            }
        } while (!feof(e));
        fclose(e);
        if(k==0) printf("\nil y'a aucun etudiant dans cette classe\n");
        
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ici bas nous avons notre fonctions de recherche pour les matieres

int recherche_matieres(int num_recherche)
{
    FILE*m;
    m=fopen("Matieres.csv","r");
    int i=0;
    do
    {
        fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
        fflush(stdin);
        if(matieres.reference==num_recherche) 
        {
            i++;
        }

    }while(!feof(m));

    fclose(m);
    if(i!=0) return 1;
    else return -1;
}

// Ici nous avons la procedure d'ajout de matieres 

void ajout_matiere()
{
    FILE*m;
    int reference;
    m=fopen("Matieres.csv","a");
    printf("\n Entrer la reference: ");
    scanf("%d",&reference);
    
    while(recherche_matieres(reference)==1)
    {
        printf("\n Cette reference existe deja");
        printf("\n Entrer un nouvelle reference: ");
        scanf("%d",&reference);
        getchar();
    }
    matieres.reference = reference;
    printf("Entrer son libelle: ");
    gets(matieres.libelle);
    printf("Entrer son coefficient: ");
    scanf("%hd",&matieres.coefficient);

    fprintf(m,"%d ; %s ; %hd \n",matieres.reference,matieres.libelle,matieres.coefficient);
    fclose(m);
    printf("Information enregistrer avec succes\n\n");
}

// Ici la procedure d'affichage d'une matieres

void affichage_matiere()
{
    int reference;
    printf("Entrer la reference de la matieres: ");
    scanf("%d",&reference);
    FILE*m;
    m=fopen("Matieres.csv","r");
    do
    {
        fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
        fflush(stdin);
        if(reference==matieres.reference)
        {
            printf("\n******Information sur la matieres******\n\n");
            printf("Reference: %d\n",matieres.reference);
            printf("Libelle: %s\n",matieres.libelle);
            printf("coefficient: %hd\n",matieres.coefficient);
        }

    }while(!feof(m));
    fclose(m);
}

// Ici notre procedure de suppression d'une matiere
/*Pour cela nous allons creer un autre fichier et y mettre tous les informations sauf celui qu'on ve supprimer puis on supprimer l'ancien
pour renomer le nouveau avec le nom de l'ancien  */

void suppression_matiere()
{
    int reference;
    char reponse;
    printf("Entrer la reference de la matiere a supprimer: ");
    scanf("%d",&reference);
    
    if(recherche_matieres(reference)==1)
    {
        printf("\n Voulez vous vraiment supprimer o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')// pour eliminer toutes ambiguités
        {
            FILE*mT,*m;
            m=fopen("Matieres.csv","r");
            mT=fopen("MatieresT.csv","a");
            do
            {
                fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
                fflush(stdin);
                if(reference!=matieres.reference)
                {
                   fprintf(mT,"%d ; %s ; %hd \n",matieres.reference,matieres.libelle,matieres.coefficient);
                }
            }while(!feof(m));
            fclose(mT);
            fclose(m);
            remove("Matieres.csv");
            rename("MatieresT.csv","Matieres.csv");
            printf("\nSuppression effectuee avec succees\n");

        }
    }else printf("\nCette reference n'existe pas\n");
}

//Ici la modification d'une matiere

void modification_matiere()
{
    int reference;
    char reponse;
    printf("Entrer le reference de la matiere a modifier: ");
    scanf("%d",&reference);
    if(recherche_matieres(reference)==1)
    {
        printf("\n Voullez vous vraiment modifier les informations de cette matiere o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            FILE*m,*mT;
            m=fopen("Matieres.csv","r");
            mT=fopen("MatieresT.csv","a");
            do
            {
                fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
                fflush(stdin);
                if(reference==matieres.reference)
                { 
                    
                    printf("Entrer le nouveau libelle: ");
                    gets(matieres.libelle);
                    printf("Entrer le nouveau coefficient: ");
                    scanf("%hd",&matieres.coefficient);
                    
                }
                fprintf(mT,"%d ; %s ; %hd \n",matieres.reference,matieres.libelle,matieres.coefficient);
            

            }while(!feof(m));
            fclose(m);
            fclose(mT);
            remove("Matieres.csv");
            rename("MatieresT.csv","Matieres.csv");
            printf("\n La modification a Reussi\n");
        }else printf("\nLa modification est annulee\n");
    }else printf("Cette reference n'existe pas");
    
}

// Procedure d'affichage de la liste des matieres

void afficher_matieres()
{
    FILE*m;
    m=fopen("Matieres.csv","r");
    printf("\n Voici la liste des Matieres(reference/libelle)\n\n");
    do
    {
        fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
        fflush(stdin);
        printf("%d\t",matieres.reference);
        printf("%s\t",matieres.libelle);
    }while(!feof(m));
    fclose(m);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// La relation se_faire/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 
{
    int reference;
    int code;

}faire;

faire se_faire;

int recherche_sefaire(int reference_matiere,int code_classe)
{
    FILE*s;
    s=fopen("Se_faire.csv","r");
    int i=0;
    do
    {
        fscanf(s,"%d ; %d \n",&se_faire.reference,&se_faire.code);
        fflush(stdin);
        if(se_faire.reference==reference_matiere && se_faire.code==code_classe )
        {
        i++;
        }
            
    }while(!feof(s));

    fclose(s);
    if(i!=0) return 1;
    else return -1;
}

/// Associer une matiere a une classe ////////////

void associer()
{
    int reference,code;
    printf("Entrer la reference de la matiere: ");
    scanf("%d",&reference);
    printf("Entrer le code de la classe: ");
    scanf("%d",&code);



    if(recherche_matieres(reference)==1 && recherche_classe(code)==1)
    {
        if(recherche_sefaire(reference,code)==1) printf("Cette matiere est deja associe a cette classe");
        else
        {
            FILE*s;
            s=fopen("Se_faire.csv","a");
            fprintf(s,"%d ; %d \n",reference,code);
            printf("Association effectue avec succee\n");
            fclose(s);
        }
                
    }

    if(recherche_matieres(reference)==-1) printf("Cette matieres n'existe pas encore, Merci de l'ajouter d'abord\n");
           
    if(recherche_classe(code)==-1) printf("Cette classe n'existe pas encore, Merci de l'ajouter d'abord\n");
    

    

}
////////////////////////////////////////////dissocier matiere///////////////////////////////////////

void dissocier()
{
    int code,reference;
    char reponse;
    printf("Entrer la reference de la matiere: ");
    scanf("%d",&reference);
    printf("Entrer le code de la classe: ");
    scanf("%d",&code);
    if(recherche_sefaire(reference,code)==1)
    {
        printf("voulez vous vraiment dissocier cette matiere de cette classe?? o/n: ");
        scanf("%c",&reponse);

        if(reponse=='o' || reponse=='O')
        {
            FILE*sT,*s;
            s=fopen("Se_faire.csv","r");
            sT=fopen("Se_faireT.csv","a");
            do
            {
                fscanf(s,"%d ; %d \n",&se_faire.reference,&se_faire.code);
                fflush(stdin);
                if(reference!=se_faire.reference || code!=se_faire.code)
                {
                    fprintf(sT,"%d ; %d \n",se_faire.reference,se_faire.code);
                }
            }while(!feof(s));
            fclose(sT);
            fclose(s);
            remove("Se_faire.csv");
            rename("Se_faireT.csv","Se_faire.csv");
            printf("Dissociation effectue avec succee\n");
        }
        
    }else printf("Cette association n'existe pas encore");

}

/////////////////////////////////////////voir les associations////////////////////////////////////////

void voir_association()
{
    int code;
    int k=0;

    printf("Entrer le code de la classe: ");
    scanf("%d",&code);
    printf("La classe(code=%d): est associe a:\n",code);
    
    FILE*s;
    s=fopen("Se_faire.csv","r");
    do
    {
        fscanf(s,"%d ; %d \n",&se_faire.reference,&se_faire.code);
        fflush(stdin);
        if(code==se_faire.code) 
        {
            printf("ref(matiere): %d\n",se_faire.reference);
            k++;/// voir if ci dessous pour comprendre
        }
    } while (!feof(s));
    fclose(s);
    if(k==0) printf("\nCette classe n'est associe a aucune matiere\n");
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Ici nous avons tous ce qui concerne les Notes///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct
{
    int numero;
    int reference;
    float note_CC;
    float note_DS;
}Notes;


Notes notes;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////recherch_notes/////////////////////////////////////////////////////////////////////

int recherche_notes(int reference_matiere ,int numero_etudiant)
{
    FILE*n;
    n=fopen("Notes.csv","r");
    int i=0;
    do
    {
        fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
        fflush(stdin);
        if(notes.reference==reference_matiere && notes.numero== numero_etudiant)
        {
            i++;
            break;
        }else continue;
            
    }while(!feof(n));

    fclose(n);
    if(i!=0) return 1;
    else return -1;
}


/////////////// ajout notes etudiant dans plusieurs matieres ////////////

void ajout_notes()
{
    int reference,numero;
    printf("Entrer le numero de l'etudiant: "); //Je l'ai pas mis dans la boucle pour permettre à l'utilisateur
    scanf("%d",&numero);                  //de pouvoir entrer des notes de cette etudiant dans plusieurs matiéres sans avoir a ressaisir son numero     
    FILE*n;
    n=fopen("Notes.csv","a");

    char reponse;
    do
    {
        printf("Entrer la reference de la matiere: ");
        scanf("%d",&reference);

        if (recherche_matieres(reference)==1 && recherche_etudiant(numero)==1)
        {
            if (recherche_notes(reference,numero)==1) printf("Cet etudiant a deja ses notes. si voulez le modifier retourner au sous menu\n");
            else
            {
                notes.reference=reference;
                notes.numero=numero;
                printf("Entrer la note de DS: ");
                scanf("%g",&notes.note_DS);
                printf("Entrer la note de CC: ");
                scanf("%g",&notes.note_CC);

                fprintf(n,"%d ; %d ; %g ; %g \n",notes.reference,notes.numero,notes.note_DS,notes.note_CC);
                fclose(n);
                printf("Notes enregistres avec succees\n");
            }
            
        }
        if(recherche_matieres(reference)==-1) printf("Cette matieres n'existe pas encore,Merci de l'ajouter d'abord\n");
            
        if(recherche_etudiant(numero)==-1) printf("Cet etudiant n'existe pas encore. Merci de l'ajouter d'abord\n");
        printf("Voulez vous ajouter d'autres notes a cet etudiant encore?? o/n: ");
        scanf("%c",&reponse);
    }while(reponse=='o' || reponse=='O');
    
}
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////ajout des notes d'une classe dans une matiere///////////////////


void ajout_notes_classe()
{
    int reference,numero;
    printf("Entrer la reference de la matiere: ");
    scanf("%d",&reference);

    FILE*n,*e;
    e=fopen("etudiant.csv","r");
    n=fopen("Notes.csv","a");

    if (recherche_matieres(reference)==1)
    {

        do
        {
            fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
            fflush(stdin);

            if(recherche_sefaire(reference,etudiant.code)==1)
            {
                numero = etudiant.numero;
                printf("Etudiant(num=%d)\n",numero);
                if (recherche_notes(reference,numero)==1) printf("l'etudiant a deja ses notes\n");
                else
                {
                    printf("Entrer la note de DS: ");
                    scanf("%g",&notes.note_DS);
                    printf("Entrer la note de CC: ");
                    scanf("%g",&notes.note_CC);

                    fprintf(n,"%d ; %d ; %g ; %g \n",reference,numero,notes.note_DS,notes.note_CC);
                    printf("Notes enregistres avec succees\n");                     
                }
            }else continue;     
        }while(!feof(e));
    }
    else printf("Cette matieres n'existe pas encore,Merci de l'ajouter d'abord\n");

    fclose(e);
    fclose(n);    
}
//////////////////////////////////////////////////////////////////////////////
////////////ajout notes d'un etudiant dans toutes ces matieres///////////////

void ajout_etudiants_matiere()
{
    int numero,reference;
    int code;
    printf("Entrer le numero de l'etudiant: ");
    scanf("%d",&numero);
    printf("Entrer le code classe de l'etudiant: ");
    scanf("%d",&code);

    FILE*n,*m;
    m=fopen("Matieres.csv","r");
    n=fopen("Notes.csv","a");

    if (recherche_etudiant(numero)==1)
    {
        do
        {
            fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
            fflush(stdin);

            reference = matieres.reference;
            if(recherche_sefaire(reference,code)==1)
            { 
                if (recherche_notes(reference,numero)==1) printf("Cet etudiant a deja ses notes\n");
                else
                {                            
                    printf("Entrer la note de DS: ");
                    scanf("%g",&notes.note_DS);
                    printf("Entrer la note de CC: ");
                    scanf("%g",&notes.note_CC);

                    fprintf(n,"%d ; %d ; %g ; %g \n",reference,numero,notes.note_DS,notes.note_CC);
                    printf("Notes enregistres avec succees\n");                    
                }
            }else continue;   

        }while(!feof(m));
    }
    else printf("Cet etudiant n'existe pas encore,Merci de l'ajouter d'abord\n");

    fclose(n);    
    fclose(m);    
}
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////Affichage notes/////////////////////////////////////////////////


////////affichage notes etudiant une matiere////////////////

void notes_etudiant_matiere ()
{
    int numero,reference;
    printf("Entrer le numero de l'etudiant: "); 
    scanf("%d",&numero);
     
    printf("Entrer la reference de la matiere: ");
    scanf("%d",&reference);
    if (recherche_matieres(reference)==1 && recherche_etudiant(numero)==1)
    {
        FILE*n;
        n=fopen("Notes.csv","r");
        
        int j=0;
        do
        {
            
            fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
            fflush(stdin);
            if (reference==notes.reference && numero==notes.numero)
            {
                printf("\nVoici les notes de l'etudiant(num) %d concernant la matiere(ref)%d:\n",numero,reference);

                printf("Note DS: %g\n",notes.note_DS);
                printf("Note cc: %g\n",notes.note_CC);
                j++;
            }
                
        }while(j!=1);// il s'agit d'une seule affichage alors inutile de le laisser tourner jusqu'à la fin du fichier
        if(j==0) printf("\nCet etudiant n'a pas encore de notes dans cette matiere\n"); 
        
        fclose(n);
    }
    if(recherche_matieres(reference)==-1) printf("Cette matieres n'existe pas encore,Merci de l'ajouter d'abord\n");
    if(recherche_etudiant(numero)==-1) printf("Cet etudiant n'existe pas encore. Merci de l'ajouter d'abord\n");
    
}
//////////////////////////////affichage notes etudiant matieres/////////////////////////

void notes_etudiant_matieres()
{
    int numero,reference;
    printf("Entrer le numero de l'etudiant: "); 
    scanf("%d",&numero);

    FILE*n,*m;
    m=fopen("Matieres.csv","r");
    n=fopen("Notes.csv","r");
    if(recherche_etudiant(numero)==1)
    {
        do
        {
            fscanf(m,"%d ; %s ; %hd \n",&matieres.reference,matieres.libelle,&matieres.coefficient);
            fflush(stdin);
            reference = matieres.reference;
            if (recherche_notes(reference,numero)==1)
            {
                int j=0;
                do
                {
                    fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
                    fflush(stdin);
                    if(reference==notes.reference && numero==notes.numero)
                    {
                        j++;       
                        printf("\nVoici les notes de l'etudiant %d concernant la matiere%d:\n",notes.numero,notes.reference);

                        printf("Note DS: %g\n",notes.note_DS);
                        printf("Note cc: %g\n",notes.note_CC);
                    }
                
                        
                }while(j!=1);// il s'agit d'une seule affichage alors inutile de le laisser tourner jusqu'à la fin du fichier
            }else continue; 
        }while(!feof(m));
        fclose(n);
        fclose(m);
    }else printf("\nCet etudiant n'existe pas encore, Merci de l'ajouter\n");
}
//////////////////////////affichage notes classe //////////////////////////////
void notes_etudiants_matiere()
{
    int reference,numero;
    printf("Entrer la reference de la matiere: ");
    scanf("%d",&reference);
    if(recherche_matieres(reference)==1)
    {
        FILE*n,*e;
        e=fopen("etudiant.csv","r");
        n=fopen("Notes.csv","r");
        do
        {
            fscanf(e,"%d ; %s ; %s ; %s ; %d ; %d ; %d ; %d \n",&etudiant.numero,etudiant.nom,etudiant.prenom,etudiant.email,&etudiant.date.jour,&etudiant.date.mois,&etudiant.date.An,&etudiant.code);
            fflush(stdin);
            
            if(recherche_sefaire(reference,etudiant.code)==1)
            {
                numero = etudiant.numero ;
                if(recherche_notes(reference,numero)==1)
                {
                    int j=0;
                    do
                    {
                        fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
                        fflush(stdin);
                        j++;       
                        printf("\nVoici les notes de l'etudiant %d\n",notes.numero);

                        printf("Note DS: %g\n",notes.note_DS);
                        printf("Note cc: %g\n",notes.note_CC);
                        
                    }while(j!=1);// il s'agit d'une seule affichage alors inutile de le laisser tourner jusqu'à la fin du fichier
                } 
            }else continue;
        }while(!feof(e));
        fclose(e);
        fclose(n);
    }else printf("\nCette reference n'existe pas encore, Merci de le céer\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////Modification notes////////////////////////////////////////////////////////////


void modification_notes()
{
    char reponse;
    int reference;
    int numero;

    printf("Entrer le reference de la matiere: ");
    scanf("%d",&reference);
    printf("Entrer le numero de l'etudiant: ");
    scanf("%d",&numero);
    if(recherche_notes(reference,numero)==1)
    {
        printf("\n Voullez vous vraiment modifier les informations de ces notes o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            FILE*n,*nT;
            n=fopen("Notes.csv","r");
            nT=fopen("NotesT.csv","a");
            do
            {
                fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
                fflush(stdin); 
                if(reference==notes.reference && numero==notes.numero)              
                {                   
                    printf("Entrer la nouvelle note de DS: ");
                    scanf("%g",&notes.note_DS);
                    printf("Entrer la nouvelle note de CC: ");
                    scanf("%g",&notes.note_CC);  
                }
                fprintf(nT,"%d ; %d ; %g ; %g \n",notes.reference,notes.numero,notes.note_DS,notes.note_CC);

            }while(!feof(n));
            fclose(nT);
            fclose(n);
            remove("Notes.csv");
            rename("NotesT.csv","Notes.csv");
            printf("\n La modification a Reussi\n");
        }else printf("\nLa modification est annulee\n");
    }else printf("\nIl y'a pas de notes en rapport avec cette reference et ce numero\n");
}   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////Suppressions notes/////////////////////////////////////////////////////////////////////////

void suppression_notes()
{
    char reponse;
    int reference;
    int numero;

    printf("Entrer le reference de la matiere: ");
    scanf("%d",&reference);
    printf("Entrer le numero de l'etudiant: ");
    scanf("%d",&numero);
    getchar();
    if(recherche_notes(reference,numero)==1)
    {
        printf("\n Voullez vous vraiment modifier les informations de ces notes o/n: ");
        scanf("%c",&reponse);
        
        if(reponse=='o'|| reponse=='O')
        {
            FILE*n,*nT;
            n=fopen("Notes.csv","r");
            nT=fopen("NotesT.csv","a");
            do
            {
                fscanf(n,"%d ; %d ; %g ; %g \n",&notes.reference,&notes.numero,&notes.note_DS,&notes.note_CC);
                fflush(stdin);
                if(reference!=notes.reference || numero!=notes.numero)   
                {
                    fprintf(nT,"%d ; %d ; %g ; %g \n",notes.reference,notes.numero,notes.note_DS,notes.note_CC);
                }
            
            }while(!feof(n));
            fclose(nT);
            fclose(n);
            remove("Notes.csv");
            rename("NotesT.csv","Notes.csv");
            printf("\n la suppression a Reussi\n");
        }else printf("\nla suppression est annulee\n");
    }else printf("\nIl y'a pas de notes en rapport avec cette reference et ce numero\n");
}

#endif