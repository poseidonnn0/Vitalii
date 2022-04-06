#include "BMP.hpp"

int main()
{
    image::BMP img;
    
    img.Read("photo.bmp");

    img.Encrypt();

    img.Decrypt();

	return 0;
}
