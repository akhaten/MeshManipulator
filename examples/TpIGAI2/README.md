
# Compte rendu des fonctionnalités développées lors du tps


## Séance 1 : Lissage Laplacien

La fonctionnalité a été implémentée dans
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/MyViewer.cpp)

Pour chaque vertex, on prned le voisinage (anneau d'ordre 1).
On calcule le centroid ie on fait la moyenne des points dans l'anneau.
Le nouveau vertex est V_i' = alpha * V_i + (1 - alpha) * centroid_i  avec alpha dans ]0, 0.5[.

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/laplacian_smoothing.gif)


## Séance 2 : Obtenir n anneaux

La recherche d'anneaux a été implémentée dans
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/RingManager.cpp)

Pour chaque vertex, on prends l'anneau d'ordre 1 du vertex courant.
On enregistre ses vertex dans un ensemble.

Pour l'anneau d'ordre n, on prends tous les vertex de l'anneau n-1.
Puis on cherche l'anneau d'ordre 1 pour chaque vertex de l'anneau n-1
puis on mémorise ses vertex sans redondance. On veille également à éliminer
les vertex qui pourraient se trouve dans l'anneau n-1.
On a donc notre anneau d'ordre n.

## Séance 3 : Utiliser les anneaux pour appliquer une déformation

Les fonctionnalités de cette partie ont été implémentées dans 
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/RingManager.cpp)

### Déformation basique avec une fonction

Cette méthode ne nécessite pas de résoudre le système avec la matrice Laplacienne (Laplacian Matrix).
Grossièrement, l'algorithme (en pseudo code) appliqué pour une telle déformation est :

```
Hypothèse:
    - V : ensemble contenant les vertex contenus dans les anneaux
    - u : vecteur dans lequel on translate nos points (ie déformation locale du maillage)
    - f : une fonction tel que
            * f(0) = 1
            * f(1) = 0
            * strictement décroissante et continue sur [0, 1] 
    - no_ring : une fonction qui retourne le numéro de l'anneau d'un sommet
    
Pour chaque sommet v dans V:
    id_ring = no_ring(v)
    alpha = f(id_ring/N)
    v = v + alpha * u
```

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_function_following_laplacian_smooth.gif)

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_function.png)

### Déformation avec la matrice laplacienne (Laplacian Matrix)


Deux variantes ont été implémentées.

La méthode étant basé sur les poids que l'on utilise pour résoubre notre système, nous en utilisons deux sortes:

- l'inverse de la valance

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_valence_following_laplacian_smooth.png)

- la somme des cosinus à un coefficient près des angles opposés aux half-edges 

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_angle_following_laplacian_smooth.png)

Dans les deux cas, on résout un système de tel sort Lx = B avec:
- L : la matrice Laplacienne avec les conditions de bord
- x : les coefficients recherchés pour la déformation
- B : le vecteur contenant que des 0 sauf à la ligne correspondant au vertex au centre des anneaux


## Key Mapping

- Left Shift + Mouve mouse : Bouge la caméra autour d'un point cible
- 1 : Applique un lissage laplacien
- 2 : Deformation avec une fonction (f(x) = (1-x²)²)
- 3 : Déformation en résolvant la matrice laplacienne et avec comme poids l'inverse de la somme des cosinus des angles opposés aux half-edges.
- 4 : Déformation en résolvant la matrice laplacienne et avec comme poids l'inverse de la valence
- Up (flèche vers le haut) : Avance la caméra
- Down (flèche vers le bas) : Recule la caméra