#include "scene.h"
#include "cJSON.h"
#include "list_string.h"
#include "list_int.h"
#include "list_double.h"
#include "interface.h"
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <SOIL.h>
#include <GL/glut.h>
//#include "textureloader.h"

LInts lTextures;
LStrings lConfigs;
LDoubles lMeasures;

float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float scale = 1.0f;
BOOL mouseDown = FALSE;
BOOL fullscreen = FALSE;
GLfloat yObjek = 15.0;

cJSON * jsonPendopo;

void loadFile();
void loadConfigs();
void loadTextures();
void loadMeasures();

//void bindBmp(Image* image, GLuint * textureId);

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	loadFile();
	loadConfigs();
	loadMeasures();
	glutInitWindowSize(atoi(getString(lConfigs, "window_width")->value), atoi(getString(lConfigs, "window_height")->value));
	glutInitWindowPosition(0.0, 0.0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glutCreateWindow(getString(lConfigs, "window_name")->value);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	loadTextures();
	glutDisplayFunc(onWorldDisplay);
	glutReshapeFunc(onWorldReshape);
	glutMotionFunc (onMotionMouseClicked);
	glutMouseFunc(onButtonMouseClicked);
	glutSpecialFunc(onSpecialKeyClicked);
	glutKeyboardFunc(onNormalKeyClicked);
	glutPassiveMotionFunc(onPassiveMouseActived);
	glutIdleFunc(onWorldIdle);
	glutMainLoop();	
//	start(argc, argv);
	return 0;
}


void loadFile(){
	int i=0;
	char c;
	char content[5000];
	FILE *fPendopo = fopen("pendopo.json","r");
	if (fPendopo != NULL){
		while ((c = fgetc(fPendopo)) != EOF) {
			content[i] = c;
			i++;
		}
	}
	content[i] = '\0';
	printf("pendopo.json\n%s\n",content);
	jsonPendopo = cJSON_Parse(content);
    fclose(fPendopo);
}

void loadConfigs(){
	int i;
	initListStrings(&lConfigs);
	cJSON * array_configs = cJSON_GetObjectItem(jsonPendopo, "configs");
	for(i = 0; i < cJSON_GetArraySize(array_configs); i++){
	    cJSON * item_config = cJSON_GetArrayItem(array_configs, i);
	    addStringToList(&lConfigs,
	    	createInstanceString(
				cJSON_GetObjectItem(item_config, "name")->valuestring, 
				cJSON_GetObjectItem(item_config, "value")->valuestring
			)
		);
	}
	printf("Load Configs : \n");
	printListItemStrings(lConfigs);
}

void loadTextures(){
	int i;
	initListInts(&lTextures);
	cJSON * array_textures = cJSON_GetObjectItem(jsonPendopo, "textures");
	for(i = 0; i < cJSON_GetArraySize(array_textures); i++){
	    cJSON * item_texture = cJSON_GetArrayItem(array_textures, i);
//		Image * image = loadBMP(cJSON_GetObjectItem(item_texture, "value")->valuestring);
//		bindBmp(image, &P->id);
//		delete image;	
		addIntToList(&lTextures, 
			createInstanceInt(
				cJSON_GetObjectItem(item_texture, "name")->valuestring, //0
				SOIL_load_OGL_texture(
					cJSON_GetObjectItem(item_texture, "value")->valuestring,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS
				)
			)
		);
	}
	printf("Load Textures : \n");
	printListItemInts(lTextures);	
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}


//void bindBmp(Image* image, GLuint * textureId) {
//	glGenTextures(1, textureId);
//	glBindTexture(GL_TEXTURE_2D, *textureId);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);	
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// 	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
// 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
////    glGenerateMipmap(GL_TEXTURE_2D);
//}


void loadMeasures(){
	int i;
	initListDoubles(&lMeasures);
	cJSON * array_measures = cJSON_GetObjectItem(jsonPendopo, "measures");
	for(i = 0; i < cJSON_GetArraySize(array_measures); i++){
	    cJSON * item_measure = cJSON_GetArrayItem(array_measures, i);
	    addDoubleToList(&lMeasures,
	    	createInstanceDouble(
				cJSON_GetObjectItem(item_measure, "name")->valuestring, 
				cJSON_GetObjectItem(item_measure, "value")->valuedouble
			)
		);
	}
	printf("Load Measures : \n");
	printListItemDoubles(lMeasures);
}


