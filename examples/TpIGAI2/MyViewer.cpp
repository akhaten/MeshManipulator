
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "MyViewer.hpp"


#include <iostream>

MyViewer::MyViewer(Camera* camera):
    Viewer(camera)
{

    this->sensitivity = 2.0f;
    this->radius = 30.0f;
    this->camera_mod = false;

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

void MyViewer::setMyOpenMesh(MyOpenMesh* obj_mesh)
{
    this->obj_mesh = obj_mesh;
}

/**
 * CALLBACK
 */

void MyViewer::processKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{

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

    

}


void MyViewer::processMouse(GLFWwindow *window, double xpos, double ypos)
{

    if(this->camera_mod){

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        double cursor_x, cursor_y;
        glfwGetCursorPos(window, &cursor_x, &cursor_y);
        
        float xoffset = cursor_x - ((float)width / 2);
        float yoffset = cursor_y - ((float)height / 2);

        xoffset *= this->sensitivity;
        yoffset *= this->sensitivity;

        xoffset /= width;
        yoffset /= height;

        glm::mat4 transformation = glm::mat4(1.0f);
        transformation = glm::rotate(transformation, xoffset, glm::vec3(0.0f, 1.0f, 0.0f));
        transformation = glm::rotate(transformation, -yoffset, glm::vec3(1.0f, 0.0f, 0.0f));
        this->camera->update(transformation);
        this->camera->setPosition(this->camera->getTarget()+this->radius*(-glm::normalize(this->camera->getDirection())));

        glfwSetCursorPos(window, width/2, height/2);
    
    }

}



void MyViewer::laplacian(MyOpenMesh* open_mesh, float alpha)
{

    std::vector<MyOpenMesh::Point> new_vertices;
    
    for(MyOpenMesh::VertexIter v_it = open_mesh->vertices_sbegin(); v_it != open_mesh->vertices_end(); ++v_it){

        MyOpenMesh::Point vertex_current = open_mesh->point(*v_it);
        // unsigned int vertex_current_index = v_it.handle().idx();
        
        MyOpenMesh::Point center_of_gravity(0, 0, 0);
        unsigned int valence = 0;

        for(MyOpenMesh::VertexVertexIter vv_it = open_mesh->vv_iter(*v_it); vv_it.is_valid(); ++vv_it){
            center_of_gravity +=  open_mesh->point(*vv_it);
            ++valence;
        }
        
        center_of_gravity /= valence;
        new_vertices.push_back(alpha*vertex_current+(1-alpha)*center_of_gravity);
    
    }

    unsigned int index = 0;

    for(MyOpenMesh::VertexIter v_it = open_mesh->vertices_sbegin(); v_it != open_mesh->vertices_end(); ++v_it){
        open_mesh->point(*v_it) = new_vertices[++index];
    }

}


std::vector<unsigned int> MyViewer::one_ring(unsigned int index)
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

}

void MyViewer::deformation(MyOpenMesh* open_mesh, unsigned int index, unsigned int rings)
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


    

    
    


}

// void MyViewer::one_ring(MyOpenMesh::Vertex v){

// }