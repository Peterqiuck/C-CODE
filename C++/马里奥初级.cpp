#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include "cJSON.h"

//定义一个图块层
struct layer {
	char name[32];
	int* tiles;//二维数组，多少行(13),多少列(200)
	int width;
	int height;
};

//定义所有图块层
struct map {
	int width;//100图块
	int height;//13图块

	struct layer* layers;
	int layerCount;//图块层数，这里是2，一个是“背景”，一个是
};

struct map gameMap;//表示这个游戏的地图

//解析地图文件,读取文件所有内容，并返回这个字符串
char* getFileContent(const char* fileName) {
	FILE* fp = fopen(fileName, "r");

	//计算这个文件的大小
	fseek(fp, 0, SEEK_END); //把读取光标定位到文件尾部
	int len = ftell(fp);  //返回文件的当前位置

	char* fileMsg = (char*)malloc(len + 1);
	fseek(fp, 0, SEEK_SET);//把读取光标定位到文件头部
	char* p = fileMsg;

	while (1) {
		int ret = fread(p, sizeof(char), 1024, fp);//一次读1024个
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
	//解析地图文件,读取文件所有内容,并返回这个字符串
	char *content=getFileContent("map.tmj");
	cJSON *tree=cJSON_Parse(content);
	if (tree == NULL) {
		printf("parse map.tmp failed.\n");
		return false;
	}
	//node是节点的意思,item是项目
	//cJSON_GetObjectItem获取指定节点width成员
	cJSON* node = cJSON_GetObjectItem(tree, "width");
	gameMap.width = node->valueint;

	//获取高度
	gameMap.height= cJSON_GetObjectItem(tree, "height")->valueint;

	//获取数组的层数
	cJSON* layersNode = cJSON_GetObjectItem(tree, "layers");
	gameMap.layerCount=cJSON_GetArraySize(layersNode);

	gameMap.layers = (struct layer*)malloc(
		sizeof(struct layer) * gameMap.layerCount);

	for (int i = 0; i < gameMap.layerCount; i++)
	{
		//获取图层数组中指定成员
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