#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Project.h"

class Image
{
private:

	SDL_Texture* texture;

	double angle;

public:
	friend class Graphics;

	void SetAngle(double angle);
	void Rotation(double angle);

	double GetAngle();
	int GetWidth();
	int GetHeight();

	void Destroy();
};

#endif 