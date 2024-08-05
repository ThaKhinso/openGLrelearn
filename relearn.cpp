#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(void) {
  GLFWwindow* window;

  if(!glfwInit()) {
    return -1;
  }

  window = glfwCreateWindow(640,480 , "Hello world", NULL, NULL);
  if(!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  
  if(glewInit() != GLEW_OK){
	  std::cout << "Error!\n";
  }

  std::cout << glGetString(GL_VERSION) << "\n";
   
  float positions[6] = {
	  -0.5f, -0.5f,
	   0.0f,  0.5f,
	   0.5f, -0.5f
  };

  unsigned int buffer; 
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
  


  while(!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3); 
    glfwSwapBuffers(window);
    glfwPollEvents();
  
  }
  glfwTerminate();
  return 0;
}
