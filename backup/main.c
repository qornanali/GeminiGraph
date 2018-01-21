#include "scene.h"
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <GL/glut.h>
#include <SOIL.h>

LTextures lTextures;
LConfigs lConfigs;

cJSON * jsonPendopo;

double rotate_y = 0; 
double rotate_x = 0;
double scale = 0.5;

void loadFile();
void loadConfigs();
void loadTextures();

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	loadFile();
	loadConfigs();
	glutInitWindowSize(atoi(getConfig(lConfigs, "window_width")->value), atoi(getConfig(lConfigs, "window_height")->value));
	glutInitWindowPosition(0.0, 0.0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(getConfig(lConfigs, "window_name")->value);
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
	printf("Pendopo.json\n%s\n",content);
	jsonPendopo = cJSON_Parse(content);
    fclose(fPendopo);
}

void loadConfigs(){
	int i;
	initListConfigs(&lConfigs);
	cJSON * array_configs = cJSON_GetObjectItem(jsonPendopo, "configs");
	for(i = 0; i < cJSON_GetArraySize(array_configs); i++){
	    cJSON * item_config = cJSON_GetArrayItem(array_configs, i);
	    addConfigtToList(&lConfigs,
	    	createInstanceConfig(
				cJSON_GetObjectItem(item_config, "name")->valuestring, 
				cJSON_GetObjectItem(item_config, "value")->valuestring
			)
		);
	}
	printf("Load Configs : \n");
	printListItemConfigs(lConfigs);
}

void loadTextures(){
	int i;
	initListTextures(&lTextures);
	cJSON * array_textures = cJSON_GetObjectItem(jsonPendopo, "textures");
	for(i = 0; i < cJSON_GetArraySize(array_textures); i++){
	    cJSON * item_texture = cJSON_GetArrayItem(array_textures, i);
	    printf("Ini teh %s %s\n", cJSON_GetObjectItem(item_texture, "value")->valuestring, cJSON_GetObjectItem(item_texture, "name")->valuestring);
		addTexturetToList(&lTextures, 
			createInstanceTexture(
				cJSON_GetObjectItem(item_texture, "name")->valuestring, 
				SOIL_load_OGL_texture(
					cJSON_GetObjectItem(item_texture, "value")->valuestring,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS
				)
			)	
		);
	}
	printf("Load Textures : \n");
	printListItemTextures(lTextures);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR );
 	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}
