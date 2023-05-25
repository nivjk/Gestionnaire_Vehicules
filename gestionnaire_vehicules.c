#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MARQUES_COUNT 14
#define MODELES_COUNT 6
#define MAX_MARQUE_LENGTH 12
#define MAX_MODELE_LENGTH 20

char marques[MARQUES_COUNT][MAX_MARQUE_LENGTH] = {
        "RENAULT",
        "MERCOBENZ",
        "AUDI",
        "BMW",
        "PEUGEOT",
        "CITROEN",
        "VOLKSWAGEN",
        "LAMBO",
        "FEFE",
        "BUGATTI",
        "ALFAROMEO",
        "TOYOTA",
        "HYUNDAI",
        "HONDA"
};

char modeles[MARQUES_COUNT][MODELES_COUNT][MAX_MODELE_LENGTH] = {
        {"Clio", "Mégane", "Captur", "Kadjar", "Talisman", "Autres"},                   
        {"C-Class", "E-Class", "S-Class", "GLC", "GLE", "Autres"},                        
        {"A3", "A4", "A6", "Q5", "Q7", "Autres"},                                         
        {"3 Series", "5 Series", "7 Series", "X3", "X5", "Autres"},                       
        {"208", "308", "508", "3008", "5008", "Autres"},                                   
        {"C3", "C4", "C5", "C4 Cactus", "C3 Aircross", "Autres"},                          
        {"Golf", "Polo", "Passat", "T-Roc", "Tiguan", "Autres"},                           
        {"Aventador", "Huracán", "Urus", "Sian", "Countach", "Autres"},                    
        {"Fe-1", "Fe-2", "Fe-3", "Fe-4", "Fe-5", "Autres"},                                
        {"Chiron", "Veyron", "Divo", "Centodieci", "La Voiture Noire", "Autres"},           
        {"Giulia", "Stelvio", "Giulietta", "4C", "Tonale", "Autres"},                      
        {"Corolla", "Camry", "Rav4", "Yaris", "Land Cruiser", "Autres"},                    
        {"Tucson", "Kona", "Santa Fe", "Veloster", "IONIQ", "Autres"},                      
        {"Civic", "Accord", "CR-V", "Jazz", "HR-V", "Autres"}                               
};

typedef enum {
    BLANC, NOIR, GRIS, ARGENT, BLEU, ROUGE, MARRON, VERT, JAUNE, AUTRE
} couleurCarroserie;

typedef struct {
    char marque[50];
    char modele[50];
    char annee[50];
    couleurCarroserie couleur;
    char immatriculation[20];
    char proprietaire[50];
    char adresseProprietaire[100];
    int chevauxFiscaux;
} Vehicule;

typedef struct {
    Vehicule* vehicules;
    int capacite;
    int taille;
} ListeVehicules;

void supprimerVehicule(ListeVehicules* liste);
void modifierVehicule(ListeVehicules* liste);
void afficherStatistiques(ListeVehicules* liste);
void rechercherVehicule(ListeVehicules* liste);
void afficherMenu();
void afficherSeparateur();
void initialiserListeVehicules(ListeVehicules* liste);
void libererListeVehicules(ListeVehicules* liste);
void ajouterVehicule(ListeVehicules* liste);
void afficherListeVehicules(ListeVehicules* liste);
void listerVehiculesProprietaire(ListeVehicules* liste);
void listerVehiculesAdresse(ListeVehicules* liste);


int main() {
    ListeVehicules liste;
    initialiserListeVehicules(&liste);

    int choix = -1;

    while (choix != 0) {
        afficherMenu();
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVehicule(&liste);
                break;
            case 2:
                supprimerVehicule(&liste);
                break;
            case 3:
                modifierVehicule(&liste);
                break;
            case 4:
                afficherListeVehicules(&liste);
                break;
            case 5:
                afficherStatistiques(&liste);
                break;
            case 6:
                rechercherVehicule(&liste);
                break;
            case 7:
                listerVehiculesProprietaire(&liste);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }

    return 0;
}


