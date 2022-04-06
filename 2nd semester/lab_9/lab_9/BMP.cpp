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


	void BMP::Read(const std::string &nameFile)
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

        pixels = new Pixel *[bmpInfo.Height];
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

    void BMP::Write(const std::string &nameFile)
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
}