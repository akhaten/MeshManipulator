
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <OpenMesh/Core/Utils/PropertyManager.hh>

#include "MyViewer.hpp"


#include <iostream>

MyViewer::MyViewer(Camera* camera):
    Viewer(camera)
{

    this->sensitivity = 2.0f;
    this->radius = 0.01f;
    this->camera_mod = false;
    this->moveset_mode = false;
    /*this->camera->setPosition(
            this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
    );*/

}

MyViewer::~MyViewer() {}


void MyViewer::setWindow(GLFWwindow* window)
{
    this->window = window;
}

void MyViewer::setScene(Scene* scene)
{
    this->scene = scene;
}

void MyViewer::setObjectMesh(ObjectMesh* obj_mesh)
{
    this->obj_mesh = obj_mesh;
    this->ring_manager = new RingManager(this->obj_mesh);
}

/**
 * CALLBACK
 */

void MyViewer::processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    // ROTATION

    if(key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
    {
        this->camera_mod = true;

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        glfwGetCursorPos(window, &this->lastX, &this->lastY);

        int width, height;
        glfwGetWindowSize(window, &width, &height);
        glfwSetCursorPos(window, width/2, height/2);
        
    }

    if(key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE)
    {
        this->camera_mod = false;
        glfwSetCursorPos(window, this->lastX, this->lastY);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }


    // ZOOM
    float shift = 0.05f;
    if(key == GLFW_KEY_UP && action == GLFW_PRESS)
    {

        if(!this->moveset_mode){


            if(this->radius-shift < 0.0f){
                this->radius = 0.0f;
                this->camera->setPosition(
                        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                );
            }else if(this->radius > 0.0f) {
                this->radius -= shift;
                this->camera->setPosition(
                        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                );
            }

        }else{

            glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            target += glm::vec3(0.0f, shift, 0.0f);
            this->camera->setTarget(target);
            this->camera->setPosition(
                    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            );

        }

    }

    if(key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {

        if(!this->moveset_mode) {

            this->radius += shift;
            this->camera->setPosition(
                    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            );

        }else{

            glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            target += glm::vec3(0.0f, -shift, 0.0f);
            this->camera->setTarget(target);
            this->camera->setPosition(
                    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            );

        }

    }

    // MOVESET

    if(key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS)
    {
        this->moveset_mode = !this->moveset_mode;
    }

    if(this->moveset_mode && key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    {

        glm::vec3 target = this->camera->getTarget();
        //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
        target += glm::vec3(-shift, 0.0f, 0.0f);
        this->camera->setTarget(target);
        this->camera->setPosition(
            this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        );

    }

    if(this->moveset_mode && key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {

        glm::vec3 target = this->camera->getTarget();
        //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
        target += glm::vec3(shift, 0.0f, 0.0f);
        this->camera->setTarget(target);
        this->camera->setPosition(
            this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        );

    }

    // OPERATORS : LAPLACIAN & DEFORMATION

    if(key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        std::cout << "Begin Laplacian Smoothing" << std::endl;
        this->laplacian(this->obj_mesh, 0.3f);
        std::cout << "End Laplacian Smoothing" << std::endl;
    }

    if(key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        std::cout << "Begin Deformation (Function)" << std::endl;
        this->ring_manager->deformation_function(500, 10, ObjectMesh::Point(0.0f, 0.01f, 0.0f));
        this->ring_manager->update();
        std::cout << "End Deformation (Function)" << std::endl;
    }

    if(key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        std::cout << "Begin Deformation (Laplacian Angle)" << std::endl;
        // alpha in { 0.25f, 0.5f, 1.0f }
        this->ring_manager->deformation_laplacian_angle(
            500,
            10,
            ObjectMesh::Point(0.0f, 0.01f, 0.0f),
            0.25f
        );

        this->ring_manager->update();
        std::cout << "End Deformation (Laplacian Angle)" << std::endl;
    }

    if(key == GLFW_KEY_4 && action == GLFW_PRESS)
    {
        std::cout << "Begin Deformation (Laplacian Valence)" << std::endl;
        this->ring_manager->deformation_laplacian_valence(
            500,
            10,
            ObjectMesh::Point(0.0f, 0.01f, 0.0f)
        );
        this->ring_manager->update();
        std::cout << "End Deformation (Laplacian Valence)" << std::endl;
    }

}


void MyViewer::processMouse(GLFWwindow *window, double xpos, double ypos)
{

    if(this->camera_mod){

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        double cursor_x, cursor_y;
        glfwGetCursorPos(window, &cursor_x, &cursor_y);
        
        float xoffset = (float)cursor_x - ((float)width / 2);
        float yoffset = (float)cursor_y - ((float)height / 2);

        xoffset *= this->sensitivity;
        yoffset *= this->sensitivity;

        xoffset /= (float)width;
        yoffset /= (float)height;

        glm::mat4 transformation = glm::mat4(1.0f);
        transformation = glm::rotate(transformation, xoffset, glm::vec3(0.0f, 1.0f, 0.0f));
        transformation = glm::rotate(transformation, -yoffset, glm::vec3(1.0f, 0.0f, 0.0f));
        this->camera->update(transformation);
        this->camera->setPosition(this->camera->getTarget()+this->radius*(-glm::normalize(this->camera->getDirection())));

        glfwSetCursorPos(window, (float)width/2, (float)height/2);
    
    }

}

void MyViewer::laplacian(ObjectMesh* obj_mesh, float alpha)
{

    auto center_of_gravity = OpenMesh::VProp<ObjectMesh::Point>(*(this->obj_mesh));

    for(auto vh : this->obj_mesh->vertices()){

        center_of_gravity[vh] = ObjectMesh::Point(0.0f, 0.0f, 0.0f);
        int valence = 0;

        // Iterate over all 1-ring vertices around vh
        for (auto vvh : this->obj_mesh->vv_range(vh)) {
            center_of_gravity[vh] += this->obj_mesh->point(vvh);
            ++valence;
        }

        center_of_gravity[vh] /= valence;
    }

    for (const auto vh : this->obj_mesh->vertices()) {
        this->obj_mesh->point(vh) = center_of_gravity[vh];
    }

    this->obj_mesh->update();

}