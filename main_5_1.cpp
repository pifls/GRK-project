#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"
#include "ext.hpp"
#include <iostream>
#include <cmath>
#include <list>

#include "Shader_Loader.h"
#include "Render_Utils.h"
#include "Camera.h"
#include "Texture.h"

GLuint programColor;
GLuint programTexture;
GLuint mainTexture;

GLuint fish_texture;
GLuint ryba1;
GLuint ryba2;
GLuint bq;

Core::Shader_Loader shaderLoader;

obj::Model crabModel;
obj::Model fishModel;
obj::Model bqModel;



float timefour = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

glm::vec3 cameraPos = glm::vec3(-5, 0, 0);
glm::vec3 cameraDir;
float cameraAngle = 0;
glm::mat4 cameraMatrix, perspectiveMatrix;

glm::mat4 rotation;

glm::vec3 lightDir = glm::normalize(glm::vec3(1.0f, -0.9f, -1.0f));

float angleSpeed = 0.3f;
float moveSpeed = 0.2f;

void drawObjectTextureMain(obj::Model * model, glm::mat4 modelMatrix, GLuint textureID)
{
	GLuint program = mainTexture;

	glUseProgram(program);
	Core::SetActiveTexture(textureID, "sampler2dtype", 1, 0);
	glUniform3f(glGetUniformLocation(program, "lightDir"), lightDir.x, lightDir.y, lightDir.z);

	glm::mat4 transformation = perspectiveMatrix * cameraMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix"), 1, GL_FALSE, (float*)&transformation);
	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, GL_FALSE, (float*)&modelMatrix);

	Core::DrawModel(model);

	glUseProgram(0);
}


glm::mat4 createCameraMatrix()
{
	cameraDir = glm::vec3(cosf(cameraAngle), 0.0f, sinf(cameraAngle));
	glm::vec3 up = glm::vec3(0,1,0);

	return Core::createViewMatrix(cameraPos, cameraDir, up);
}

void drawObjectColor(obj::Model * model, glm::mat4 modelMatrix, glm::vec3 color)
{
	GLuint program = programColor;

	glUseProgram(program);

	glUniform3f(glGetUniformLocation(program, "objectColor"), color.x, color.y, color.z);
	glUniform3f(glGetUniformLocation(program, "lightDir"), lightDir.x, lightDir.y, lightDir.z);
	glm::mat4 transformation = perspectiveMatrix * cameraMatrix * modelMatrix;

	glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix"), 1, GL_FALSE, (float*)&transformation);
	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, GL_FALSE, (float*)&modelMatrix);

	Core::DrawModel(model);
	glUseProgram(0);
}


void drawObjectTexture(obj::Model * model, glm::mat4 modelMatrix, GLuint textureID)
{
	GLuint program = programTexture;
	
	glUseProgram(program);
	Core::SetActiveTexture(textureID, "sampler2dtype", 1, 0);

	glUniform3f(glGetUniformLocation(program, "lightDir"), lightDir.x, lightDir.y, lightDir.z);
	

	glm::mat4 transformation = perspectiveMatrix * cameraMatrix * modelMatrix;
	
	glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix"), 1, GL_FALSE, (float*)&transformation);
	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, GL_FALSE, (float*)&modelMatrix);

	Core::DrawModel(model);

	glUseProgram(0);
}

void drawObjectTextureFish(obj::Model * model, glm::mat4 modelMatrix, GLuint textureID)
{
	GLuint program = programTexture;

	glUseProgram(program);
	Core::SetActiveTexture(textureID, "sampler2dtype", 1, 0);
	glUniform3f(glGetUniformLocation(program, "lightDir"), lightDir.x, lightDir.y, lightDir.z);

	glm::mat4 transformation = perspectiveMatrix * cameraMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(program, "modelViewProjectionMatrix"), 1, GL_FALSE, (float*)&transformation);
	glUniformMatrix4fv(glGetUniformLocation(program, "modelMatrix"), 1, GL_FALSE, (float*)&modelMatrix);

	Core::DrawModel(model);

	glUseProgram(0);
}

