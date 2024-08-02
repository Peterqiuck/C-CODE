#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include "cJSON.h"

//����һ��ͼ���
struct layer {
	char name[32];
	int* tiles;//��ά���飬������(13),������(200)
	int width;
	int height;
};

//��������ͼ���
struct map {
	int width;//100ͼ��
	int height;//13ͼ��

	struct layer* layers;
	int layerCount;//ͼ�������������2��һ���ǡ���������һ����
};

struct map gameMap;//��ʾ�����Ϸ�ĵ�ͼ

//������ͼ�ļ�,��ȡ�ļ��������ݣ�����������ַ���
char* getFileContent(const char* fileName) {
	FILE* fp = fopen(fileName, "r");

	//��������ļ��Ĵ�С
	fseek(fp, 0, SEEK_END); //�Ѷ�ȡ��궨λ���ļ�β��
	int len = ftell(fp);  //�����ļ��ĵ�ǰλ��

	char* fileMsg = (char*)malloc(len + 1);
	fseek(fp, 0, SEEK_SET);//�Ѷ�ȡ��궨λ���ļ�ͷ��
	char* p = fileMsg;

	while (1) {
		int ret = fread(p, sizeof(char), 1024, fp);//һ�ζ�1024��
		if (ret <= 0) {
			break;
		}
		p += ret;
	}
	*p = '/0';
	fclose(fp);
	fp = NULL;
	return fileMsg;
}

bool mapInit() {
	//������ͼ�ļ�,��ȡ�ļ���������,����������ַ���
	char *content=getFileContent("map.tmj");
	cJSON *tree=cJSON_Parse(content);
	if (tree == NULL) {
		printf("parse map.tmp failed.\n");
		return false;
	}
	//node�ǽڵ����˼,item����Ŀ
	//cJSON_GetObjectItem��ȡָ���ڵ�width��Ա
	cJSON* node = cJSON_GetObjectItem(tree, "width");
	gameMap.width = node->valueint;

	//��ȡ�߶�
	gameMap.height= cJSON_GetObjectItem(tree, "height")->valueint;

	//��ȡ����Ĳ���
	cJSON* layersNode = cJSON_GetObjectItem(tree, "layers");
	gameMap.layerCount=cJSON_GetArraySize(layersNode);

	gameMap.layers = (struct layer*)malloc(
		sizeof(struct layer) * gameMap.layerCount);

	for (int i = 0; i < gameMap.layerCount; i++)
	{
		//��ȡͼ��������ָ����Ա
		cJSON* alayer=cJSON_GetArrayItem(layersNode, i);//layer

		strcpy(gameMap.layers[i].name,
			cJSON_GetObjectItem(alayer, "name")->valuestring);//layer

		cJSON* dataNode = cJSON_GetObjectItem(alayer, "data");//layer
		int count = cJSON_GetArraySize(dataNode);

		gameMap.layers[i].tiles = (int*)malloc(sizeof(int) * count);
		for (int k = 0; k < count; k++)
		{
			gameMap.layers[i].tiles[k] = cJSON_GetArrayItem(dataNode, k)->valueint;
		}

	}



	return true;
}

void gameInit() {

}

int main(void) {
	gameInit();

	return 0;
}