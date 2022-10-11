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

Renderer* Scene::getRenderer()
{
    return this->renderer;
}

void Scene::setViewer(Viewer* viewer)
{
    this->viewer = viewer;
    this->renderer= new Renderer(this->viewer);
}

void Scene::draw()
{

    for(auto drawable : this->drawables)
        this->renderer->render(drawable);
    
}
