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

Pour inclure du latex
\f[
              A_{m\times n} =
              \left[ {\begin{array}{cccc}
                a_{11} & a_{12} & \cdots & a_{1n}\\
                a_{21} & a_{22} & \cdots & a_{2n}\\
                \vdots & \vdots & \ddots & \vdots\\
                a_{m1} & a_{m2} & \cdots & a_{mn}\\
              \end{array} } \right]
          \f]