void afficherMenu() {
    afficherSeparateur();
    printf("--- Menu ---\n");
    printf("1. Ajouter un véhicule\n");
    printf("2. Supprimer un véhicule\n");
    printf("3. Modifier un véhicule\n");
    printf("4. Afficher la liste complète des véhicules\n");
    printf("5. Afficher des statistiques\n");
    printf("6. Rechercher un véhicule\n");
    printf("7. Lister les véhicules d'un propriétaire\n");
    printf("0. Quitter\n");
    afficherSeparateur();
}

void afficherSeparateur() {
    printf("---------------------------------\n");
}

void ajouterVehicule(ListeVehicules* liste) {

    int tmp;
    int i, j;

    if (liste->taille == liste->capacite) {
        printf("La liste est pleine. Impossible d'ajouter un nouveau véhicule.\n");
        return;
    }

    Vehicule vehicule;

    printf("\n--- AJOUT D'UN NOUVEAU VEHICULE ---\n\n");
    
    

    printf("La marque du véhicule (");
    for (i = 0; i < MARQUES_COUNT - 1; i++) {
        printf("%d:%s, ", i,marques[i]);
    }
    printf("%d:%s",i,marques[i]);
    printf(") : ");
    scanf("%d", &tmp);
    strcpy(vehicule.marque, marques[tmp]);

    i = tmp;

    printf("Le modèle du véhicule (");
    for (j = 0; j < MODELES_COUNT-1; j++) {
        printf("%d:%s, ",j,modeles[i][j]);
    }
    
    printf("%d:%s",j,modeles[i][j]);
    printf(") : ");
    scanf("%d", &tmp);
    strcpy(vehicule.modele, modeles[i][tmp]);

    printf("Année: ");
    scanf("%s", vehicule.annee);

    printf("Couleur (0:BLANC, 1:NOIR, 2:GRIS, 3:ARGENT, 4:BLEU, 5:ROUGE, 6:MARRON, 7:VERT, 8:JAUNE, 9:AUTRE) : ");
    scanf("%d", &tmp);
    vehicule.couleur = (couleurCarroserie)tmp;

    printf("Immatriculation: ");
    scanf("%s", vehicule.immatriculation);

    printf("Propriétaire: ");
    scanf("%s", vehicule.proprietaire);

    printf("Adresse du propriétaire: ");
    scanf("%s", vehicule.adresseProprietaire);

    printf("Nombre de chevaux fiscaux: ");
    scanf("%d", &vehicule.chevauxFiscaux);

    liste->vehicules[liste->taille] = vehicule;
    liste->taille++;

    printf("Véhicule ajouté avec succès.\n");
}

void afficherListeVehicules(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Aucun véhicule à afficher.\n");
        return;
    }

    int i;

    printf("Liste des véhicules enregistrés:\n");
    for (i = 0; i < liste->taille; i++) {
        printf("Véhicule %d:\n", i + 1);
        printf("Marque: %s\n", liste->vehicules[i].marque);
        printf("Modèle: %s\n", liste->vehicules[i].modele);
        printf("Année: %s\n", liste->vehicules[i].annee);
        printf("Couleur: ");
        switch (liste->vehicules[i].couleur) {
            case BLANC:
                printf("BLANC\n");
                break;
            case NOIR:
                printf("NOIR\n");
                break;
            case GRIS:
                printf("GRIS\n");
                break;
            case ARGENT:
                printf("ARGENT\n");
                break;
            case BLEU:
                printf("BLEU\n");
                break;
            case ROUGE:
                printf("ROUGE\n");
                break;
            case MARRON:
                printf("MARRON\n");
                break;
            case VERT:
                printf("VERT\n");
                break;
            case JAUNE:
                printf("JAUNE\n");
                break;
            case AUTRE:
                printf("AUTRE\n");
                break;
        }
        printf("Immatriculation: %s\n", liste->vehicules[i].immatriculation);
        printf("Propriétaire: %s\n", liste->vehicules[i].proprietaire);
        printf("Adresse du propriétaire: %s\n", liste->vehicules[i].adresseProprietaire);
        printf("Chevaux fiscaux: %d\n", liste->vehicules[i].chevauxFiscaux);
        afficherSeparateur();
    }
}


void initialiserListeVehicules(ListeVehicules* liste) {
    liste->capacite = 100;
    liste->taille = 0;
    liste->vehicules = (Vehicule*)malloc(liste->capacite * sizeof(Vehicule));
}

