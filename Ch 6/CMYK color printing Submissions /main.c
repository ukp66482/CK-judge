#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            image[i][j] = mask[i][j]<<24;
        }
    }
}
void print_M(unsigned int mask[][MAX_SIZE]){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            mask[i][j] = mask[i][j]<<16;
            image[i][j] = (mask[i][j]|image[i][j]);
        }
    }
}
void print_Y(unsigned int mask[][MAX_SIZE]){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            mask[i][j] = mask[i][j]<<8;
            image[i][j] = (mask[i][j]|image[i][j]);
        }
    }
}
void print_K(unsigned int mask[][MAX_SIZE]){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            image[i][j] = (mask[i][j]|image[i][j]);
        }
    }
}
void CMYK_to_RGB(){
    unsigned int C,M,Y,K;
    unsigned int R,G,B;
    for(int i=0;i<H;i++) {
        for (int j = 0; j < W; j++) {
            C = image[i][j]>>24;
            M = (image[i][j]&0x00ff0000)>>16;
            Y = (image[i][j]&0x0000ff00)>>8;
            K = (image[i][j]&0x000000ff);
            R = lround(255*(100-C)/100.0*(100-K)/100.0);
            G = lround(255*(100-M)/100.0*(100-K)/100.0);
            B = lround(255*(100-Y)/100.0*(100-K)/100.0);
            image[i][j] = R;
            image[i][j] = (image[i][j]<<8|G);
            image[i][j] = (image[i][j]<<8|B);
        }
    }
}

int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
