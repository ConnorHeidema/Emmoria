#include "map/TextureContainer.hpp"

#include "util/logger/Logger.hpp"

TextureContainer::TextureContainer()
	: mk_type("TextureContainer")
{}

std::shared_ptr<sf::Texture> TextureContainer::GetTexture(std::string const& textureName)
{
	auto potentialTextureIter = m_textureMap.find(textureName);
	if (potentialTextureIter == m_textureMap.end())
	{
		auto pTexture = LoadTexture_(textureName);
		m_textureMap.insert(std::pair<std::string, std::shared_ptr<sf::Texture>>(textureName, pTexture));
		return pTexture;
	}
	return potentialTextureIter->second;
}

std::shared_ptr<sf::Texture> TextureContainer::LoadTexture_(std::string const& textureName)
{
	s_pLogger->DebugLog(mk_type, (std::string("Loading new texture: ") + textureName).c_str());
	auto pPotentialTexture = std::make_shared<sf::Texture>();
	pPotentialTexture->loadFromFile(textureName);
	return pPotentialTexture;
}
