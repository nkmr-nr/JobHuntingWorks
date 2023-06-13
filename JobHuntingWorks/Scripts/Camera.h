//#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_

#include <DxLib.h>
#include"Objects.h"
#include"NonObjects.h"

class Player;

class Camera : public NonObjects
{
private:
	Camera(VECTOR pos_, VECTOR target_, VECTOR rotateAngle_, Objects* player_)
		:pos(pos_)
		, target(target_)
		, rotateAngle(rotateAngle_)
		, targetObj(player_)
		, isAttacking(false)
	{
		SetCameraNearFar(0.1f, 10000.0f);
		SetCameraPositionAndTargetAndUpVec(pos,target,VGet(0, 1, 0));
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
	void Init()override;					//初期化
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
	void Update()override;				//更新

	void SetPositionAndTarget(VECTOR pos_, VECTOR target_)
		//ターゲットのポジションからカメラのポジション設定
	{
		pos = pos_;
		target = target_;

		SetCameraPositionAndTargetAndUpVec(pos, target, VGet(0, 1, 0));
	}
	void SetTarget(Objects* target_)		//targetの設定
	{
		targetObj = target_;
	}
	void FinishCamera();
private:
	VECTOR pos;								//ポジション
	VECTOR target;							//ターゲットのベクトル
	VECTOR rotateAngle;					//回転角度
	Objects* targetObj;						//ターゲット
	bool isAttacking;							//Playerがアタック中か
};

#endif//#ifndef CAMERA_H_
