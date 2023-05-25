class Vehicule:
    def __init__(self, marque, modele, annee, couleur, immatriculation, proprietaire, adresse_proprietaire, chevaux_fiscaux):
        self.marque = marque
        self.modele = modele
        self.annee = annee
        self.couleur = couleur
        self.immatriculation = immatriculation
        self.proprietaire = proprietaire
        self.adresse_proprietaire = adresse_proprietaire
        self.chevaux_fiscaux = chevaux_fiscaux

class ListeVehicules:
    def __init__(self):
        self.vehicules = []

    def ajouter_vehicule(self, vehicule):
        self.vehicules.append(vehicule)

    def supprimer_vehicule(self, immatriculation):
        for vehicule in self.vehicules:
            if vehicule.immatriculation == immatriculation:
                self.vehicules.remove(vehicule)
                return True
        return False

    def modifier_vehicule(self, immatriculation, nouvelle_marque, nouveau_modele, nouvelle_annee):
        for vehicule in self.vehicules:
            if vehicule.immatriculation == immatriculation:
                vehicule.marque = nouvelle_marque
                vehicule.modele = nouveau_modele
                vehicule.annee = nouvelle_annee
                return True
        return False

    def afficher_liste_vehicules(self):
        if len(self.vehicules) == 0:
            print("La liste est vide. Aucun véhicule à afficher.")
        else:
            print("Liste des véhicules enregistrés:")
            for index, vehicule in enumerate(self.vehicules):
                print(f"Véhicule {index + 1}:")
                print(f"Marque: {vehicule.marque}")
                print(f"Modèle: {vehicule.modele}")
                print(f"Année: {vehicule.annee}")
                print(f"Immatriculation: {vehicule.immatriculation}")
                print(f"Propriétaire: {vehicule.proprietaire}")
                print(f"Adresse du propriétaire: {vehicule.adresse_proprietaire}")
                print(f"Chevaux fiscaux: {vehicule.chevaux_fiscaux}")
                print("--------------------")

    def rechercher_vehicule(self, critere):
        resultat = []
        for vehicule in self.vehicules:
            if critere in [vehicule.immatriculation, vehicule.marque, vehicule.modele]:
                resultat.append(vehicule)
        return resultat

    def lister_vehicules_proprietaire(self, proprietaire):
        resultat = []
        for vehicule in self.vehicules:
            if vehicule.proprietaire == proprietaire:
                resultat.append(vehicule)
        return resultat

    def afficher_statistiques(self):
        if len(self.vehicules) == 0:
            print("La liste est vide. Aucun véhicule à analyser.")
        else:
            print("Statistiques:")
            print("1. Nombre de véhicules par année")
            print("2. Nombre de véhicules par couleur")
            choix = input("Choisissez une option (1 ou 2): ")
            if choix == "1":
                statistiques = {}
                for vehicule in self.vehicules:
                    if vehicule.annee in statistiques:
                        statistiques[vehicule.annee] += 1
                    else:
                        statistiques[vehicule.annee] = 1
                print("Nombre de véhicules par année:")
                for annee, count in statistiques.items():
                    print(f"Année {annee}: {count} véhicules")
            elif choix == "2":
                statistiques = {}
                for vehicule in self.vehicules:
                    if vehicule.couleur in statistiques:
                        statistiques[vehicule.couleur] += 1
                    else:
                        statistiques[vehicule.couleur] = 1
                print("Nombre de véhicules par couleur:")
                for couleur, count in statistiques.items():
                    print(f"Couleur {couleur}: {count} véhicules")
            else:
                print("Option invalide.")

def afficher_menu():
    print("=== Menu ===")
    print("1. Ajouter un véhicule")
    print("2. Supprimer un véhicule")
    print("3. Modifier un véhicule")
    print("4. Afficher la liste des véhicules")
    print("5. Rechercher un véhicule par critères")
    print("6. Afficher les statistiques")
    print("7. Lister les véhicules d'un propriétaire")
    print("8. Quitter")

