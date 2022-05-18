#include <scene.hpp>
#include <vector>
#include <iomanip>

namespace VK
{
	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture);

		Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
		Point position = { 467310.0, -70.0, 6063480.0 };
		Angles angles = { 0.0,1.4,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);

		m_points = new Point[1000000];

		/*double r = 1;
		for (double fi = 0; fi < 6.28; fi += 0.01)
			for (double teta = 0; teta < 1.57; teta += 0.01)
			{
				m_points[m_size].x = r * sin(teta) * cos(fi);
				m_points[m_size].y = r * sin(teta) * sin(fi) + 5;
				m_points[m_size].z = r * cos(teta);
				m_size++;
			}*/
	}
	Scene::~Scene()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}

	void Scene::LifeCycle()
	{

		double y0 = 1;

		std::ifstream in("points.txt");

		if (!in.is_open()) {
			std::cerr << "File points.txt not found";
			return;
		}

		std::vector<double> mas;
		double num;


		while (!in.eof())
		{
			in >> num;
			mas.push_back(num);
		}
		std::cout << std::setprecision(3) << std::fixed; // Добавить цифры после запятой
		int k = 0;
		/*for (int i = 0; i < mas.size(); i++)
		{
			std::cout << mas[i] << " ";
			k++;
			if (k == 6)
			{
				std::cout << std::endl;
				k = 0;
			}
		}*/
		std::vector<double> X;
		std::vector<double> Y;
		std::vector<double> Z;
		std::vector<double> R;
		std::vector<double> G;
		std::vector<double> B;
		for (int i = 0; i < mas.size()-1; i++)
		{
			if (i % 6 == 0)
			{
				X.push_back(mas[i]);
			}
			if (i % 6 == 1)
			{
				Y.push_back(mas[i]);
			}
			if (i % 6 == 2)
			{
				Z.push_back(mas[i]);
			}
			if (i % 6 == 3)
			{
				R.push_back(mas[i]);
			}
			if (i % 6 == 4)
			{
				G.push_back(mas[i]);
			}
			if (i % 6 == 5)
			{
				B.push_back(mas[i]);
			}
		}

		/*std::cout << "X COORD \n\n\n";
		for (int i = 0; i < X.size(); i++)
		{
			std::cout << X[i] << " ";
		}
		std::cout << "\n\n\n\n Y COORD \n\n\n";
		for (int i = 0; i < Y.size(); i++)
		{
			std::cout << Y[i] << " ";
		}
		std::cout << "\n\n\n\n Z COORD \n\n\n";
		for (int i = 0; i < Z.size(); i++)
		{
			std::cout << Z[i] << " ";
		}
		std::cout << "\n\n\n\n R \n\n\n";
		for (int i = 0; i < R.size(); i++)
		{
			std::cout << R[i] << " ";
		}
		std::cout << "\n\n\n\n G \n\n\n";
		for (int i = 0; i < G.size(); i++)
		{
			std::cout << G[i] << " ";
		}
		std::cout << "\n\n\n\n B \n\n\n";
		for (int i = 0; i < B.size(); i++)
		{
			std::cout << B[i] << " ";
		}*/


		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				m_camera->dZ(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_camera->dZ(-1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_camera->dX(-1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_camera->dX(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_camera->dPitch(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_camera->dPitch(0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_camera->dRoll(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_camera->dRoll(0.02);
			}

			//y0 += 0.02;
			/*m_size = 0;
			double r = 1;
			for (double fi = 0; fi < 6.28; fi += 0.01)
				for (double teta = 0; teta < 1.57; teta += 0.01)
				{
					m_points[m_size].x = r * sin(teta) * cos(fi);
					m_points[m_size].y = r * sin(teta) * sin(fi) + y0;
					m_points[m_size].z = r * cos(teta);
					m_size++;
				}
				*/
			//  
			m_size = 0;
			int size_point = mas.size() / 6;
			//std::cout << "SIZE POINT = " << size_point;
			for (int i = 0; i < size_point; i++)
			{
				m_points[m_size].x = X.at(i);
				m_points[m_size].y = Y.at(i);
				m_points[m_size].z = Z.at(i);
				m_size++;
			}
			

			for (int i = 0; i < m_size; i++)
			{
				//m_camera->ProjectPoint(m_points[i], { 255, 0, 0, 255 });

				m_camera->ProjectPoint(m_points[i], { (uint8_t)R[i], (uint8_t)G[i] , (uint8_t)B[i], 255 });
			}
				
			m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}
	}
}
