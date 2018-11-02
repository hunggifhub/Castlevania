#include "Simon.h"

void CSIMON::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	vy += SIMON_GRAVITY;
	if (y > 100)
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CSIMON::Render()
{
	int ani;
	if (vx == 0)
	{
		if (state == SIMON_STATE_JUMP || state == SIMON_STATE_SIT) {
			if (nx > 0) ani = SIMON_NHAY_PHAI;
			else ani = SIMON_NHAY_TRAI;
		}
		else if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
		else ani = SIMON_ANI_IDLE_LEFT;
	}
	else if (vx > 0)
		ani = SIMON_ANI_WALKING_RIGHT;
	else ani = SIMON_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
}

void CSIMON::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	case SIMON_STATE_WALKING_LEFT:
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		break;
	case SIMON_STATE_JUMP:
		if (y == 100)
			vy = -SIMON_JUMP_SPEED_Y;

	case SIMON_STATE_IDLE:
		vx = 0;
		break;
	}
}

