{ pkgs ? import <nixpkgs> {} }:

# https://nixos.org/guides/nix-pills/garbage-collector.html
# Pour detruire le pat dan le store, il suffit juste
# de supprimer le "result" puis d'appeler le garbage collector
pkgs.stdenv.mkDerivation {

    name = "OpenMesh";
    # version = "8.1";

    src = pkgs.fetchgit {
        url = "https://gitlab.vci.rwth-aachen.de:9000/OpenMesh/OpenMesh";
        rev = "db8c0608830ae7324b2b2e1d91e4db565b2d3eae";
        sha256 = "sha256-ac3vMS4tolEdMCMMhAPRDaHPI6Xvb7Gq5xC+cH5gmD8=";
    };

    buildInputs = [
        pkgs.cmake
    ];

    configurePhase = ''
        mkdir -p build
        cd build
        cmake .. -DCMAKE_INSTALL_PREFIX=$out/OpenMesh
    '';

    installPhase = ''
        mkdir -p $out/OpenMesh
        make install
    '';

}