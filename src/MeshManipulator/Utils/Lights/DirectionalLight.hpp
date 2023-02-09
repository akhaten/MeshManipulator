//
// Created by akhaten on 1/19/23.
//

#ifndef DIRECTIONAL_LIGHT_HPP
#define DIRECTIONAL_LIGHT_HPP

#include "MeshManipulator/Utils/Lights/Light.hpp"


class DirectionalLight :
    public Light
{

    private:
        /**
         * Direction of light
         */
        glm::vec3 direction;

    public:

        /**
         * Set new direction
         * @param direction : new direction
         */
        void setDirection(glm::vec3 direction);

        /**
         * Get direction
         * @return direction of light
         */
        glm::vec3 getDirection();

};

#endif //DIRECTIONAL_LIGHT_HPP
