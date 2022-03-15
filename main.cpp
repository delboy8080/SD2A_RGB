#include <iostream>
#include <string>
using namespace std;
struct Rgb
{
    float r, g, b;
    Rgb() : r(0), g(0), b(0) {} // default values (0,0,0)
    Rgb(float rr, float gg, float bb) : r(rr), g(gg), b(bb) {}
};
void display_pixel_channels(const Rgb &pixel,const string &name);
void filterRed(Rgb &pixel);
void whiteout_image(int width, int height, Rgb *image);
void blackout_image(int width, int height, Rgb *image);

void displayImagePixel(int width, const Rgb *image, int x, int y);

int main() {
    Rgb blackPixel;
    Rgb redPixel(1,0,0);
    Rgb greenPixel(0,1,0);
    Rgb bluePixel(0,0,1);
    Rgb pinkPixel(1,0.75,0.75);
    Rgb magentaPixel(1,0,1);
    Rgb greyPixel(0.5,0.5,0.5);

    display_pixel_channels(blackPixel, "Black");
    display_pixel_channels(redPixel, "Red");
    display_pixel_channels(greenPixel, "Green");
    display_pixel_channels(bluePixel, "Blue");
    display_pixel_channels(pinkPixel, "Pink");
    display_pixel_channels(magentaPixel, "Magenta");
    display_pixel_channels(greyPixel, "Grey");
    filterRed(greyPixel);
    display_pixel_channels(greyPixel, "Grey");

    int width = 200;
    int height = 100;
    Rgb *image = new Rgb[width*height];
    whiteout_image(width, height, image);
    displayImagePixel(width, image, 0, 0);
    displayImagePixel(width, image, 25, 99);
    blackout_image(width, height, image);
    displayImagePixel(width, image, 0, 0);
    displayImagePixel(width, image, 25, 99);
    return 0;
}

void displayImagePixel(int width, const Rgb *image, int x, int y) {

    Rgb pixel = image[(y*width)+x];

    display_pixel_channels(pixel, "("+to_string(x)+", " + to_string(y)+")");
}

void display_pixel_channels(const Rgb &pixel,const string &name)
{
    cout << name <<" (Red: " << pixel.r << "; Green:" << pixel.g <<"; Blue:"<<pixel.b
    <<")"<<endl;
}

void filterRed(Rgb &pixel)
{
    pixel.g = 0;
    pixel.b = 0;
}

void whiteout_image(int width, int height, Rgb *image)
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0;  c< width;c++)
        {
            image->r = 1;
            image->g = 1;
            image->b = 1;
            image++;
        }
    }
}

void blackout_image(int width, int height, Rgb *image)
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0;  c< width;c++)
        {
            image[r*width+c].r = 0;
            image[r*width+c].g = 0;
            image[r*width+c].b = 0;

        }
    }
}