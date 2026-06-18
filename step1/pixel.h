#ifndef PIXELS
#define PIXELS

class Pixel{
    private:
    unsigned int Red;
    unsigned int Green;
    unsigned int Blue;

    public:
    Pixel ();
    Pixel (unsigned int r, unsigned int g, unsigned int b);

    
    unsigned int getRed ();
    
    unsigned int getBlue();

    unsigned int getGreen();

    void changeRed(unsigned int newR);
    
    void changeBlue(unsigned int newB);

    void changeGreen(unsigned int newG); 

};

#endif