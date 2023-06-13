//#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "DxLib.h"

struct OBBCollider
{
	static const int MaxVertex = 8;		//頂点の数

	VECTOR size;								// サイズ
	VECTOR offset;							// オフセット値
	VECTOR verticesPos[MaxVertex];	// 頂点座標

	OBBCollider(VECTOR size_, VECTOR offset_) :
		size(size_),
		offset(offset_)
	{
		
		VECTOR half_size = VScale(size, 0.5f);

		//各頂点座標の情報
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

	// 拡縮調整用
	void UpdateVertex(MATRIX& mat_, MATRIX& scale_adjustment_matrix_)
	{
		for (int i = 0; i < MaxVertex; i++)
		{
			verticesPos[i] = VTransform(basicVerticesPos[i], mat_);
			verticesPos[i] = VTransform(verticesPos[i], scale_adjustment_matrix_);
		}
	}

private:
	VECTOR basicVerticesPos[MaxVertex];	// 頂点座標
};

#endif
