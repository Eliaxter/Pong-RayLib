#ifndef COLLISION_H
#define COLLISION_H

namespace Game
{
	extern const int dontCheckCollisionFrames;
	extern bool previusFrameCollisionP1;
	extern int lastCollisionFramesP1;
	extern bool previusFrameCollisionP2;
	extern int lastCollisionFramesP2;

	void WindowCollision();
	void WindowLimits();
}
#endif