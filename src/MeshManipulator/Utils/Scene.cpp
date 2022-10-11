//
// Created by akhaten on 9/1/22.
//

#include "Scene.hpp"
#include <iostream>

Scene::Scene() {}

Scene::~Scene() {}


void Scene::addDrawable(Drawable *drawable)
{
    this->drawables.push_back(drawable);
}

void Scene::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
}

void Scene::draw()
{
    ;
    for(unsigned int index = 0; index < this->drawables.size(); ++index)
    {
       
        this->drawables[index]->draw(
            this->viewer->projectionMatrix(),
            this->viewer->viewMatrix()
        );
    }
    
}
