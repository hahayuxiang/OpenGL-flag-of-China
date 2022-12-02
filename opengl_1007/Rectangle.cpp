#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 Ourcolor;\n"
"void main()\n"
"{\n"
"FragColor = Ourcolor\n;"
"}\n";
//"FragColor = vec4(1.0f, 0.870588f, 0.0f, 1.0f);\n"
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize glad\n";
		return -1;
	}


	//顶点着色器
	unsigned int vertexShader;		//着色器对象
	vertexShader = glCreateShader(GL_VERTEX_SHADER);	//创建着色器
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 将着色器源码附加到着色器对象上
	glCompileShader(vertexShader);	//编译着色器
	int success;					//表示是否成功编译
	char infoLog[512];				//记录返回的错误信息
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //检查是否编译成功
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); //获取错误信息
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	}


	//片段着色器
	unsigned int fragementShader;
	fragementShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragementShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragementShader);
	glGetShaderiv(fragementShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragementShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
	}

	//着色器程序对象，将多个着色器合并并完成链接 a->b, b->c, c->d...
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	//将着色器附加到着色器程序对象上
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragementShader);
	glLinkProgram(shaderProgram);	//链接附加到该程序上的着色器
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
	}

	//删除之前创建的着色器
	glDeleteShader(vertexShader);
	glDeleteShader(fragementShader);

	/*
-0.381683   0.592705
-0.667   0.8
-0.952317   0.592705
-0.843336   0.257295
-0.490664   0.257295

-0.59964   0.592713
-0.73436   0.592713
-0.775991   0.464587
-0.667   0.3854
-0.558009   0.464587
*/
	float vertices[][33]{
		{
			-0.666667f, 0.6f,		0.0f,

			-0.666667f, 0.8f,		0.0f,
			-0.856878f, 0.592705f,	0.0f,
			-0.784224f, 0.257295f,	0.0f,
			-0.54911f,  0.257295f,	0.0f,
			-0.476455f, 0.592705f,	0.0f,

			-0.711573f, 0.592713,	0.0f,
			-0.739327f, 0.464587,	0.0f,
			-0.666667f, 0.3854,		0.0f,
			-0.594006f, 0.464587,	0.0f,
			-0.62176f,  0.592713,	0.0f
		},
		{
			-0.333f,	0.8f,		0.0f,

			-0.3905f,	0.74855f,	0.0f,
			-0.318378f,	0.702549f,	0.0f,
			-0.266924f, 0.791221f,	0.0f,
			-0.307246f, 0.892026f,	0.0f,
			-0.38362f,	0.865654f,	0.0f,

			-0.343299f, 0.764846f,	0.0f,
			-0.314124f, 0.77492f,	0.0f,
			-0.311496f,	0.819654f,	0.0f,
			-0.339046f, 0.837226f,	0.0f,
			-0.358702f, 0.803353f,	0.0f
		},
		{
			-0.2f,		0.6f,		0.0f,

			-0.265997f, 0.585858f,	0.0f,
			-0.211427f, 0.50148f,	0.0f,
			-0.141066f, 0.553253f,	0.0f,
			-0.152149f, 0.669629f,	0.0f,
			-0.229361f, 0.68978f,	0.0f,

			-0.218279f, 0.573402f,	0.0f,
			-0.188784f, 0.565704f,	0.0f,
			-0.174789f, 0.605402f,	0.0f,
			-0.195635f, 0.637635f,	0.0f,
			-0.222513f, 0.617857f,	0.0f
		},
		{
			-0.2f,		0.3f,		0.0f,

			-0.264102f, 0.327472f,	0.0f,
			-0.237227f, 0.217043f,	0.0f,
			-0.158906f, 0.221258f,	0.0f,
			-0.137376f, 0.334292f,	0.0f,
			-0.20239f,  0.399936f,	0.0f,

			-0.223923f, 0.286901f,	0.0f,
			-0.199087f, 0.261825f,	0.0f,
			-0.175513f, 0.289506f,	0.0f,
			-0.185779f, 0.33169f,	0.0f,
			-0.215698f, 0.33008f,	0.0f
		},
		{
			-0.333f,	0.1f,		0.0f,

			-0.385391f, 0.16247f,	0.0f,
			-0.389028f, 0.0450391f,	0.0f,
			-0.315697f, 0.00356278f,0.0f,
			-0.266739f, 0.0953593f, 0.0f,
			-0.309812f, 0.193569f,	0.0f,

			-0.358773f, 0.101773f,	0.0f,
			-0.342318f, 0.0642566f,	0.0f,
			-0.313447f, 0.0761366f, 0.0f,
			-0.312058f, 0.120995f,	0.0f,
			-0.340071f, 0.136839f,	0.0f
		}

	};
	unsigned int indices[] = {
		0, 6, 2,
		0, 2, 7,
		0, 1, 6,
		0, 1, 10,
		0, 5, 10,
		0, 5, 9,
		0, 4, 9,
		0, 4, 8,
		0, 3, 7,
		0, 3, 8
	};
	/*float vertices[]{
		 0.5f,  0.5f, 0.0f,	//右上角
		 0.5f, -0.5f, 0.0f,	//右下角
		-0.5f,  0.5f, 0.0f, //左上角
		-0.5f, -0.5f, 0.0f  //左下角
	};*/
	/*unsigned int indices[] = {
		0, 1, 2,
		3, 1, 2
	};*/

	//顶点缓冲
	unsigned int VBO[5], VAO[5], EBO[5];
	for (int i = 0; i < 5; i++) {
		glGenVertexArrays(1, &VAO[i]);
		glGenBuffers(1, &VBO[i]);
		glGenBuffers(1, &EBO[i]);

		glBindVertexArray(VAO[i]);

		glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[i]), vertices[i], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}



	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		glClearColor(0.878588f, 0.160784f, 0.062745f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glUseProgram(shaderProgram);
		int vertexColorLocation = glGetUniformLocation(shaderProgram, "Ourcolor");
		glUniform4f(vertexColorLocation, 1.0f, 0.870588f, 0.0f, 1.0f);
		glBindVertexArray(VAO[0]);
		glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);
		for (int i = 1; i < 5; i++) {
			float timeValue = glfwGetTime() + i;
			float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
			int vertexColorLocation = glGetUniformLocation(shaderProgram, "Ourcolor");
			glUniform4f(vertexColorLocation, 1.0f, greenValue, 0.0f, 1.0f);
			glBindVertexArray(VAO[i]);
			glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);
		}


		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	for (int i = 0; i < 5; i++) {
		glDeleteVertexArrays(1, &VAO[i]);
		glDeleteBuffers(1, &VBO[i]);
	}

	glDeleteShader(shaderProgram);

	glfwTerminate();
	return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