void renderScene()
{

	cameraMatrix = createCameraMatrix();
	perspectiveMatrix = Core::createPerspectiveMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glm::mat4 crabModelMatrix = glm::translate(cameraPos + cameraDir  + glm::vec3(0, -0.7f, 0)) * glm::rotate(-cameraAngle + glm::radians(270.0f), glm::vec3(0, 1, 0)) * glm::scale(glm::vec3(0.75f));
	glm::mat4 ryba3; 
	glm::mat4 ryba4;
	glm::mat4 ryba5;
	glm::mat4 ryba6;
	glm::mat4 ryba7;
	glm::mat4 ryba8;
	glm::mat4 ryba9;
	glm::mat4 ryba10;
	glm::mat4 ryba11;
	glm::mat4 ryba12;
	glm::mat4 ryba13;
	glm::mat4 ryba14;
	glm::mat4 ryba15;
	glm::mat4 ryba16;
	glm::mat4 ryba17;
	glm::mat4 ryba18;
	glm::mat4 ryba19;

	float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	
	
	ryba3[3][0] = 10 * sin(0.9 * time);
	ryba3[3][2] = 10 * cos(0.9 * time);
	ryba4[3][0] = 15 * sin(0.7 * time);
	ryba4[3][2] = 15 * cos(0.7 * time);
	ryba5[3][0] = 25 * sin(0.3 * time);
	ryba5[3][2] = 25 * cos(0.3 * time);
	ryba6[3][0] = 30 * sin(0.1 * time);
	ryba6[3][2] = 30 * cos(0.1 * time);
	ryba7[3][0] = 35 * sin(0.05 * time);
	ryba7[3][2] = 35 * cos(0.05 * time);
	ryba8[3][0] = 40 * sin(0.02 * time);
	ryba8[3][2] = 40 * cos(0.02 * time);
	ryba9[3][0] = 45 * sin(0.005 * time);
	ryba9[3][2] = 45 * cos(0.005 * time);
	ryba10[3][0] = 32 * sin(0.8 * time);
	ryba10[3][2] = 32 * cos(0.8 * time);
	ryba11[3][0] = 21 * sin(0.65 * time);
	ryba11[3][2] = 21 * cos(0.65 * time);
	ryba12[3][0] = 25 * sin(0.58 * time);
	ryba12[3][2] = 25 * cos(0.58 * time);
	ryba13[3][0] = 38 * sin(0.43 * time);
	ryba13[3][2] = 38 * cos(0.43 * time);
	ryba14[3][0] = 31 * sin(0.37 * time);
	ryba14[3][2] = 31 * cos(0.37 * time);
	ryba15[3][0] = 32 * sin(0.28 * time);
	ryba15[3][2] = 32 * cos(0.28 * time);
	ryba16[3][0] = 12 * sin(0.25 * time);
	ryba16[3][2] = 12 * cos(0.25 * time);
	ryba17[3][0] = 15 * sin(0.22 * time);
	ryba17[3][2] = 15 * cos(0.22 * time);
	ryba18[3][0] = 30 * sin(0.1 * time);
	ryba18[3][2] = 30 * cos(0.1 * time);
	ryba19[3][0] = 18 * sin(0.04 * time);
	ryba19[3][2] = 18 * cos(0.04 * time);
	
	rotation[0][0] = cos(time);
	rotation[2][0] = sin(time);
	rotation[0][2] = -sin(time);
	rotation[2][2] = cos(time);


	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba3*rotation*glm::scale(glm::vec3(0.5f)),ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0,0,0))*ryba4*rotation*glm::scale(glm::vec3(0.8f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba5*rotation*glm::scale(glm::vec3(0.7f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(1, 1, 0.7))*ryba6*rotation*glm::scale(glm::vec3(2.0f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(1, 1, 1))*ryba7*rotation* glm::scale(glm::vec3(1.8f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(1, 1, 1))*ryba8*rotation* glm::scale(glm::vec3(1.6f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(1, 1,0.5))*ryba9*rotation*glm::scale(glm::vec3(1.4f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba10*rotation*glm::scale(glm::vec3(0.5f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba11*rotation*glm::scale(glm::vec3(0.1f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba12*rotation*glm::scale(glm::vec3(0.9f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba13*rotation*glm::scale(glm::vec3(0.1f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba14*rotation*glm::scale(glm::vec3(0.15f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba15*rotation*glm::scale(glm::vec3(0.23f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba16*rotation*glm::scale(glm::vec3(0.52f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba17*rotation*glm::scale(glm::vec3(0.59f)), ryba2);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba18*rotation*glm::scale(glm::vec3(0.51f)), ryba1);
	drawObjectTexture(&fishModel, glm::translate(glm::vec3(0, 0, 0))*ryba19*rotation*glm::scale(glm::vec3(0.99f)), ryba2);

	//tlo
	drawObjectTextureMain(&bqModel, glm::translate(glm::vec3(0, 0, 0))* glm::scale(glm::vec3(70.0f)), bq);

	//tekstura ryby
	drawObjectTextureFish(&crabModel, crabModelMatrix, fish_texture);
	drawObjectColor(&crabModel, crabModelMatrix, glm::vec3(5.0f));
	
	glutSwapBuffers();
	
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	programColor = shaderLoader.CreateProgram("shaders/shader_color.vert", "shaders/shader_color.frag");
	programTexture = shaderLoader.CreateProgram("shaders/shader_tex.vert", "shaders/shader_tex.frag");
	mainTexture= shaderLoader.CreateProgram("shaders/shader_tex1.vert", "shaders/shader_tex1.frag");
	
	fishModel = obj::loadModelFromFile("models/FishModel.obj");
	bqModel = obj::loadModelFromFile("models/BQ.obj");
	crabModel = obj::loadModelFromFile("models/crab.obj");
	
	fish_texture = Core::LoadTexture("textures/fish.png");
	ryba1 = Core::LoadTexture("textures/ryba1.png");
	ryba2 = Core::LoadTexture("textures/ryba2.png");
	bq = Core::LoadTexture("textures/BQ.PNG");



}

void shutdown()
{
	shaderLoader.DeleteProgram(programColor);
	shaderLoader.DeleteProgram(programTexture);
	shaderLoader.DeleteProgram(mainTexture);
}

void idle()
{
	glutPostRedisplay();
}
//sterowanie
void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'z': cameraAngle -= angleSpeed; break;
	case 'x': cameraAngle += angleSpeed; break;
	case 'w': cameraPos += cameraDir * moveSpeed; break;
	case 's': cameraPos -= cameraDir * moveSpeed; break;
	case 'd': cameraPos += glm::cross(cameraDir, glm::vec3(0, 1, 0)) * moveSpeed; break;
	case 'a': cameraPos -= glm::cross(cameraDir, glm::vec3(0, 1, 0)) * moveSpeed; break;

	}
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600); 
	glutCreateWindow("Wodny Œwiat"); 
	glewInit();

	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	glutMainLoop();

	shutdown();

	return 0;
}

