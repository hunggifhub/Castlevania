#pragma once
#include "GameObject.h"

#define SIMON_WALKING_SPEED		0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_GRAVITY			0.1f

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_SIT				400

#define SIMON_ANI_IDLE_RIGHT		0
#define SIMON_ANI_IDLE_LEFT			1
#define SIMON_ANI_WALKING_RIGHT		2
#define SIMON_ANI_WALKING_LEFT		3
#define SIMON_NHAY_PHAI				4
#define SIMON_NHAY_TRAI				5

class CSIMON : public CGameObject
{
public:

	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};