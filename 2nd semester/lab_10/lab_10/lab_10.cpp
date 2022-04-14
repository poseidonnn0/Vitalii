#include <BMP.hpp>

int main()
{
    try
    {
        image::BMP test_bmp(400, 150);
        //test_bmp.Fill({ 0,255,0 });
        test_bmp.Open("input.bmp");
        test_bmp.Rotate(acos(-1)/2);
        //test_bmp.inter(); // встроено в поворот
        test_bmp.Save("../out.bmp");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
