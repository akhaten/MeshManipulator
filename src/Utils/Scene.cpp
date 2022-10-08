//
// Created by akhaten on 9/1/22.
//

#include "Scene.hpp"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::addDrawable(Drawable *drawable)
{
    this->drawables.push_back(drawable);
}

void Scene::draw()
{
    for(unsigned int index = 0; index < this->drawables.size(); ++index)
        this->drawables[index]->draw();
}
