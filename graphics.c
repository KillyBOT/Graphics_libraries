#include "kGraphics.h"

#ifndef STDIO_H
#include <stdio.h>
#endif

struct color makeColor(unsigned char r, unsigned char g, unsigned char b){
  struct color c;

  c.r = r;
  c.g = g;
  c.b = b;

  return c;
}

void writePic(struct pic* p, char* fileName, int width, int height){

  struct color pixel;

  FILE* f = fopen(fileName, "w+");

  fprintf(f, "P3 %d %d 255 ", width, height);
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      pixel = p->data[y][x];
      if(pixel.r > 0 || pixel.g > 0 || pixel.b > 0){
        fprintf(f, "%d %d %d ",pixel.r,pixel.g, pixel.b);
      } else {
        fprintf(f, "0 0 0 ");
      }
    }
  }

  fclose(f);
}
