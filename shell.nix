{ pkgs ? import <nixpkgs> {} }:

let
    OpenMesh = pkgs.callPackage ./nix-libs/OpenMesh {} ;
in

pkgs.mkShell {
# pkgs.stdenv.mkDerivation {

    buildInputs = with pkgs; [

        # GLFW Dependencies
        glfw
        # xorg.libX11
        # xorg.libXrandr
        # xorg.libXinerama
        # xorg.libXcursor
        # xorg.libXi
        # xorg.libXext

        # GLM Dependencies
        glm
        ## Nothing

        # OPENMESH Dependencies
        OpenMesh
        # (pkgs.callPackage ./nix-libs/OpenMesh.nix)
        ## Nothing

        # EIGEN Dependencies
        eigen
        ## Nothing

        # Assimp Dependencies
        assimp

        # GLEW Dependencies
        glew
        # xlibsWrapper
        # libXmu
        # libXi

        # OPENGL Dependencies
        mesa

        # C++ Tools
        cmake
        gcc11
        clang
        doxygen
        # valgrind

        # Qt
        # qt5.full
        # qtcreator

    ];

    #shellHook = ''
    #    export LD_LIBRARY_PATH=${pkgs.stdenv.cc.cc.lib}/lib:${pkgs.qt5.full}/lib:${pkgs.libGL}/lib
    #'';

}


