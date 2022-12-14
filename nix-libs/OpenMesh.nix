{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {

    name = "OpenMesh";
    version = "9.0";

    src = pkgs.fetchgit {
        url = "https://gitlab.vci.rwth-aachen.de:9000/OpenMesh/OpenMesh";
        # 8.1
        # rev = "db8c0608830ae7324b2b2e1d91e4db565b2d3eae";
        # sha256 = "sha256-ac3vMS4tolEdMCMMhAPRDaHPI6Xvb7Gq5xC+cH5gmD8=";
        # 9.0
        rev = "adebfb1ec0c14a43f5503a2dfea3d76599eb28ab";
        sha256 = "sha256-IGh9pHD3IgcRF9hl1IbsNSihCzHRB7W4y91Qg/uJ+CY=";
    };

    nativeBuildInputs = [
        pkgs.cmake
    ];

    # buildInputs = [
    #     pkgs.cmake
    # ];

    

    # configurePhase = ''
    #     mkdir -p build
    #     cd build
    #     cmake .. -DCMAKE_INSTALL_PREFIX=$out
    # '';

    # installPhase = ''
    #     make install
    # '';

}