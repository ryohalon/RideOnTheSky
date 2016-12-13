#pragma once
#include "cinder/Easing.h"
#include "cinder/Vector.h"



namespace Easing
{
	static const float& Linear(float t, const float &b, const float &e) {
		return (e - b) * t + b;
	}

	static const float& BackIn(float t, const float& b, const float& e) {
		const float& s = 1.70158f;
		return (e - b) * t * t * ((s + 1) * t - s) + b;
	}

	static const float& BackOut(float t, const float& b, const float& e) {
		const float& s = 1.70158f;
		t -= 1.0;
		return (e - b) * (t * t * ((s + 1) * t + s) + 1) + b;
	}

	static const float& BackInOut(float t, const float& b, const float& e) {
		const float& s = 1.70158f * 1.525f;
		if ((t /= 0.5) < 1) return (e - b) / 2 * (t * t * ((s + 1) * t - s)) + b;
		t -= 2;
		return (e - b) / 2 * (t * t * ((s + 1) * t + s) + 2) + b;
	}

	static const float& BounceOut(float t, const float& b, const float& e) {
		if (t < (1 / 2.75f)) {
			return (e - b) * (7.5625f * t * t) + b;
		}
		else if (t < (2 / 2.75f)) {
			t -= (1.5f / 2.75f);
			return (e - b) * (7.5625f * t * t + 0.75f) + b;
		}
		else if (t < (2.5 / 2.75)) {
			t -= (2.25f / 2.75f);
			return (e - b) * (7.5625f * t * t + 0.9375f) + b;
		}
		else {
			t -= (2.625f / 2.75f);
			return (e - b) * (7.5625f * t * t + 0.984375f) + b;
		}
	}

	static  const float& BounceIn(float t, const float& b, const float& e) {
		return (e - b) - BounceOut(1.0f - t, 0.f, e - b) + b;
	}

	static const float& BounceInOut(float t, const float& b, const float& e) {
		if (t < 0.5f) return BounceIn(t * 2.f, 0.f, e - b) * 0.5f + b;
		else         return BounceOut(t * 2.f - 1.0f, 0.f, e - b) * 0.5f + (e - b) * 0.5f + b;
	}

	static const float& CircIn(float t, const float& b, const float& e) {
		return -(e - b) * (std::sqrt(1 - t * t) - 1) + b;
	}

	static const float& CircOut(float t, const float& b, const float& e) {
		t -= 1.0;
		return (e - b) * std::sqrt(1 - t * t) + b;
	}

	static const float& CircInOut(float t, const float& b, const float& e) {
		if ((t /= 0.5) < 1) return -(e - b) / 2 * (std::sqrt(1 - t * t) - 1) + b;
		t -= 2;
		return (e - b) / 2 * (std::sqrt(1 - t * t) + 1) + b;
	}

	static const float& CubicIn(float t, const float& b, const float& e) {
		return (e - b) * t * t * t + b;
	}

	static const float& CubicOut(float t, const float& b, const float& e) {
		t -= 1.0;
		return (e - b) * (t * t * t + 1) + b;
	}

	static const float& CubicInOut(float t, const float& b, const float& e) {
		if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t + b;
		t -= 2;
		return (e - b) / 2 * (t * t * t + 2) + b;
	}

	static const float& ElasticIn(float t, const float& b, const float& e) {
		if (t == 0) return b;
		if (t == 1) return e;

		const float& p = 0.3f;
		const float& a = e - b;
		const float& s = p / 4.f;
		t -= 1.f;
		return -(a * std::pow(2.f, 10.f * t) * std::sin((t - s) * (2.f * float(M_PI)) / p)) + b;
	}

	static const float& ElasticOut(float t, const float& b, const float& e) {
		if (t == 0) return b;
		if (t == 1) return e;

		const float& p = 0.3f;
		const float& a = e - b;
		const float& s = p / 4.f;
		return (a * std::pow(2.f, -10.f * t) * std::sin((t - s) * (2.f * float(M_PI)) / p) + a + b);
	}

	static const float& ElasticInOut(float t, const float& b, const float& e) {
		if (t == 0) return b;
		if ((t /= 0.5) == 2) return e;

		const float& p = 0.3f * 1.5f;
		const float& a = e - b;
		const float& s = p / 4.f;
		if (t < 1.f) {
			t -= 1.f;
			return -0.5f * (a * std::pow(2.f, 10.f * t) * std::sin((t - s) * (2.f * float(M_PI)) / p)) + b;
		}
		t -= 1;
		return a * std::pow(2.f, -10.f * t) * std::sin((t - s) * (2.f * float(M_PI)) / p) * 0.5f + a + b;
	}

	static const float& ExpoIn(float t, const float& b, const float& e) {
		return (t == 0) ? b : (e - b) * std::pow(2.f, 10.f * (t - 1.f)) + b;
	}

	static const float& ExpoOut(float t, const float& b, const float& e) {
		return (t == 1.f) ? e : (e - b) * (-std::pow(2.f, -10.f * t) + 1.f) + b;
	}

	static const float& ExpoInOut(float t, const float& b, const float& e) {
		if (t == 0) return b;
		if (t == 1) return e;
		if ((t /= 0.5f) < 1) return (e - b) / 2.f * std::pow(2.f, 10.f * (t - 1.f)) + b;
		return (e - b) / 2.f * (-std::pow(2.f, -10.f* --t) + 2.f) + b;
	}

	static const float& QuadIn(float t, const float& b, const float& e) {
		return (e - b) * t * t + b;
	}

	static const float& QuadOut(float t, const float& b, const float& e) {
		return -(e - b) * t * (t - 2) + b;
	}

	static const float& QuadInOut(float t, const float& b, const float& e) {
		if ((t /= 0.5) < 1) return (e - b) / 2 * t * t + b;
		--t;
		return -(e - b) / 2 * (t * (t - 2) - 1) + b;
	}

	static const float& QuartIn(float t, const float& b, const float& e) {
		return (e - b) * t * t * t * t + b;
	}

	static const float& QuartOut(float t, const float& b, const float& e) {
		t -= 1.0;
		return -(e - b) * (t * t * t * t - 1) + b;
	}

	static const float& QuartInOut(float t, const float& b, const float& e) {
		if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t * t + b;
		t -= 2;
		return -(e - b) / 2 * (t * t * t * t - 2) + b;
	}

	static const float& QuintIn(float t, const float& b, const float& e) {
		return (e - b) * t * t * t * t * t + b;
	}

	static const float& QuintOut(float t, const float& b, const float& e) {
		t -= 1.0;
		return (e - b) * (t * t * t * t * t + 1) + b;
	}

	static const float& QuintInOut(float t, const float& b, const float& e) {
		if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t * t * t + b;
		t -= 2;
		return (e - b) / 2 * (t * t * t * t * t + 2) + b;
	}

	static const float& SineIn(float t, const float& b, const float& e) {
		return -(e - b) * std::cos(t * (float(M_PI) / 2.f)) + (e - b) + b;
	}

	static const float& SineOut(float t, const float& b, const float& e) {
		return (e - b) * std::sin(t * (float(M_PI) / 2.f)) + b;
	}

	static const float& SineInOut(float t, const float& b, const float& e) {
		return -(e - b) / 2.f * (std::cos(float(M_PI) * t) - 1.f) + b;
	}

	static const ci::Vec2f& QuadOut(float t, const ci::Vec2f& b, const ci::Vec2f& e) {
		return ci::Vec2f(-(e.x - b.x) * t * (t - 2) + b.x,
			-(e.y - b.y) * t * (t - 2) + b.y);
	}
};