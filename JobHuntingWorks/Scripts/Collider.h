//#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "DxLib.h"

struct OBBCollider
{
	static const int MaxVertex = 8;		//���_�̐�

	VECTOR size;								// �T�C�Y
	VECTOR offset;							// �I�t�Z�b�g�l
	VECTOR verticesPos[MaxVertex];	// ���_���W

	OBBCollider(VECTOR size_, VECTOR offset_) :
		size(size_),
		offset(offset_)
	{
		
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

private:
	VECTOR basicVerticesPos[MaxVertex];	// ���_���W
};

#endif
