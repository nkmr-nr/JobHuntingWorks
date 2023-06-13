//#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_

#include <DxLib.h>
#include"Objects.h"

class Player;

class Camera
{
private:
	Camera(VECTOR pos_, VECTOR target_, VECTOR rotateAngle_, Objects* player_)
		:pos(pos_)
		, target(target_)
		, rotateAngle(rotateAngle_)
		, targetObj(nullptr)
		, player(player_)
		, isAttacking(false)
	{
		SetCameraNearFar(0.1f, 10000.0f);
		SetCameraPositionAndTargetAndUpVec(
			pos,
			target,
			VGet(0, 1, 0)
		);
	}
public:
	~Camera()
	{

	}
	static Camera* Instance(Objects* player_)
	{
		static Camera pInstance(VGet(0, 0, 0), VGet(0, 0, 0), VGet(0, 0, 0), player_);
		return &pInstance;
	}
	void SetPosition(VECTOR pos_)//カメラのポジション情報
	{
		pos = pos_;
		SetPositionAndTarget(pos, target);
	}
	void SetTarget(VECTOR target_)//追いかける対象
	{
		target = target_;
		SetPositionAndTarget(pos, target);
	}
	void UpdateCamera();//カメラの更新
	void SetPositionAndTarget(VECTOR pos_, VECTOR target_)//ターゲットのポジションからカメラのポジション設定
	{
		pos = pos_;
		target = target_;

		SetCameraPositionAndTargetAndUpVec(pos, target, VGet(0, 1, 0));
	}
	void SetTarget(Objects* target_)
	{
		targetObj = target_;
	}

	void FinishCamera();
private:
	VECTOR pos;
	VECTOR target;
	VECTOR rotateAngle;
	Objects* targetObj;
	Objects* player;
	bool isAttacking;
};

#endif//#ifndef CAMERA_H_
