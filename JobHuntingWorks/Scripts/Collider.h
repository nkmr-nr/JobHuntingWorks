//#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "DxLib.h"
#include<utility>
#include <vector>

#define DEBUG_COLLISION

struct RectCollider
{
	RectCollider(VECTOR* pos_, VECTOR* size_)
		:pos(pos_ != nullptr ? *pos_ : VGet(0, 0, 0))
		, rectSize(size_ != nullptr ? *size_ : VGet(0, 0, 0))
	{
	}
	VECTOR pos;								//�|�W�V����
	VECTOR rectSize;						//�T�C�Y
};

struct OBBCollider
{
	static const int MaxVertex = 8;		//���_�̐�
	static const int AxisNum = 3;

	VECTOR size;								// �T�C�Y
	VECTOR offset;							// �I�t�Z�b�g�l
	VECTOR verticesPos[MaxVertex];	// ���_���W
	VECTOR axis[AxisNum];				//���̐�
	MATRIX rotMatrixX;					//X�̍s��
	MATRIX rotMatrixY;					//Y�̍s��
	MATRIX rotMatrixZ;					//Z�̍s��
	float rotX = 180 * DX_PI / 4.0f;		// 45�x�̉�]�����W�A���ŕ\��
	float rotY = 180 * DX_PI / 3.0f;		// 60�x�̉�]�����W�A���ŕ\��
	float rotZ = 180 * DX_PI / 2.0f;		// 90�x�̉�]�����W�A���ŕ\��
	MATRIX rotationMatrix;				//��]�s��

	OBBCollider(VECTOR size_, VECTOR offset_)
		:size(size_)
		, offset(offset_)
		, rotMatrixX(MGetRotX(rotX))
		, rotMatrixY(MGetRotY(rotY))
		, rotMatrixZ(MGetRotZ(rotZ))
		, rotX(180 / 4.0f)
		, rotY(180 / 3.0f)
		, rotZ(180 / 2.0f)
		, rotationMatrix(MMult(MMult(rotMatrixX, rotMatrixY), rotMatrixZ))
	{

		axis[0] = VGet(rotationMatrix.m[0][0], rotationMatrix.m[0][1], rotationMatrix.m[0][2]);
		axis[1] = VGet(rotationMatrix.m[1][0], rotationMatrix.m[1][1], rotationMatrix.m[1][2]);
		axis[2] = VGet(rotationMatrix.m[2][0], rotationMatrix.m[2][1], rotationMatrix.m[2][2]);
		VECTOR half_size = VScale(size, 0.5f);

		//�e���_�̍��W���
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

	// �g�k�����p(DXLib�p)
	void UpdateVertex(MATRIX& mat_, MATRIX& scale_adjustment_matrix_)
	{
		for (int i = 0; i < MaxVertex; i++)
		{
			/*
				@nakachi
					�g�k������������ɍs�񔽉f����`�ɕύX
			*/
			verticesPos[i] = VTransform(basicVerticesPos[i], scale_adjustment_matrix_);
			verticesPos[i] = VTransform(verticesPos[i], mat_);
		}
	}
#ifdef DEBUG_COLLISION
	void Draw()
	{
		std::vector<std::pair<VECTOR, VECTOR>> line_list =
		{
			{ verticesPos[0], verticesPos[1] },
			{ verticesPos[0], verticesPos[2] },
			{ verticesPos[0], verticesPos[4] },

			{ verticesPos[1], verticesPos[3] },
			{ verticesPos[1], verticesPos[5] },

			{ verticesPos[3], verticesPos[2] },
			{ verticesPos[3], verticesPos[7] },

			{ verticesPos[2], verticesPos[6] },

			{ verticesPos[5], verticesPos[4] },
			{ verticesPos[5], verticesPos[7] },

			{ verticesPos[7], verticesPos[6] },

			{ verticesPos[4], verticesPos[6] },
		};

		unsigned int color = GetColor(255, 255, 255);
		for (const auto& pair : line_list)
		{
			DrawLine3D(pair.first, pair.second, color);
		}
	}
#endif
private:
	VECTOR basicVerticesPos[MaxVertex];	// ���_���W(�ω������Ȃ�)
};

#endif
