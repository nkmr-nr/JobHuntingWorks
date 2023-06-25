//#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "DxLib.h"

struct RectInfomation
{
	RectInfomation(VECTOR* pos_, VECTOR* size_)
		:pos(pos_ != nullptr ? *pos_ : VGet(0, 0, 0))
		, rectSize(size_ != nullptr ? *size_ : VGet(0, 0, 0))
	{
	}
	RectInfomation(VECTOR& pos_, VECTOR& size_)
		:pos(pos_)
		, rectSize(size_)
	{
	}
	VECTOR pos; 

	VECTOR rectSize;
};

struct OBBCollider
{
	static const int MaxVertex = 8;		//���_�̐�
	static const int AxisNum = 3;

	VECTOR size;								// �T�C�Y
	VECTOR offset;							// �I�t�Z�b�g�l
	VECTOR verticesPos[MaxVertex];	// ���_���W
	VECTOR axis[AxisNum];
	MATRIX rotMatrixX;
	MATRIX rotMatrixY;
	MATRIX rotMatrixZ;
	float rotX = DX_PI / 4.0f;  // 45�x�̉�]�����W�A���ŕ\��
	float rotY = DX_PI / 3.0f;  // 60�x�̉�]�����W�A���ŕ\��
	float rotZ = DX_PI / 2.0f;  // 90�x�̉�]�����W�A���ŕ\��
	MATRIX rotationMatrix;

	OBBCollider(VECTOR size_, VECTOR offset_)
		:size(size_)
		, offset(offset_)
		, rotMatrixX(MGetRotX(rotX))
		, rotMatrixY(MGetRotY(rotY))
		, rotMatrixZ(MGetRotZ(rotZ))
		, rotX(DX_PI / 4.0f)
		, rotY(DX_PI / 3.0f)
		, rotZ(DX_PI / 2.0f)
		, rotationMatrix(MMult(MMult(rotMatrixX, rotMatrixY), rotMatrixZ))
	{

		axis[0] = VGet(rotationMatrix.m[0][0], rotationMatrix.m[0][1], rotationMatrix.m[0][2]);
		axis[1] = VGet(rotationMatrix.m[1][0], rotationMatrix.m[1][1], rotationMatrix.m[1][2]);
		axis[2] = VGet(rotationMatrix.m[2][0], rotationMatrix.m[2][1], rotationMatrix.m[2][2]);

		VECTOR half_size = VScale(size, 0.5f);

		//�e���_���W�̏��
		VECTOR vertices[] =
		{
			VGet(-half_size.x, -half_size.y, -half_size.z),
			VGet(-half_size.x, half_size.y, -half_size.z),

			VGet(half_size.x, -half_size.y, -half_size.z),
			VGet(half_size.x, half_size.y, -half_size.z),

			VGet(-half_size.x, -half_size.y, half_size.z),
			VGet(-half_size.x, half_size.y, half_size.z),

			VGet(half_size.x, -half_size.y, half_size.z),
			VGet(half_size.x, half_size.y, half_size.z),
		};

		for (int i = 0; i < MaxVertex; i++)
		{
			verticesPos[i] = basicVerticesPos[i] = VAdd(vertices[i], offset);
		}
	}

	// �g�k�����p
	void UpdateVertex(MATRIX& mat_, MATRIX& scale_adjustment_matrix_)
	{
		for (int i = 0; i < MaxVertex; i++)
		{
			verticesPos[i] = VTransform(basicVerticesPos[i], mat_);
			verticesPos[i] = VTransform(verticesPos[i], scale_adjustment_matrix_);
		}
	}
	VECTOR basicVerticesPos[MaxVertex];	// ���_���W
};

#endif
