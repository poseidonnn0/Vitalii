/*
* BMP.hpp
* 
* BMP library
* 
* @created 06.04.2022 Vitaly Kondratev
* 
*/
#ifndef __BMP_H__
#define __BMP_H__
#include <string>
#include <fstream>
#include "Matrix.hpp"

using math::Vec2d;
using math::Mat22d;

namespace image
{

#pragma pack(1)
    struct Pixel
    {
        unsigned char b;
        unsigned char g;
        unsigned char r;
    };
#pragma pack()

    class BMP
    {
    public:
        BMP();
        BMP(int width, int height);
        BMP(const BMP& bmp);
        BMP& operator=(const BMP& bmp);
        ~BMP();
        void Fill(Pixel pixel);
        void Brightness();
        void Open(const std::string& filename);
        void Save(const std::string& filename);
        void Rotate(double angle);
        void inter();

    private:
        int m_width, m_height;
        Pixel** m_pixels = nullptr;
        Vec2d** m_coordinates = nullptr;

    private:
#pragma pack(1) //  
        struct BMPHEADER
        {
            unsigned short    Type;
            unsigned int      Size;
            unsigned short    Reserved1;
            unsigned short    Reserved2;
            unsigned int      OffBits;
        };
#pragma pack()

#pragma pack(1)
        struct BMPINFO
        {
            unsigned int    Size;
            int             Width;
            int             Height;
            unsigned short  Planes;
            unsigned short  BitCount;
            unsigned int    Compression;
            unsigned int    SizeImage;
            int             XPelsPerMeter;
            int             YPelsPerMeter;
            unsigned int    ClrUsed;
            unsigned int    ClrImportant;
        };
#pragma pack()
    };

}
#endif
