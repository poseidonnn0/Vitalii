/*
* BMP library
*
* @created 06.04.2022 Vitaly Kondratev
*
*/
#include "BMP.hpp"

namespace image
{
	BMP::BMP()
	{

	}

	BMP::~BMP()
	{
		for (int i = 0; i < bmpInfo.Height; i++)
		{
			delete[] pixels[i];
		}
		delete[] pixels;
	}


	void BMP::Read(const std::string& nameFile)
	{
		std::ifstream in(nameFile, std::ios::binary);

		if (!(in.is_open()))
		{
			//throw std::exception("File not find!");
			std::cout << "File not find!";
			return;
		}

		in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));
		in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));

		pixels = new Pixel * [bmpInfo.Height];
		for (int i = 0; i < bmpInfo.Height; i++)
		{
			pixels[i] = new Pixel[bmpInfo.Width];
		}

		for (int i = 0; i < bmpInfo.Height; i++)
		{
			for (int j = 0; j < bmpInfo.Width; j++)
			{
				in.read(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
			}
			if ((3 * bmpInfo.Width) % 4 != 0)
			{
				for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++)
				{
					char c;
					in.read(&c, 1);
				}
			}
		}

	}

	void BMP::Write(const std::string& nameFile)
	{
		std::ofstream out(nameFile, std::ios::binary);

		int width = bmpInfo.Width;
		int height = bmpInfo.Height;

		bmpHeaderNew.Type = 0x4D42;
		bmpHeaderNew.Size = 14 + 40 + (3 * width * height);
		if (width % 4 != 0)
		{
			bmpHeaderNew.Size += (4 - (3 * width) % 4) * height;
		}
		bmpHeaderNew.OffBits = 54;
		bmpHeaderNew.Reserved1 = 0;
		bmpHeaderNew.Reserved2 = 0;

		out.write(reinterpret_cast<char*>(&bmpHeaderNew), sizeof(BMPHEADER));

		bmpInfoNew.BitCount = 24;
		bmpInfoNew.ClrImportant = 0;
		bmpInfoNew.ClrUsed = 0;
		bmpInfoNew.Compression = 0;
		bmpInfoNew.Height = height;
		bmpInfoNew.Planes = 1;
		bmpInfoNew.Size = 40;
		bmpInfoNew.SizeImage = bmpHeaderNew.Size - 54;
		bmpInfoNew.Width = width;
		bmpInfoNew.XPelsPerMeter = 0;
		bmpInfoNew.YPelsPerMeter = 0;

		out.write(reinterpret_cast<char*>(&bmpInfoNew), sizeof(BMPINFO));

		for (int i = 0; i < bmpInfoNew.Height; i++)
		{
			for (int j = 0; j < bmpInfoNew.Width; j++)
			{
				out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
			}

			if ((3 * bmpInfoNew.Width) % 4 != 0)
			{
				for (int j = 0; j < 4 - (3 * bmpInfoNew.Width) % 4; j++)
				{
					char c = 0;
					out.write(&c, 1);
				}
			}
		}
	}

	void BMP::BlueFilter()
	{
		for (int i = 0; i < bmpInfo.Height; i++)
		{
			for (int j = 0; j < bmpInfo.Width; j++)
			{
				if (pixels[i][j].b - 100 < 0)
				{
					pixels[i][j].b += 30;
				}
			}
		}
	}

	void BMP::YellowFilter()
	{
		// Фильтр оттенков белого цвета в жёлтый
		for (int i = 0; i < bmpInfo.Height; i++)
		{
			for (int j = 0; j < bmpInfo.Width; j++)
			{
				if (pixels[i][j].b > 210)
				{
					pixels[i][j].b = 0;
				}
				if (pixels[i][j].g > 210)
				{
					pixels[i][j].g = 255;
				}
				if (pixels[i][j].r > 210)
				{
					pixels[i][j].r = 255;
				}
			}
		}
	}


	void BMP::Encrypt()
	{
		std::ifstream pic("photo.bmp");
		std::ifstream txt("Text.txt");
		if (!pic.is_open() || !txt.is_open())
		{
			perror("Ошибка открытия файла");
			return;
		}

		while (getline(pic, stemp))
		{
			pstr += stemp;
			stemp.clear();
		}
		//std::cout << pstr << std::endl;
		while (getline(txt, stemp))
		{
			tstr += stemp;
			stemp.clear();
		}
		int pl = pstr.size();
		int tl = tstr.size();
		//std::cout << "\n==========\ntl=" << tl << "\n==================\n";

		if (tl > 100)
		{
			puts("Слишком много текста");
			printf("%d", tl);
			return;
		}
		if (tl == 0)
		{
			puts("Текста нет");
			return;
		}

		ty = (pl - py) / (tl * 8); // Расчетный интервал
		//srand(0);
		int tp = rand() % 256;
		pstr[6] = tl ^ tp;
		pstr[7] = tp;            // Записываем длину скрытой информации в зарезервированной области
		for (int i = py, j = 0; j != tl; ++j)          // Преобразуем скрытую информацию в биты и записываем их в последний бит интервала байтов.
		{
			std::bitset<8> bt(tstr[j]);
			for (int k = 0; k != 8; k++)
			{
				if (bt[8 - k - 1] == true) pstr[i] |= 1;
				else pstr[i] &= ~1;
				i += ty;
			}
		}

		Write("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//Additional_4//Additional_4//out.bmp");


		//std::ofstream out("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//Additional_4//Additional_4//out.bmp");
		pic.close();          // Закрываем файловый поток
		txt.close();
		//out.close();
	}

	void BMP::Decrypt()
	{
		std::ifstream pic("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//Additional_4//Additional_4//out.bmp");
		if (!pic.is_open())
		{
			perror("Ошибка открытия файла");
			return;
		}
		while (getline(pic, stemp))
	    {
			pstr1 += stemp;
			stemp.clear();
		}

		std::cout << pstr1 << std::endl;
		int pl = pstr1.size();
		std::cout << "\n==========\npl=" << pl << "\n==================\n";
		int tl = pstr1[6] ^ pstr1[7]; // Извлекаем длину скрытой информации из зарезервированной области
		std::cout << "\n==========\ntl=" << tl << "\n==================\n";
		//int ty = (pl - py) / (tl * 8);       // Расчетный интервал
		std::cout << "\n==========\nty=" << ty << "\n==================\n";

		char temp = 0;

		std::ofstream out("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//Additional_4//Additional_4//out.txt");

		for (int i = py, j = 0; j != tl; ++j)          // Преобразуем скрытую информацию в биты и записываем их в последний бит интервала байтов.
		{
			temp = 0;
			for (int k = 0; k != 8; k++)
			{
				temp <<= 1;
				temp += std::bitset<8>(pstr1[i])[0];
				i += ty;
			}
			out << temp;
		}

		pic.close();          // Закрываем файловый поток
		out.close();
	}



}