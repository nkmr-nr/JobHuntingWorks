//#pragma once
#ifndef NON_OBJECTS_H_
#define NON_OBJECTS_H_

class NonObjects
{
public:
	NonObjects()
	{

	}
	virtual ~NonObjects()
	{

	}
	virtual void Init() = 0;
	virtual void Update() = 0;
protected:
};

#endif//#define NON_OBJECTS_H_
