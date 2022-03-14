#include <iostream>
#include <GLFW/glfw3.h>
#include<config.h>
#ifdef USE_ADDER
    #include <adder.h>
#endif
using namespace std;

int main(int argc, char* argv[])
{
    #ifdef USE_ADDER
        cout <<add(11.2,25.4)<< " USING ADDER LIB" <<endl;
    #else
        cout << 11.2+25.4 << "SENZA ADDER" << endl;
    #endif

    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << endl;
    cout << "Hello Lord!" << endl;

    GLFWwindow* window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
