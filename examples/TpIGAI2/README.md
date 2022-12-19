
# Compte rendu des fonctionnalités développées lors du tps


## Séance 1 : Lissage Laplacien

Pour chaque vertex, on prned le voisinage (anneau d'ordre 1).
On calcule le centroide ie on fait la moyenne des points dans l'anneau.
Le nouveau vertex est Vi' = alpha * Vi + (1 - alpha) * Ci  avec alpha dans ]0, 0.5[.

![](https://user-images.githubusercontent.com/60817301/208491180-d6b863dd-fb27-4386-a3c9-8bc45e7983b2.mp4)


## Séance 2 : Obtenir n anneaux

Pour chaque vertex, on prends l'anneau d'ordre 1 du vertex courant.
On enregistre ses vertex dans un ensemble.

Pour l'anneau d'ordre n, on prends tous les vertex de l'anneau n-1.
Puis on cherche l'anneau d'ordre 1 pour chaque vertex de l'anneau n-1
puis on mémorise ses vertex sans redondance. On veille également à éliminer
les vertex qui pourraient se trouve dans l'anneau n-1.
On a donc notre anneau d'ordre n.

## Séance 3 : Utiliser les anneaux pour appliquer une déformation.

### Déformation basique avec une fonction

Cette méthode ne nécessite pas de résoudre le système avec la matrice Laplacienne (Laplacian Matrix).
Grossièrement, l'algorithme (en pseudo code) appliqué pour une telle déformation est :

```
Hypothèse:
    - S : ensemble contenant les vertex contenu dans les anneaux
    - u : vecteur dans lequel on translate nos points (ie déformation locale du maillage)
    - f : une fonction tel que
            * f(0) = 1
            * f(1) = 0
            * strictement décorissante sur [0, 1] 
    - no_ring : une fonction qui retourne le numéro de l'anneau d'un sommet
    
Pour chaque sommet v dans V:
    id_ring = no_ring(v)
    alpha = f(id_ring/N)
    v = v + alpha * u
```

### Déformation avec la matrice laplacienne (Laplacian Matrix)


Deux variantes ont été implémentées.

La méthode étant basé sur les poids que l'on utilise pour résoubre notre système, nous en utilisons deux sortes:

- l'inverse de la valance


- la somme des cosinus à un coefficient près des angles opposés aux half-edges 


Dans les deux cas, on résout un système de tel sort Lx = B avec:
- L : la matrice Laplacienne avec les conditions de bord
- x : les coefficients rechechés pour la déformation
- B : le vecteur contenant que des 0 sauf à la ligne correspondant au vertex au centre des anneaux


