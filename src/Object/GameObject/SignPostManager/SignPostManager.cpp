#include "SignPostManager.h"



void SignPostManager::PostLoad()
{
	std::ifstream ifstr(ci::app::getAssetPath("LoadFile/Stage/StageSignPost.txt").string());

	if (!ifstr.is_open())
		assert(!"StageSignPost.txt not exist");

	while (!ifstr.eof())
	{
		ci::Vec3f pos;
		ifstr >> pos.x >> pos.y >> pos.z;
		signposts.push_back(SignPost(pos));
	}
}

void SignPostManager::SetDirection()
{
	for (int i = 0; i < static_cast<int>(signposts.size()) - 1; i++)
		signposts[i].SetDirection(signposts[i + 1].GetTransform().position);

	// 最後の頂点に対して最初の頂点をつなげる
	signposts.back().SetDirection(signposts.front().GetTransform().position);
}

void SignPostManager::SetRingQuat()
{
	// 一つ手前の頂点からリングの角度を計算
	signposts.front().SetRingQuat(signposts.back().GetTransform().position);

	for (int i = 1; i < static_cast<int>(signposts.size()); i++)
		signposts[i].SetRingQuat(signposts[i - 1].GetTransform().position);
}

void SignPostManager::SetLength()
{
	float length = 0;
	for (auto& signpost : signposts)
	{
		signpost.SetLength(length);
		length += signpost.GetDirection().length();
	}
}

ci::Matrix44f SignPostManager::GetStageMatrix(const ci::Vec3f &position)
{
	float length = fmod(position.z, round_length);

	ci::Matrix44f stage_matrix = ci::Matrix44f::identity();

	for (int i = 0; i < static_cast<int>(signposts.size()) - 1; i++) {
		if (signposts[i].GetLength() < length)
			continue;
		if (length >= signposts[i + 1].GetLength())
			continue;

		stage_matrix *= ci::Matrix44f::createTranslation(signposts[i].GetTransform().position);
		stage_matrix *= signposts[i].GetMatrix();
		stage_matrix *= ci::Matrix44f::createTranslation(
			ci::Vec3f(position.x, position.y, length - signposts[i].GetLength()));
		return stage_matrix;
	}

	stage_matrix *= ci::Matrix44f::createTranslation(signposts.back().GetTransform().position);
	stage_matrix *= signposts.back().GetMatrix();
	stage_matrix *= ci::Matrix44f::createTranslation(
		ci::Vec3f(position.x, position.y, length - signposts.back().GetLength()));

	return stage_matrix;
}

SignPostManager::SignPostManager()
{

}

void SignPostManager::Setup()
{
	PostLoad();
	SetDirection();
	SetRingQuat();
	SetLength();
	round_length = signposts.back().GetLength()
		+ signposts.back().GetDirection().length();

	for (auto &signpost : signposts)
	{
		signpost.SetMaterial(ci::gl::Material(
			ci::ColorA(0.6f, 1.0f, 0.6f, 1.0f),      // Ambient
			ci::ColorA(0.6f, 1.0f, 0.6f, 1.0f),      // Diffuse
			ci::ColorA(0.6f, 1.0f, 0.6f, 1.0f),      // Specular
			80.0f,									 // Shininess
			ci::ColorA(0.5f, 0.5f, 0.5f, 1.0f)));	 // Emission
	}
}

void SignPostManager::Update()
{

}

void SignPostManager::Draw()
{
	for (auto& signpost : signposts)
	{
		if (!Collision::IsHitSphereToSphere(
			player_posistion, 700, signpost.GetTransform().position, 1))
			continue;

		signpost.Draw();
	}
}