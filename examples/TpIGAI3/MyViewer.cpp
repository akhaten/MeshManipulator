
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <OpenMesh/Core/Utils/PropertyManager.hh>

#include "MyViewer.hpp"


#include <iostream>

MyViewer::MyViewer(Camera* camera):
    Viewer(camera)
{

    this->sensitivity = 2.0f;
	//this->radius = 0.01f;
    this->camera_mod = false;
    this->moveset_mode = false;



	this->target = this->camera->getPosition()+this->radius*this->camera->getDirection();
	this->setRadius(0.1f);
	this->setTarget(glm::vec3(0.0f, 0.0f, 0.0f));
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

void MyViewer::setTarget(const glm::vec3 target)
{
	this->target = target;
	glm::vec3 opposite_direction = -this->camera->getDirection();
	glm::vec3 new_position = this->target + this->radius * opposite_direction;
	this->camera->setPosition(new_position);
}

void MyViewer::setRadius(const float radius)
{
	this->radius = radius;
	glm::vec3 opposite_direction = -this->camera->getDirection();
	glm::vec3 new_position = this->target + this->radius * opposite_direction;
	this->camera->setPosition(new_position);
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


            if(this->radius-shift < 0.01f){
				this->setRadius(0.01f);
                //this->radius = 0.0f;
                //this->camera->setPosition(
                //        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                //);
            }else{
				this->setRadius(this->radius-shift);
                //this->radius -= shift;
                //this->camera->setPosition(
                //        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
                //);
            }

        }else{

			this->setTarget(this->target+glm::vec3(0.0f, shift, 0.0f));
            //glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            //target += glm::vec3(0.0f, shift, 0.0f);
            //this->camera->setTarget(target);
            //this->camera->setPosition(
            //        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            //);

        }

    }

    if(key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {

        if(!this->moveset_mode) {

            //this->radius += shift;
			this->setRadius(this->radius+shift);
            //this->camera->setPosition(
            //        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            //);

        }else{

			this->setTarget(this->target-glm::vec3(0.0f, shift, 0.0f));
            //glm::vec3 target = this->camera->getTarget();
            //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
            //target += glm::vec3(0.0f, -shift, 0.0f);
            //this->camera->setTarget(target);
            //this->camera->setPosition(
            //        this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
            //);

        }

    }

    // MOVESET

    if(key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS)
    {
        this->moveset_mode = !this->moveset_mode;
    }

    if(this->moveset_mode && key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    {

		this->setTarget(this->target+glm::vec3(-shift, 0.0f, 0.0f));
        //glm::vec3 target = this->camera->getTarget();
        //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
        //target += glm::vec3(-shift, 0.0f, 0.0f);
        //this->camera->setTarget(target);
        //this->camera->setPosition(
        //    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        //);

    }

    if(this->moveset_mode && key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {

		this->setTarget(this->target+glm::vec3(shift, 0.0f, 0.0f));
        //glm::vec3 target = this->camera->getTarget();
        //std::cout << target.x << ";" << target.y << ";" << target.z << std::endl;
        //target += glm::vec3(shift, 0.0f, 0.0f);
        //this->camera->setTarget(target);
        //this->camera->setPosition(
        //    this->camera->getTarget() + this->radius * (-glm::normalize(this->camera->getDirection()))
        //);

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
        this->camera->setPosition(this->target+this->radius*(-glm::normalize(this->camera->getDirection())));

        glfwSetCursorPos(window, (float)width/2, (float)height/2);
    
    }

}

