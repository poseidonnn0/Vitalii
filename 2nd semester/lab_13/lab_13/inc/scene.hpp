#ifndef __SCENE_H__
#define __SCENE_H__
#include <SFML/Graphics.hpp>
#include <camera.hpp>
#include <fstream>

namespace VK
{
	class Scene
	{
	public:
		Scene(int width, int height);
		~Scene();
		void LifeCycle();

	private:
		std::unique_ptr<Camera> m_camera;

		int m_width;
		int m_height;

		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;

		Point* m_points = nullptr;
		int m_size = 0;
	};
}
#endif