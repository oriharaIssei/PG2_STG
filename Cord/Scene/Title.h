#pragma once
#include "IScene.h"

#include "Button.h"

class Title :
    public IScene {
public:
	void Init()override;

	void Update()override;
	void Draw()override;

	void Unload()override;

	Title(SceneManager* host);
	~Title()=default;
private:
	Button* titleButton_;
};