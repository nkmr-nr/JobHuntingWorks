
#include"SceneBase.h"

void SceneBase::Loading()
{
	char buffer[32];
	std::string sentence = "ロ";

	VECTOR pos = VGet(980, 700, 0);

	int waitTime = 5;

	SetMainWindowText("ロ");
	sprintf_s(buffer, 32, sentence.c_str());
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime);

	sentence += "ー";
	SetMainWindowText("ロー");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime);

	sentence += "ド";
	SetMainWindowText("ロード");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime);

	sentence += "中";
	SetMainWindowText("ロード中");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime);

	sentence += ".";
	SetMainWindowText("ロード中.");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime += 200);

	sentence += ".";
	SetMainWindowText("ロード中..");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime += 200);

	sentence += ".";
	SetMainWindowText("ロード中...");
	DrawString(pos.x, pos.y, sentence.c_str(), GetColor(255, 255, 255));
	WaitTimer(waitTime += 200);
}

void SceneBase::Message()
{
	std::string message = "PushToSpaceKey";
	VECTOR pos = VGet(450, 250, 0);
	DrawString(pos.x, pos.y, message.c_str(), GetColor(255, 255, 255));
}
