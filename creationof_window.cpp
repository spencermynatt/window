#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

int main()
{
	// push bytes in, in gpu with graphics
		//	shader - program that runs on the gpu, gpu will read the dataand joint up the positions to draw a triangle
		glfwInit(); //initilizates the GLFW library
		//GLFW will try to create an OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glf window hint sets the specified window hint to the desired value
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//GLFW_CONTEXT_VERSION_MAJOR and GLFW_CONTEXT_VERSION_MINOR
	//specify the client API version that the 
	//created context must be compatible with. 
	//The exact behavior of these hints 
	//depend on the requested client API.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//GLFW_OPENGL_PROFILE indicates the OpenGL profile used by the context
	//https://www.khronos.org/opengl/wiki/OpenGL_Context 
	//Think of a context as an object that holds all of OpenGL
	//GLFW_OPENGL_PROFILE specifies which OpenGL profile to create the context for. 
	//Possible values are one of GLFW_OPENGL_CORE_PROFILE

	GLFWwindow* window = glfwCreateWindow(800, 600, "Shape Window", NULL, NULL);

	//glfwCreateWindow is a function that creates the window passing these self explanatory  paramaters
	//the last two parameters null, and null are passing in arguments for monitor and shared. If you wanted a full screen, pass 
	//GLFWwindow* monitor.
	//the last parameter null is to share the resource
	if (window == NULL)
	{
		cout << "Error";
		glfwTerminate();
		return -1;

	}
	glfwMakeContextCurrent(window);
	//loop for window so that it doesn't close once it draws an image
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
	float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };

   unsigned int VBO;
  
    glGenBuffers(1, &VBO);
 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
      glGenVertexArrays(1, &VBO); //THESE TWO YOU FORGOT
    glBindVertexArray(VBO); //
	 glEnableVertexAttribArray(0);

   
    glBindBuffer(GL_ARRAY_BUFFER, 0);

   
    glBindVertexArray(0);
	
	

	/*
	GLfloat points[]
	{  //x      y
		0.0f, 1.0f,
		-1.0f, -1.0f,
		1.0f, -1.0f
	};
	//--------------------------------------------------
 unsigned int buffer_id; // empty place to store data
	
	
	
	glGenBuffers(1, &buffer_id); //generates one buffer,

	glBindBuffer(GL_ARRAY_BUFFER, buffer_id); //sends it to another buffer or binds it
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	//gl buffer data binds the size of my array and my address of my array into my empty buffer 
	//which is array buffer
	//finally gl static draw will send it to the graphics card
	//--------------------------------------------------
		//draw triangle
  //this enables the data to travel through graphics pipeline
	glEnableVertexAttribArray(0);//index where the shader will use
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//2 is the how many floats per vertex, gl float is the type, 
	//gl false is telling our graphics card not to touch our data,
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//gl triangle specifies the type of shape,
	//0 specifies the first triangle or which one we want to draw at
	// 3 specifies how many vertices we're rendering
	*/
}
	
}
	
	
