#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include <MeshManipulator/Window/Application.hpp>
#include "MyViewer.hpp"

class MyApplication:
    public Application
{


    public:
        
        MyApplication(const char* name, int width, int height);
        ~MyApplication();

        void setViewer(MyViewer* viewer);

};


#endif  // MY_APPLICATION_HPP