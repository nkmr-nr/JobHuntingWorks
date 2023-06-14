//#pragma once
#ifndef OBJECTS_H_
#define OBJECTS_H_

#include<DxLib.h>

class Objects
{
public:
	Objects(VECTOR pos_,VECTOR rotateDegree_,VECTOR scale_,int modelHandle_,int stageHandle_,int healthPoint_)
		:isActive(true)
		,pos(pos_)
		, rotateDegree(rotateDegree_)
		,scale(scale_)
		,modelHandle(modelHandle_)
		,stageHandle(stageHandle_)
		,healthPoint(healthPoint_)
	{

	}
	virtual~Objects()
	{

	}
	virtual void Init() = 0;			//オブジェクトの初期化
	virtual void Update() = 0;		//オブジェクトの更新
	virtual void Draw() = 0;		//オブジェクトの描画
	VECTOR GetPos()				//オブジェクトのポジション情報
	{
		return pos;
	}
	VECTOR GetRadius()			//オブジェクトの角度
	{
		return rotateDegree;
	}
	int GetModelHandle()			//オブジェクトのモデル情報
	{
		return modelHandle;
	}
	bool IsActive()						//オブジェクトの生存確認
	{
		return isActive;
	}
	void OnCollisionStage();		//オブジェクトとステージの当たり判定
protected:
	bool isActive;						//生存してるか
	VECTOR pos;						//ポジション
	VECTOR rotateDegree;		//角度
	VECTOR scale;					//大きさ
	int modelHandle;					//画像ハンドル
	int stageHandle;					//ステージとの当たり判定用
	int healthPoint;					//体力
};

#endif//#define OBJECTS_H_