liste_vehicules = ListeVehicules()

while True:
    afficher_menu()
    choix = input("Choisissez une option (1-8): ")

    if choix == "1":
        marque = input("Marque du véhicule: ")
        modele = input("Modèle du véhicule: ")
        annee = input("Année du véhicule: ")
        couleur = input("Couleur du véhicule: ")
        immatriculation = input("Immatriculation du véhicule: ")
        proprietaire = input("Propriétaire du véhicule: ")
        adresse_proprietaire = input("Adresse du propriétaire: ")
        chevaux_fiscaux = input("Chevaux fiscaux du véhicule: ")

        vehicule = Vehicule(marque, modele, annee, couleur, immatriculation, proprietaire, adresse_proprietaire, chevaux_fiscaux)
        liste_vehicules.ajouter_vehicule(vehicule)
        print("Véhicule ajouté avec succès.")

    elif choix == "2":
        immatriculation = input("Immatriculation du véhicule à supprimer: ")
        if liste_vehicules.supprimer_vehicule(immatriculation):
            print("Véhicule supprimé avec succès.")
        else:
            print("Aucun véhicule correspondant à l'immatriculation spécifiée.")

    elif choix == "3":
        immatriculation = input("Immatriculation du véhicule à modifier: ")
        nouvelle_marque = input("Nouvelle marque du véhicule: ")
        nouveau_modele = input("Nouveau modèle du véhicule: ")
        nouvelle_annee = input("Nouvelle année du véhicule: ")
        if liste_vehicules.modifier_vehicule(immatriculation, nouvelle_marque, nouveau_modele, nouvelle_annee):
            print("Véhicule modifié avec succès.")
        else:
            print("Aucun véhicule correspondant à l'immatriculation spécifiée.")

    elif choix == "4":
        liste_vehicules.afficher_liste_vehicules()

    elif choix == "5":
        critere = input("Entrez un critère de recherche (immatriculation, marque ou modèle): ")
        resultats = liste_vehicules.rechercher_vehicule(critere)
        if len(resultats) == 0:
            print("Aucun véhicule correspondant au critère spécifié.")
        else:
            print("Résultats de recherche:")
            for index, vehicule in enumerate(resultats):
                print(f"Résultat {index + 1}:")
                print(f"Marque: {vehicule.marque}")
                print(f"Modèle: {vehicule.modele}")
                print(f"Année: {vehicule.annee}")
                print(f"Immatriculation: {vehicule.immatriculation}")
                print(f"Propriétaire: {vehicule.proprietaire}")
                print(f"Adresse du propriétaire: {vehicule.adresse_proprietaire}")
                print(f"Chevaux fiscaux: {vehicule.chevaux_fiscaux}")
                print("--------------------")

    elif choix == "6":
        liste_vehicules.afficher_statistiques()

    elif choix == "7":
        proprietaire = input("Entrez le nom du propriétaire: ")
        resultats = liste_vehicules.lister_vehicules_proprietaire(proprietaire)
        if len(resultats) == 0:
            print("Aucun véhicule trouvé pour le propriétaire spécifié.")
        else:
            print(f"Véhicules du propriétaire '{proprietaire}':")
            for index, vehicule in enumerate(resultats):
                print(f"Véhicule {index + 1}:")
                print(f"Marque: {vehicule.marque}")
                print(f"Modèle: {vehicule.modele}")
                print(f"Année: {vehicule.annee}")
                print(f"Immatriculation: {vehicule.immatriculation}")
                print(f"Propriétaire: {vehicule.proprietaire}")
                print(f"Adresse du propriétaire: {vehicule.adresse_proprietaire}")
                print(f"Chevaux fiscaux: {vehicule.chevaux_fiscaux}")
                print("--------------------")

    elif choix == "8":
        print("Programme terminé.")
        break

    else:
        print("Option invalide. Veuillez choisir une option valide.")