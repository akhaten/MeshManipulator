# MeshManipulator
A mesh manipulator with OpenGL and OpenMesh


Pour chaque vertex,
on prned le voisinage (premier anneau)
On calcule le cebtre de gravité

On fait le sommet diviser par la somme des voisin. Ça donne C_i
ole nouveau vertex est Vi' = alpha * Vi + (1 - alpha) * Ci


## Séance 1 : Lissage Laplacien

## Séance 2 : 

Séléctionnner un point et on afaecte sa valeur à 1.
Sélectionner un certain nombre d'anneau
Tous les sommet à la frontière on met 0.
Déformer le maillage en tirant le point.
On pondère par un fonction de transfert ()