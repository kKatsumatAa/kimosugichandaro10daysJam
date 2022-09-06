#pragma once

class Iscene
{
public:
	virtual ~Iscene() {};
	virtual void Update() =0;
	virtual void Draw() =0;
	virtual bool IsEnd() =0;
	virtual Iscene* GetNextScene() =0;
};

class NullScene//null����ꂽ���Ƃ��Ɏg��
{
public:
	virtual ~NullScene() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool IsEnd() = 0;
	virtual Iscene* GetNextScene() = 0;
};
