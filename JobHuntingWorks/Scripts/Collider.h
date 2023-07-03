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
	VECTOR pos;								//ポジション
	VECTOR rectSize;						//サイズ
};

struct OBBCollider
{
	static const int MaxVertex = 8;		//頂点の数
	static const int AxisNum = 3;

	VECTOR size;								// サイズ
	VECTOR offset;							// オフセット値
	VECTOR verticesPos[MaxVertex];	// 頂点座標
	VECTOR axis[AxisNum];				//軸の数
	MATRIX rotMatrixX;					//Xの行列
	MATRIX rotMatrixY;					//Yの行列
	MATRIX rotMatrixZ;					//Zの行列
	float rotX = 180 * DX_PI / 4.0f;		// 45度の回転をラジアンで表現
	float rotY = 180 * DX_PI / 3.0f;		// 60度の回転をラジアンで表現
	float rotZ = 180 * DX_PI / 2.0f;		// 90度の回転をラジアンで表現
	MATRIX rotationMatrix;				//回転行列

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

		//各頂点の座標情報
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

	// 拡縮調整用(DXLib用)
	void UpdateVertex(MATRIX& mat_, MATRIX& scale_adjustment_matrix_)
	{
		for (int i = 0; i < MaxVertex; i++)
		{
			/*
				@nakachi
					拡縮調整をした後に行列反映する形に変更
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
	VECTOR basicVerticesPos[MaxVertex];	// 頂点座標(変化させない)
};

#endif
