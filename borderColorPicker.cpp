#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    borderSize = borderSize;
    fillColor = fillColor;
    img = img;
    tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{
    /**
     * Picks the color for pixel (x, y). If the x or y coordinate is a
     * multiple of the spacing, it will be filled with the fillColor.
     * otherwise, it will be filled with white.
     *
     * @param p   The point for which you're picking a color
     * @return    The color chosen for (p).
     */
    /* your code here */
    int px = p.x;
    int py = p.y;
    int xedge = px+borderSize;
    int yedge = py+borderSize;

    HSLAPixel *og = im.getPixel(px,py);
    for (int a = (px-borderSize); a <= xedge; a++){
        for (int b= (py-borderSize); b <= yedge; b++){
            int distancesqr = px*px + py*py;
            if (inimage(px, py, img.width(), img.height())) {
                return fillColor;
            }
        }
    }
    return *og;
}

bool borderColorPicker::inimage(int x, int y, int imgwidth, int imgheight) {
    return ( imgwidth > 0 && imgheight > 0 && x >= 0 && y >= 0 && y < imgheight);
}

bool borderColorPicker::infillregion(int x, int y) {
    HSLAPixel* pixelog = img.getPixel(x,y);
    double dist = pixelog->dist();
}