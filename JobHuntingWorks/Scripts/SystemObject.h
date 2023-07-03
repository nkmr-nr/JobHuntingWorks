//#pragma once
#ifndef SYSTEM_OBJECT_H_
#define SYSTEM_OBJECT_H_

class SystemObject
{
public:
	SystemObject()
	{

	}
	virtual ~SystemObject()
	{

	}
	virtual void Init() = 0;
	virtual void Update() = 0;
protected:
};

#endif//#define SYSTEM_OBJECT_H_