void libererListeVehicules(ListeVehicules* liste) {
    free(liste->vehicules);
}

void supprimerVehicule(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Impossible de supprimer un véhicule.\n");
        return;
    }

    char immatriculation[20];
    printf("Immatriculation du véhicule à supprimer: ");
    scanf("%s", immatriculation);

    int i;
    int vehiculeTrouve = 0;

    for (i = 0; i < liste->taille; i++) {
        if (strcmp(liste->vehicules[i].immatriculation, immatriculation) == 0) {
            vehiculeTrouve = 1;
            break;
        }
    }

    if (vehiculeTrouve) {
        for (; i < liste->taille - 1; i++) {
            liste->vehicules[i] = liste->vehicules[i + 1];
        }

        liste->taille--;

        printf("Véhicule supprimé avec succès.\n");
    } else {
        printf("Véhicule introuvable.\n");
    }
}

void modifierVehicule(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Impossible de modifier un véhicule.\n");
        return;
    }

    char immatriculation[20];
    printf("Immatriculation du véhicule à modifier: ");
    scanf("%s", immatriculation);

    int i;
    int vehiculeTrouve = 0;
    int couleur;

    for (i = 0; i < liste->taille; i++) {
        if (strcmp(liste->vehicules[i].immatriculation, immatriculation) == 0) {
            vehiculeTrouve = 1;
            break;
        }
    }

    if (vehiculeTrouve) {
        printf("Nouvelle marque: ");
        scanf("%s", liste->vehicules[i].marque);

        printf("Nouveau modèle: ");
        scanf("%s", liste->vehicules[i].modele);

        printf("Nouvelle année: ");
        scanf("%s", liste->vehicules[i].annee);

        printf("Nouvelle couleur: ");
        scanf("%d", &couleur);
        liste->vehicules[i].couleur = (couleurCarroserie)couleur;

        printf("Véhicule modifié avec succès.\n");
    } else {
        printf("Véhicule introuvable.\n");
    }
}

void afficherStatistiques(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Aucun véhicule à analyser.\n");
        return;
    }

    int choix;

    printf("Statistiques:\n");
    printf("1. Nombre de véhicules par année\n");
    printf("2. Nombre de véhicules par couleur\n");
    printf("3. Retour\n");
    afficherSeparateur();
    printf("Votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            // Calculer le nombre de véhicules par année et afficher les résultats
            break;
        case 2:
            // Calculer le nombre de véhicules par couleur et afficher les résultats
            break;
        case 3:
            // Retour au menu principal
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
    }
}

void rechercherVehicule(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Aucun véhicule à rechercher.\n");
        return;
    }

    char critere[50];
    printf("Critère de recherche (immatriculation, marque, modèle): ");
    scanf("%s", critere);

    int i;

    printf("Résultats de la recherche:\n");
    for (i = 0; i < liste->taille; i++) {
        if (strcmp(critere, "immatriculation") == 0) {
            printf("Immatriculation: %s\n", liste->vehicules[i].immatriculation);
        } else if (strcmp(critere, "marque") == 0) {
            printf("Marque: %s\n", liste->vehicules[i].marque);
        } else if (strcmp(critere, "modèle") == 0) {
            printf("Modèle: %s\n", liste->vehicules[i].modele);
        } else {
            printf("Critère de recherche invalide.\n");
            break;
        }
    }
}

void listerVehiculesProprietaire(ListeVehicules* liste) {
    if (liste->taille == 0) {
        printf("La liste est vide. Aucun véhicule à rechercher.\n");
        return;
    }

    char proprietaireRecherche[50];
    printf("Nom du propriétaire : ");
    scanf("%s", proprietaireRecherche);

    int i;

    printf("Résultats de la recherche:\n");
    for (i = 0; i < liste->taille; i++) {
        if (strcmp(proprietaireRecherche, liste->vehicules[i].proprietaire) == 0) {
            printf("\n Véhicule %d : ", i);
            printf("Immatriculation: %s\n", liste->vehicules[i].immatriculation);
            printf("Marque: %s\n", liste->vehicules[i].marque);
            printf("Modèle: %s\n\n", liste->vehicules[i].modele);
        } else {
            printf("Critère de recherche invalide.\n");
            break;
        }
    }
}


