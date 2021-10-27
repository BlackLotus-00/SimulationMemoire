# Simulation de la gestion du Memoire

***Projet ASE(Architecture des systemes d'exploitation): Simulation d'une gestion de la mémoire par pagination.***

**L’objectif du projet :**

La gestion de la mémoire par pagination désigne l’organisation de l’ensemble des programmes à savoir : le chargement, l'affichage de l’espace vide et de l’espace occupé par ces programmes, la suppression, la recherche d’un programme. Le but de ce projet est la création d’une application qui fait la simulation de la gestion de la mémoire par pagination.

***Description des fonctionnalités du programmes***

**Le système propose un menu dont les fonctionnalités attendues sont :**

*Charger un programme : création d’un nouveau programme définit par son nom et sa taille en registre et par sa liste des pages.*

*Afficher les pages vides*

*Afficher la lise des programmes*

*Chercher un programme*

*Afficher les programmes (avec affichage des pages occupées pour chaque programme)*

*Terminer l'exécution d'un programme*

*Afficher la mémoire centrale (état de mémoire)*

*Vider la mémoire : supprimer tous les programmes chargés*

*Quitter : sortir du programme et perdre l’état de la mémoire*

***Les structures de données utilisées***

L’implémentation est basée sur l’utilisation des listes chaînées. Une liste chainée est une structure de données dynamique qui représente un ensemble d’éléments de même taille et de même type. Chaque élément est défini par des variables et nécessairement une variable de type pointeur qui pointe vers l’élément suivant et le dernier élément a un pointeur nul.

**Dans ce projet, on a utilisé deux listes chainées :**

Une liste des pages libres contenant deux champs ***adresse*** : représente l’adresse de la page vide

*Page_svt : est un pointeur qui pointe vers la page libre suivante*

Liste des programmes représente une liste des listes (chaque programme contient une liste des pages) et contenant quatre champs : *nom : le nom du programme

*taille : la taille du programme donnée en nombre d’instructions tel que chaque cent instructions représentent une page occupée par un programme.*

*page_prog : est un pointeur pointant vers la liste des pages occupées par le programme.*

*prog_suiv : est un pointeur pointant vers le programme suivant*

On considère aussi que la mémoire centrale contient 25 pages et chaque page = 100 registres.

***Le langage utilisé***

L'implémentation du programme s’est appuyé sur le langage C qui est un langage de programmation impératif conçu pour la programmation système, tout en le compilant à l'aide de l’IDE (Environnement de développement intégré) Code::Blocks.
