{ stdenv, fetchgit, cmake, lib }:

stdenv.mkDerivation rec {

    name = "OpenMesh";
    version = "9.0";

    src = fetchgit {
        url = "https://gitlab.vci.rwth-aachen.de:9000/OpenMesh/OpenMesh";
        rev = "adebfb1ec0c14a43f5503a2dfea3d76599eb28ab";
        sha256 = "sha256-IGh9pHD3IgcRF9hl1IbsNSihCzHRB7W4y91Qg/uJ+CY=";
    };

    nativeBuildInputs = [
        cmake
    ];

#    doCheck = false;

    meta = with lib; {
        description = ''
            A generic and efficient library that offers data
            structures for representing and manipulating polygonal meshes
        '';
        homepage = "https://www.graphics.rwth-aachen.de/software/openmesh/";
        license = with licenses; [ bsd3 ];
        platforms = platforms.all;
        # maintainers = [ maintainers.???? ];
  };

}