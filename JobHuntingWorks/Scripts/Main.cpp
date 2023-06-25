
#include<DxLib.h>
#include <time.h>
#include<stdlib.h>
#include"SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	SetGraphMode(1080, 720, 32);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	
	srand(time(NULL));

	SceneManager* sceneManager = SceneManager::Instance();

	sceneManager->GameLoop();


	InitGraph();
	DxLib_End();

	return 0;
}