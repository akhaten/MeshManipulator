
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

    if(key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        //std::cout << "Before Laplacian" << std::endl;
        this->laplacian(this->obj_mesh, 0.3f);
        //std::cout << "After Laplacian" << std::endl;
    }

    if(key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        // std::cout << "Before Deformation" << std::endl;
        this->deformation(this->obj_mesh, 500, 10);
        // std::cout << "After Deformation" << std::endl;
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

void MyViewer::deformation(ObjectMesh* obj_mesh, unsigned int id_vertex, unsigned int nb_rings)
{

    ObjectMesh::Point translation = ObjectMesh::Point(0.0f, 0.01f, 0.0f);

    this->ring_manager->compute(id_vertex, nb_rings);
    //this->ring_manager->laplacian_deformation_valence();
    this->ring_manager->laplacian_deformation_angle();
    for(ObjectMesh::VertexHandle vh : this->ring_manager->vertex_handles){
        this->obj_mesh->point(vh) += this->ring_manager->deformation[vh];
    }

    /*for(ObjectMesh::VertexHandle vh : this->ring_manager->vertex_handles){
        unsigned int id_ring = this->ring_manager->no_ring[vh];
        std::cout << id_ring << std::endl;
        float c = (float)id_ring/(float)(nb_rings);
        float fun_transfert = (1.0f - c*c)*(1.0f - c*c);
        this->obj_mesh->point(vh) += fun_transfert * translation;
    }*/

    /*//MyOpenMesh* open_mesh = this->obj_mesh;

    this->ring_manager->compute(id_vertex, nb_rings);

    ObjectMesh::VertexIter v_it = this->obj_mesh->vertices_sbegin();

    ObjectMesh::Point translation = ObjectMesh::Point(0.0f, 0.01f, 0.0f);

    for(unsigned int id_ring = 0; id_ring < nb_rings; ++id_ring){
        float c = (float)id_ring/(float)(nb_rings-1);
        float fun_transfert = (1.0f - c*c)*(1.0f - c*c);
        std::set<unsigned int> ring = this->ring_manager->get(id_ring);
        for(unsigned int vertex : ring){
            ObjectMesh::VertexHandle handle = this->obj_mesh->vertex_handle(vertex);
            this->obj_mesh->point(handle) += fun_transfert * translation;
        }

    }*/

    this->obj_mesh->update();

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