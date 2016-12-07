#pragma once
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/app/App.h"
#include <map>


class TextureManager
{
private:

	std::map<std::string, ci::gl::Texture> textures;

public:

	TextureManager();
	~TextureManager();

	static TextureManager& Get()
	{
		static TextureManager texture_manager;
		
		return texture_manager;
	}

	void Setup();

	void Register(const std::string &path);
	/*void Register(const std::string &path,
		const ci::gl::Texture::Format &format,
		const std::string &name);*/
	ci::gl::Texture GetTexture(const std::string &name);
	const ci::Vec2f& GetSize(const std::string &name);

	void Delete(const std::string &name);
	void AllDelete();
};