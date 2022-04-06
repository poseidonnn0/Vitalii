#include "BMP.hpp"

int main()
{
    image::BMP img;
    
    img.Read("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//lab_9//lab_9//Background.bmp");

    img.BlueFilter();

    img.Write("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//lab_9//lab_9//BlueImg.bmp");

    image::BMP img_2;

    img_2.Read("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//lab_9//lab_9//Background.bmp");

    img_2.YellowFilter();
  
    img_2.Write("C://Users//Vitaliy//OneDrive//Documents//Git//Repositories//Vitalii//2nd semester//lab_9//lab_9//YellowImg.bmp");
   
	return 0;
}
