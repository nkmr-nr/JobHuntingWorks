
#include "Collision.h"
#include <math.h>
#include <cfloat>
#include<iostream>

void Collision::Init()
{

}

void Collision::Update()
{
}

bool Collision::CheckCollision(RectCollider& rect, OBBCollider& obb)
{
    // RectColliderの矩形の情報を取得
    VECTOR rectPos = rect.pos;
    VECTOR rectSize = rect.rectSize;
    float rectHalfWidth = rectSize.x / 2.0f;
    float rectHalfHeight = rectSize.y / 2.0f;
    float rectHalfDepth = rectSize.z / 2.0f;

    // OBBColliderの頂点座標を取得
    VECTOR* obbVertices = obb.verticesPos;

    // OBBColliderの軸ベクトルを取得
    VECTOR* obbAxis = obb.axis;

    // OBBColliderのサイズ情報を取得
    VECTOR obbSize = obb.size;
    float obbHalfWidth = obbSize.x / 2.0f;
    float obbHalfHeight = obbSize.y / 2.0f;
    float obbHalfDepth = obbSize.z / 2.0f;

    // OBBColliderの中心位置を計算
    VECTOR obbCenter = VAdd(obb.offset, rectPos);

    // OBBColliderの各軸とRectColliderの軸との分離軸テスト
    for (int i = 0; i < OBBCollider::AxisNum; i++)
    {
        // OBBColliderの軸ベクトルを取得
        VECTOR axis = obbAxis[i];

        // OBBColliderの投影範囲を計算
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectColliderの投影範囲を計算
        float rectMin = VDot(rectPos, axis) - rectHalfWidth * fabsf(axis.x) - rectHalfHeight * fabsf(axis.y) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.x * fabsf(axis.x) + rectSize.y * fabsf(axis.y) + rectSize.z * fabsf(axis.z);

        // 分離軸テスト
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    // RectColliderの各軸とOBBColliderの辺との分離軸テストを行う
    for (int i = 0; i < 3; i++)
    {
        // OBBColliderの軸ベクトルを取得
        VECTOR axis = VCross(obbAxis[i], VGet(0, 1, 0));

        // OBBColliderの投影範囲を計算
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectColliderの投影範囲を計算
        float rectMin = VDot(rectPos, axis) - rectHalfWidth * fabsf(axis.x) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.x * fabsf(axis.x) + rectSize.z * fabsf(axis.z);

        // 分離軸テスト
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        // OBBColliderの軸ベクトルを取得
        VECTOR axis = VCross(obbAxis[i], VGet(1, 0, 0));

        // OBBColliderの投影範囲を計算
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectColliderの投影範囲を計算
        float rectMin = VDot(rectPos, axis) - rectHalfHeight * fabsf(axis.y) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.y * fabsf(axis.y) + rectSize.z * fabsf(axis.z);

        // 分離軸テスト
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    // RectColliderの各辺とOBBColliderの面との分離軸テストを行う
    for (int i = 0; i < 3; i++)
    {
        // OBBColliderの軸ベクトルを取得
        VECTOR axis = obbAxis[i];

        // OBBColliderの投影範囲を計算
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectColliderの辺の方向ベクトルを計算
        VECTOR edgeDir1 = VSub(VGet(rectHalfWidth, 0, 0), VGet(-rectHalfWidth, 0, 0));
        VECTOR edgeDir2 = VSub(VGet(0, rectHalfHeight, 0), VGet(0, -rectHalfHeight, 0));
        VECTOR edgeDir3 = VSub(VGet(0, 0, rectHalfDepth), VGet(0, 0, -rectHalfDepth));

        // RectColliderの辺の方向ベクトルをOBBColliderの座標空間に変換
        edgeDir1 = VTransform(edgeDir1, obb.rotationMatrix);
        edgeDir2 = VTransform(edgeDir2, obb.rotationMatrix);
        edgeDir3 = VTransform(edgeDir3, obb.rotationMatrix);

        // RectColliderの辺の方向ベクトルとOBBColliderの面との分離軸テストを行う
        if (!SeparatingAxisTest(rectPos, edgeDir1, rectHalfWidth, rectHalfHeight, rectHalfDepth, obbCenter, obbSize, &obbAxis[i], obbMin, obbMax) == false)
        {
            return false;
        }
        if (!SeparatingAxisTest(rectPos, edgeDir2, rectHalfWidth, rectHalfHeight, rectHalfDepth, obbCenter, obbSize, &obbAxis[i], obbMin, obbMax) == false)
        {
            return false;
        }
        if (!SeparatingAxisTest(rectPos, edgeDir3, rectHalfWidth, rectHalfHeight, rectHalfDepth, obbCenter, obbSize, &obbAxis[i], obbMin, obbMax) == false)
        {
            return false;
        }
    }

    // 分離軸テストにすべて合格した場合、衝突してる事判定
    return true;
}

bool Collision::SeparatingAxisTest(const VECTOR& rectPos, const VECTOR& edgeDir, float rectHalfWidth, float rectHalfHeight, float rectHalfDepth, const VECTOR& obbCenter, const VECTOR& obbSize, const VECTOR obbAxis[3], float obbMin, float obbMax)
{
    // RectColliderの辺の方向ベクトルの長さを取得
    float edgeLength = VSize(edgeDir);

    // RectColliderの辺の方向ベクトルを正規化
    VECTOR edgeDirNormalized = VScale(edgeDir, 1.0f / edgeLength);

    // RectColliderの辺の方向ベクトルとOBBColliderの面の法線ベクトルとの外積を計算
    VECTOR crossProduct = VCross(edgeDirNormalized, obbSize);

    // OBBColliderの中心位置からRectColliderの中心位置へのベクトルを計算
    VECTOR centerToCenter = VSub(rectPos, obbCenter);

    // RectColliderの辺の方向ベクトルとOBBColliderの面の法線ベクトルとの内積を計算
    float dotProduct = VDot(centerToCenter, crossProduct);

    // RectColliderの辺の方向ベクトルとOBBColliderの面の法線ベクトルが直交している場合、分離軸となるため衝突していないと判定
    if (fabsf(dotProduct) > edgeLength * VSize(crossProduct))
    {
        return false;
    }

    // OBBColliderの投影範囲を計算
    float obbProjection = dotProduct + obbMin * edgeLength;
    float obbProjectionMin = obbProjection - obbSize.x * VDot(edgeDirNormalized, obbAxis[0]) - obbSize.y * VDot(edgeDirNormalized, obbAxis[1]) - obbSize.z * VDot(edgeDirNormalized, obbAxis[2]);
    float obbProjectionMax = obbProjection + obbSize.x * VDot(edgeDirNormalized, obbAxis[0]) + obbSize.y * VDot(edgeDirNormalized, obbAxis[1]) + obbSize.z * VDot(edgeDirNormalized, obbAxis[2]);

    // RectColliderの投影範囲を計算
    float rectProjection = VDot(rectPos, edgeDirNormalized) - rectHalfWidth * fabsf(VDot(edgeDirNormalized, VGet(1, 0, 0))) - rectHalfHeight * fabsf(VDot(edgeDirNormalized, VGet(0, 1, 0))) - rectHalfDepth * fabsf(VDot(edgeDirNormalized, VGet(0, 0, 1)));
    float rectProjectionMin = rectProjection;
    float rectProjectionMax = rectProjection + edgeLength;

    // 分離軸テスト
    if (rectProjectionMax < obbProjectionMin || obbProjectionMax < rectProjectionMin)
    {
        return false;
    }

    // 分離軸テストに合格した場合、衝突していないと判定
    return true;
}
