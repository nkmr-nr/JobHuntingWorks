
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
    // RectCollider�̋�`�̏����擾
    VECTOR rectPos = rect.pos;
    VECTOR rectSize = rect.rectSize;
    float rectHalfWidth = rectSize.x / 2.0f;
    float rectHalfHeight = rectSize.y / 2.0f;
    float rectHalfDepth = rectSize.z / 2.0f;

    // OBBCollider�̒��_���W���擾
    VECTOR* obbVertices = obb.verticesPos;

    // OBBCollider�̎��x�N�g�����擾
    VECTOR* obbAxis = obb.axis;

    // OBBCollider�̃T�C�Y�����擾
    VECTOR obbSize = obb.size;
    float obbHalfWidth = obbSize.x / 2.0f;
    float obbHalfHeight = obbSize.y / 2.0f;
    float obbHalfDepth = obbSize.z / 2.0f;

    // OBBCollider�̒��S�ʒu���v�Z
    VECTOR obbCenter = VAdd(obb.offset, rectPos);

    // OBBCollider�̊e����RectCollider�̎��Ƃ̕������e�X�g
    for (int i = 0; i < OBBCollider::AxisNum; i++)
    {
        // OBBCollider�̎��x�N�g�����擾
        VECTOR axis = obbAxis[i];

        // OBBCollider�̓��e�͈͂��v�Z
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectCollider�̓��e�͈͂��v�Z
        float rectMin = VDot(rectPos, axis) - rectHalfWidth * fabsf(axis.x) - rectHalfHeight * fabsf(axis.y) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.x * fabsf(axis.x) + rectSize.y * fabsf(axis.y) + rectSize.z * fabsf(axis.z);

        // �������e�X�g
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    // RectCollider�̊e����OBBCollider�̕ӂƂ̕������e�X�g���s��
    for (int i = 0; i < 3; i++)
    {
        // OBBCollider�̎��x�N�g�����擾
        VECTOR axis = VCross(obbAxis[i], VGet(0, 1, 0));

        // OBBCollider�̓��e�͈͂��v�Z
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectCollider�̓��e�͈͂��v�Z
        float rectMin = VDot(rectPos, axis) - rectHalfWidth * fabsf(axis.x) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.x * fabsf(axis.x) + rectSize.z * fabsf(axis.z);

        // �������e�X�g
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        // OBBCollider�̎��x�N�g�����擾
        VECTOR axis = VCross(obbAxis[i], VGet(1, 0, 0));

        // OBBCollider�̓��e�͈͂��v�Z
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectCollider�̓��e�͈͂��v�Z
        float rectMin = VDot(rectPos, axis) - rectHalfHeight * fabsf(axis.y) - rectHalfDepth * fabsf(axis.z);
        float rectMax = rectMin + rectSize.y * fabsf(axis.y) + rectSize.z * fabsf(axis.z);

        // �������e�X�g
        if (rectMax < obbMin || obbMax < rectMin)
        {
            return false;
        }
    }

    // RectCollider�̊e�ӂ�OBBCollider�̖ʂƂ̕������e�X�g���s��
    for (int i = 0; i < 3; i++)
    {
        // OBBCollider�̎��x�N�g�����擾
        VECTOR axis = obbAxis[i];

        // OBBCollider�̓��e�͈͂��v�Z
        float obbMin = FLT_MAX;
        float obbMax = -FLT_MAX;
        for (int j = 0; j < OBBCollider::MaxVertex; j++)
        {
            float dotProduct = VDot(obbVertices[j], axis);
            obbMin = fminf(obbMin, dotProduct);
            obbMax = fmaxf(obbMax, dotProduct);
        }

        // RectCollider�̕ӂ̕����x�N�g�����v�Z
        VECTOR edgeDir1 = VSub(VGet(rectHalfWidth, 0, 0), VGet(-rectHalfWidth, 0, 0));
        VECTOR edgeDir2 = VSub(VGet(0, rectHalfHeight, 0), VGet(0, -rectHalfHeight, 0));
        VECTOR edgeDir3 = VSub(VGet(0, 0, rectHalfDepth), VGet(0, 0, -rectHalfDepth));

        // RectCollider�̕ӂ̕����x�N�g����OBBCollider�̍��W��Ԃɕϊ�
        edgeDir1 = VTransform(edgeDir1, obb.rotationMatrix);
        edgeDir2 = VTransform(edgeDir2, obb.rotationMatrix);
        edgeDir3 = VTransform(edgeDir3, obb.rotationMatrix);

        // RectCollider�̕ӂ̕����x�N�g����OBBCollider�̖ʂƂ̕������e�X�g���s��
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

    // �������e�X�g�ɂ��ׂč��i�����ꍇ�A�Փ˂��Ă鎖����
    return true;
}

bool Collision::SeparatingAxisTest(const VECTOR& rectPos, const VECTOR& edgeDir, float rectHalfWidth, float rectHalfHeight, float rectHalfDepth, const VECTOR& obbCenter, const VECTOR& obbSize, const VECTOR obbAxis[3], float obbMin, float obbMax)
{
    // RectCollider�̕ӂ̕����x�N�g���̒������擾
    float edgeLength = VSize(edgeDir);

    // RectCollider�̕ӂ̕����x�N�g���𐳋K��
    VECTOR edgeDirNormalized = VScale(edgeDir, 1.0f / edgeLength);

    // RectCollider�̕ӂ̕����x�N�g����OBBCollider�̖ʂ̖@���x�N�g���Ƃ̊O�ς��v�Z
    VECTOR crossProduct = VCross(edgeDirNormalized, obbSize);

    // OBBCollider�̒��S�ʒu����RectCollider�̒��S�ʒu�ւ̃x�N�g�����v�Z
    VECTOR centerToCenter = VSub(rectPos, obbCenter);

    // RectCollider�̕ӂ̕����x�N�g����OBBCollider�̖ʂ̖@���x�N�g���Ƃ̓��ς��v�Z
    float dotProduct = VDot(centerToCenter, crossProduct);

    // RectCollider�̕ӂ̕����x�N�g����OBBCollider�̖ʂ̖@���x�N�g�����������Ă���ꍇ�A�������ƂȂ邽�ߏՓ˂��Ă��Ȃ��Ɣ���
    if (fabsf(dotProduct) > edgeLength * VSize(crossProduct))
    {
        return false;
    }

    // OBBCollider�̓��e�͈͂��v�Z
    float obbProjection = dotProduct + obbMin * edgeLength;
    float obbProjectionMin = obbProjection - obbSize.x * VDot(edgeDirNormalized, obbAxis[0]) - obbSize.y * VDot(edgeDirNormalized, obbAxis[1]) - obbSize.z * VDot(edgeDirNormalized, obbAxis[2]);
    float obbProjectionMax = obbProjection + obbSize.x * VDot(edgeDirNormalized, obbAxis[0]) + obbSize.y * VDot(edgeDirNormalized, obbAxis[1]) + obbSize.z * VDot(edgeDirNormalized, obbAxis[2]);

    // RectCollider�̓��e�͈͂��v�Z
    float rectProjection = VDot(rectPos, edgeDirNormalized) - rectHalfWidth * fabsf(VDot(edgeDirNormalized, VGet(1, 0, 0))) - rectHalfHeight * fabsf(VDot(edgeDirNormalized, VGet(0, 1, 0))) - rectHalfDepth * fabsf(VDot(edgeDirNormalized, VGet(0, 0, 1)));
    float rectProjectionMin = rectProjection;
    float rectProjectionMax = rectProjection + edgeLength;

    // �������e�X�g
    if (rectProjectionMax < obbProjectionMin || obbProjectionMax < rectProjectionMin)
    {
        return false;
    }

    // �������e�X�g�ɍ��i�����ꍇ�A�Փ˂��Ă��Ȃ��Ɣ���
    return true;
}
