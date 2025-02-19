# Jeu de Tri avec Piles

## Description
Ce projet implémente un jeu de tri basé sur deux piles, `a` et `b`. L'objectif est de trier les nombres contenus dans la pile `a` en utilisant un ensemble d'opérations prédéfinies.

## Règles du Jeu
- **Au départ** :
  - La pile `a` contient une quantité aléatoire de nombres négatifs et/ou positifs uniques.
  - La pile `b` est vide.
- **Objectif** : Trier la pile `a` en ordre croissant en déplaçant des éléments entre les piles et en appliquant les opérations suivantes :

### Opérations disponibles

#### Swap
- `sa` : Intervertit les deux premiers éléments de la pile `a`.
- `sb` : Intervertit les deux premiers éléments de la pile `b`.
- `ss` : Applique `sa` et `sb` simultanément.

#### Push
- `pa` : Prend le premier élément de `b` et le met sur `a`.
- `pb` : Prend le premier élément de `a` et le met sur `b`.

#### Rotate
- `ra` : Fait tourner `a` vers le haut (le premier élément devient le dernier).
- `rb` : Fait tourner `b` vers le haut.
- `rr` : Applique `ra` et `rb` simultanément.

#### Reverse Rotate
- `rra` : Fait tourner `a` vers le bas (le dernier élément devient le premier).
- `rrb` : Fait tourner `b` vers le bas.
- `rrr` : Applique `rra` et `rrb` simultanément.

## Algorithme Utilisé
Le projet utilise un **algorithme de tri Greedy Sort**. L'idée principale est de calculer le coût de déplacement de chaque élément vers sa position correcte et d'effectuer les opérations de manière optimisée en choisissant toujours le mouvement ayant le coût minimal.

## Compilation et Exécution
### Compilation
Utilisation du Makefile avec `gcc` pour compiler le programme :
```sh
make
```

### Exécution
Lancez le programme :
```sh
./push_swap NB1 NB2 ... NBn
```

## Exemples d'Utilisation
### Exemple 1
#### Entrée :
```sh
Pile a : [3, 2, 5, 1, 4]
Pile b : []
```
#### Exécution des opérations :
```sh
pb
pb
ra
ra
pa
ra
pa
rra
rra
```
#### Résultat :
```sh
Pile a : [1, 2, 3, 4, 5]
Pile b : []
```

### Exemple 2
#### Entrée :
```sh
Pile a : [8, -3, 7, 2, -1]
Pile b : []
```
#### Exécution :
```sh
pb
pb
sa
rra
pa
pa
ra
```
#### Résultat :
```sh
Pile a : [-3, -1, 2, 7, 8]
Pile b : []
```
##Partie Bonus
Lancer le programme :

```sh
./checker NB1 NB2 ... NBn
```

Il doit ensuite attendre et lire des instructions sur l’entrée standard, chaque ins-
truction suivie par un ’\n’. Une fois toutes les instructions lues, le programme va
les exécuter sur la pile d’entiers passée en paramètre.

Si à la suite de l’exécution la pile a est bien triée et la pile b est vide, alors le
programme doit afficher "OK" suivi par un ’\n’ sur la sortie standard.

Sinon, il doit afficher "KO" suivi par un ’\n’ sur la sortie standard


##Exemple 
```sh
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>
```
## Auteur
Projet développé par **[Aurelien Fontaine]**.

