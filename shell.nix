
let

    pkgs = import <nixpkgs> {
        overlays = [];
    };

in

pkgs.mkShell {


    
    buildInputs = with pkgs; [

        # GLFW Dependencies
        ## glfw
        xorg.libX11
        xorg.libXrandr
        xorg.libXinerama
        xorg.libXcursor
        xorg.libXi
        xorg.libXext

        # GLM Dependencies
        ## glm
        ## Nothing

        # OPENMESH Dependencies
        ## Nothing

        # EIGEN Dependencies
        ## eigen
        ## Nothing

        # GLEW Dependencies
        ## glew
        # xlibsWrapper
        # libXmu
        # libXi

        # OPENGL Dependencies
        mesa
        glew

        # C++ Tools
        cmake
        gcc11

        # Qt
        # qt5.full
        # qtcreator

    ];

    #shellHook = ''
    #    export LD_LIBRARY_PATH=${pkgs.stdenv.cc.cc.lib}/lib:${pkgs.qt5.full}/lib:${pkgs.libGL}/lib
    #'';

}


