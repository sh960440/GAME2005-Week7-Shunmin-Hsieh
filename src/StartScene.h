#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include <cmath>

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	/*Label* m_pStartLabel;
	Label* m_pInstructionsLabel;*/

	Ship* m_pShip;

	glm::vec2 m_mousePosition;

	// ImGui utility functions 用於介面
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables 用於介面
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;

	// Physics Variable 物理變量
	const float Deg2Rad = 0.0174532925f; // 轉換degree到radian
	const float Rad2Deg = 57.2957795130f; // 轉換radian到degree
	bool m_bIsGravityEnabled = false;
	float m_fGravity = 9.8f;
	float m_fPPM = 5.0f; // pixels per meter - scale
	glm::vec2 m_finalPosition = glm::vec2(0.0f, 0.0f);
	float m_velocity = 100.0f;
	float m_fVelocityX = 0.0f;
	float m_fVelocityY = 0.0f;
	glm::vec2 m_acceleration = glm::vec2(0.0f, 0.0f);
	float m_fTime = 0.016667f; // 大約 16 ms
	float m_fAtime = 0.016667f; // 累積時間 accumulated time

	float m_fAngle = 45.0f; // the "kicking" angle

	// Physics Function 物理函數
	void m_move();

};

#endif /* defined (__START_SCENE__) */