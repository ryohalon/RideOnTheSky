#pragma once
#include "cinder/Matrix.h"
#include "cinder/gl/gl.h"
#include "../Object.h"
#include "../Component/Transform/Transform.h"
#include "../../Utillity/Manager/SoundManager/SoundManager.h"
#include "../../Utillity/Manager/TextureManager/TextureManager.h"


class GameObject : public Object
{
private:

protected:

	Transform transform;
	ci::Matrix44f matrix;

	bool is_stop;

public:

	Transform GetTransform() const { return transform; }
	ci::Matrix44f GetMatrix() const { return matrix; }
	bool GetIsStop() const { return is_stop; }

	void SetTransform(const Transform &transform_) { transform = transform_; }
	void SetMatrix(const ci::Matrix44f &matrix_) { matrix = matrix_; }
	void SetIsStop(const bool &is_stop_) { is_stop = is_stop_; }

public:

	GameObject() :
		matrix(ci::Matrix44f::identity()),
		transform(Transform())
	{}
	GameObject(const Transform &transform) :
		transform(transform)
	{

	}
	virtual ~GameObject() {}

	void UpdateMatrix()
	{
		ci::Matrix44f mtranslate = ci::Matrix44f::createTranslation(transform.translate);
		ci::Matrix44f mrotate = ci::Matrix44f::createRotation(transform.rotate);
		ci::Matrix44f mscale = ci::Matrix44f::createScale(transform.scale);

		matrix = mtranslate * mrotate * mscale;
	}

	virtual void Setup() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};