//
// Created by akhaten on 9/2/22.
//

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#import <GL/glew.h>

class Texture
{

public:
    Texture(char* path_texture);
    ~Texture();
    void use();

private:


};

#endif // TEXTURE_HPP
