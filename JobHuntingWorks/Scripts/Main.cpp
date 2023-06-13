
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
	//ƒJƒƒ‰
	{
		VECTOR camera_pos = VGet(0.0f, 100.0f, -100.0f);
		VECTOR target_pos = VGet(0.0f, 100.0f, 0.0f);
		VECTOR up_vec = VGet(0.0f, 1.0f, 0.0f);
		SetCameraPositionAndTargetAndUpVec(camera_pos, target_pos, up_vec);
		SetCameraNearFar(0.1f, 1000.0f);
	}
	srand(time(NULL));

	SceneManager* sceneManager = SceneManager::Instance();

	sceneManager->GameLoop();


	InitGraph();
	DxLib_End();

	return 0;
}