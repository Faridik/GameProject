#include "Project.h"

void Image::SetAngle(double angle)
{
	this->angle = angle;
}

void Image::Rotation(double angle)
{
	this->angle += angle;
	if (this->angle >= 360)
	{
		int n;
		n = this->angle / 360;
		this->angle -= n * 360;
	}
	if (this->angle < 0)
	{
		int n;
		n = -(this->angle / 360) + 1;
		this->angle += n * 360;
	}
}

double Image::GetAngle()
{
	return this->angle;
}

int Image::GetWidth()
{
	int width;

	SDL_QueryTexture(texture, NULL, NULL, &width, NULL);

	return width;
}

int Image::GetHeight()
{
	int height;

	SDL_QueryTexture(texture, NULL, NULL, NULL, &height);

	return height;
}

void Image::Destroy()
{
	SDL_DestroyTexture(texture);
}