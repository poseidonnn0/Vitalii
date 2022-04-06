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
#include <iostream>
#include <fstream>

namespace image
{
#pragma pack(1) // Отключить выравнивание
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
    ~BMP();

    void Read(const std::string &nameFile);
    void Write(const std::string &nameFile);

    void BlueFilter(); // Изменяет всё изображение к синему оттенку
    void YellowFilter(); // Изменяет оттенки белого цвета на жёлтые

private:
    BMPHEADER bmpHeader;
    BMPINFO bmpInfo;
    BMPHEADER bmpHeaderNew;
    BMPINFO bmpInfoNew;
    Pixel** pixels;
};

}
#endif
