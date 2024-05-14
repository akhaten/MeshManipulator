
# Compte rendu des fonctionnalités développées lors des tps


## Séance 1 : Lissage Laplacien

La fonctionnalité a été implémentée dans
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/MyViewer.cpp)

Pour chaque sommet, nous prenons le voisinage (anneau d'ordre 1).
On calcule le centroid en calculant la moyenne des points dans l'anneau.
Le nouveau sommet est V_i' = alpha * V_i + (1 - alpha) * centroid_i  avec alpha dans ]0, 0.5[.

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/laplacian_smoothing.gif)


## Séance 2 : Obtenir n anneaux

La recherche d'anneaux a été implémentée dans
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/RingManager.cpp)

Pour chaque sommet, nous prenons l'anneau d'ordre 1 du sommet courant.
Nous enregistrons ses sommets dans un ensemble (collection contenant des objets de manière unique).

Pour l'anneau d'ordre n, nous cherchons l'anneau d'ordre 1 pour chaque sommet de l'anneau n-1.
Ensuite, nous mémorisons ses sommets sans redondance avec la propriété mathématique
d'un ensemble énoncée ci-dessus.

## Séance 3 : Utiliser les anneaux pour appliquer une déformation

Les fonctionnalités de cette partie ont été implémentées dans 
![RingManager.cpp](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/RingManager.cpp)

### Déformation basique avec une fonction

Cette méthode ne nécessite pas de résoudre le système avec la matrice Laplacienne (Laplacian Matrix).
Grossièrement, l'algorithme (en pseudo code) appliqué pour une telle déformation est :

```
Hypothèse:
    - V : ensemble contenant les vertex contenus dans les anneaux
    - u : vecteur par lequel on translate nos points (ie déformation locale du maillage)
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

La méthode étant basée sur les poids que nous utilisons pour résoudre notre système, nous en utilisons deux sortes:

- l'inverse de la valance

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_valence_following_laplacian_smooth.png)

- la somme des cosinus à un coefficient près des angles opposés aux half-edges 

![](https://github.com/akhaten/MeshManipulator/blob/main/examples/TpIGAI2/images/deformation_angle_following_laplacian_smooth.png)

Dans les deux cas, nous résolvons un système tel que Lx = B avec:
- L : la matrice laplacienne avec les conditions de bord
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