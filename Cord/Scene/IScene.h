#pragma once
#include "SceneManager.h"

class SceneManager;
class IScene {
public:
	IScene(SceneManager* host);
	virtual ~IScene();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	
	virtual void Unload() = 0;
protected:
	SceneManager* host_;
};