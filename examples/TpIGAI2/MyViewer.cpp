
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "MyViewer.hpp"


#include <iostream>

MyViewer::MyViewer(Camera* camera):
    Viewer(camera)
{

    this->sensitivity = 2.0f;
    this->radius = 5.0f;
    this->camera_mod = false;
    this->moveset_mode = false;

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

    if(key == GLFW_KEY_UP && action == GLFW_PRESS)
    {

        if(!this->moveset_mode){

            if(this->radius-1.0f < 0.0f){
                this->radius = 0.0f;
                this->camera->setPosition(
                        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                );
            }

            if(this->radius > 0.0f) {
                this->radius -= 1.0f;
                this->camera->setPosition(
                        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                );
            }

        }else{

            glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            target += glm::vec3(0.0f, 1.0f, 0.0f);
            this->camera->setTarget(target);
            this->camera->setPosition(
                    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            );

        }

    }

    if(key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {

        if(!this->moveset_mode) {

            this->radius += 1.0f;
            this->camera->setPosition(
                    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            );

        }else{

            glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            target += glm::vec3(0.0f, -1.0f, 0.0f);
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
        target += glm::vec3(-1.0f, 0.0f, 0.0f);
        this->camera->setTarget(target);
        this->camera->setPosition(
            this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        );

    }

    if(this->moveset_mode && key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {

        glm::vec3 target = this->camera->getTarget();
        //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
        target += glm::vec3(1.0f, 0.0f, 0.0f);
        this->camera->setTarget(target);
        this->camera->setPosition(
            this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        );

    }

    if(key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        //std::cout << "Before Laplacian" << std::endl;
        this->laplacian(this->obj_mesh, 0.5f);
        //std::cout << "After Laplacian" << std::endl;
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

void MyViewer::deformation(MyOpenMesh* open_mesh, unsigned int index, unsigned int rings){

}

void MyViewer::laplacian(ObjectMesh* obj_mesh, float alpha)
{

    MyOpenMesh* open_mesh = this->obj_mesh->getMyOpenMesh();

    std::vector<MyOpenMesh::Point> new_vertices;

    MyOpenMesh::VertexIter v_it;
    MyOpenMesh::VertexIter v_end = open_mesh->vertices_end();
    MyOpenMesh::Point vertex_current;
    MyOpenMesh::VertexVertexIter vv_it;

    for(v_it = open_mesh->vertices_sbegin(); v_it != v_end; ++v_it){

        MyOpenMesh::Point center_of_gravity(0, 0, 0);
        unsigned int valence = 0;

        for(vv_it = open_mesh->vv_iter(*v_it); vv_it.is_valid(); ++vv_it){
            center_of_gravity += open_mesh->point(*vv_it);
            ++valence;
        }

        center_of_gravity /= valence;
        new_vertices.push_back(alpha*vertex_current+(1-alpha)*center_of_gravity);

    }

    // Change points
    unsigned int index = 0;

    for(v_it = open_mesh->vertices_begin(); v_it != v_end; ++v_it){
        open_mesh->point(*v_it) = new_vertices[++index];
    }

    obj_mesh->update();

}

/*std::vector<unsigned int> MyViewer::one_ring(unsigned int index, unsigned int nb_ring)
{
    // Clear rings

    for(std::set<unsigned int> ring : this->rings)
        ring.clear();
    this->rings.clear();

    // Indexes of ring
    std::vector<unsigned int> ring;

    // Ring 0 : vertex selected
    ring.push_back(index);
    this->rings.push_back(ring);
    ring.clear();

    // Select the good vertex
    MyOpenMesh::VertexIter v_it = this->obj_mesh->vertices_sbegin() + index;


    // First ring
    for(MyOpenMesh::VertexVertexIter vv_it = this->obj_mesh->vv_iter(*v_it); vv_it.is_valid(); ++vv_it)
        ring.push_back(vv_it.handle().idx());

    this->rings.push_back(ring);
    ring.clear();

    // Others rings :
    for(unsigned int id_ring = 1; id_ring < )
}*/

/*void MyViewer::deformation(MyOpenMesh* open_mesh, unsigned int index, unsigned int rings)
{

    // Clear rings

    for(std::vector<unsigned int> ring : this->rings)
        ring.clear();
    this->rings.clear();

    // Indexes of ring
    std::vector<unsigned int> ring;

    // Ring 0 : vertex selected
    ring.push_back(index);
    this->rings.push_back(ring);
    ring.clear();

    // Select the good vertex
    MyOpenMesh::VertexIter v_it = open_mesh->vertices_sbegin() + index;


    // First ring
    for(MyOpenMesh::VertexVertexIter vv_it = open_mesh->vv_iter(*v_it); vv_it.is_valid(); ++vv_it)
        ring.push_back(vv_it.handle().idx());

    this->rings.push_back(ring);
    ring.clear();

    // Others rings :


    

    
    


}*/

// void MyViewer::one_ring(MyOpenMesh::Vertex v){

// }