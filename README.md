# MeshManipulator

A mesh manipulator with OpenGL and OpenMesh.

## Dependencies

- [glew v2.2.0](https://glew.sourceforge.net/install.html)
- [OpenMesh v9.0](https://gitlab.vci.rwth-aachen.de:9000/OpenMesh/OpenMesh)
- [glfw v3.3.8](https://www.glfw.org/)
- [Eigen v3.4.0](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [glm v0.9.9.8](https://github.com/g-truc/glm)

## Build and Compilation

### If you use NixOS (Recommended)

OpenMesh is not in [nixpkgs](https://search.nixos.org/packages) but he is packaged in 
[nix-libs/OpenMesh.nix](https://github.com/akhaten/MeshManipulator/blob/main/nix-libs/OpenMesh.nix).

So, just run command to build a dev environment and you will run examples:
```
nix-shell shell.nix
```

### Other distribution

You must clone and build the dependencies.

```
cd MeshManipulator
mkdir build
cd build
cmake ..
make

```

### Compilation

Exemples :
- [TP IGAI](https://github.com/akhaten/MeshManipulator/tree/main/examples/TpIGAI2)


