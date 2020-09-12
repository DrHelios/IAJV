# IA Pour Les Jeux Vidéo

## State Machine

Machine à état de bucheron, pour récolter et raffiner du bois, ainsi que construire des maisons.
Positions X Y de la forêt, le stock et la menuiserie.
Implémentation d'attaques de loups par pourcentage de chance.
Etats d'**Idle**, **Déplacement** (pour stocker et raffiner), **Stockage**, **Fuite**, **Mort**.
**_Substate Machine_** pour construire des maisons.
Inputs en paramètre qui ont été testés : **200, 2, 2, 2, 4, 4, 6, 6**

### Debug 

#### Déplacement

A cause des positions en float, l'IA peut parfois dépasser la position de destination.
Ce bug est aléatoire et ne survient pas tout le temps.

#### Fonctions Génériques

Pour le traitement des cas dans la State Machine (Idle, Move, Etc.), nous avons utilisé un **Switch**
plutôt que par une **Méthode Générique** car cela nous posait problème avec le reste de l'implémentation.
Nous avons donc gardé ce switch par soucis de temps.

## GOAP

**Objectif :** Construire une maison

**Précondition 1 :** Avoir du bois raffiné
**Précondition 2 :** Avoir du bois brut
**Précondition 3 :** Avoir un bucheron disponible
**Précondition 4 :** Avoir de l'espace dans les poches
**Précondition 5 :** Avoir assez d'arbres dans la forêt

**Effet :** Couper du bois - ** Préconditions 3,4,5**
**Effet :** Obtenir du bois raffiné - ** Préconditions 2,3**
**Effet :** Construire une maison - ** Préconditions 1,3**
**Effet :** Stocker du bois - ** Préconditions 2,3**
**Effet :** Désassigner bucheron - ** Précondition 3**
**Effet :** Assigner bucheron - ** Précondition 3**
