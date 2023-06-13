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
	void Init()override;					//������
	void SetPosition(VECTOR pos_)//�J�����̃|�W�V�������
	{
		pos = pos_;
		SetPositionAndTarget(pos, target);
	}
	void SetTarget(VECTOR target_)//�ǂ�������Ώ�
	{
		target = target_;
		SetPositionAndTarget(pos, target);
	}
	void Update()override;				//�X�V

	void SetPositionAndTarget(VECTOR pos_, VECTOR target_)
		//�^�[�Q�b�g�̃|�W�V��������J�����̃|�W�V�����ݒ�
	{
		pos = pos_;
		target = target_;

		SetCameraPositionAndTargetAndUpVec(pos, target, VGet(0, 1, 0));
	}
	void SetTarget(Objects* target_)		//target�̐ݒ�
	{
		targetObj = target_;
	}
	void FinishCamera();
private:
	VECTOR pos;								//�|�W�V����
	VECTOR target;							//�^�[�Q�b�g�̃x�N�g��
	VECTOR rotateAngle;					//��]�p�x
	Objects* targetObj;						//�^�[�Q�b�g
	bool isAttacking;							//Player���A�^�b�N����
};

#endif//#ifndef CAMERA_H_
