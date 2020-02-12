#include "kGraphics.h"

#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#endif

struct color makeColor(unsigned char r, unsigned char g, unsigned char b){
  struct color c;

  c.r = r;
  c.g = g;
  c.b = b;

  return c;
}

struct eMatrix* createMatrix(short size){
  struct eMatrix* m;

  m = malloc(sizeof(struct eMatrix));

  m->size = size;
  m->p = 0;
  m->data = calloc(sizeof(double), m->size);

  for(int x = 0; x < m->size; x++){
    m->data[x] = calloc(sizeof(double),DIMENSIONS);
  }

  return m;
}

void freeMatrix(struct eMatrix* m){
  for(int x = 0; x < m->size; x++){
    free(m->data[x]);
  }
  free(m->data);

  free(m);
}

void addPoint(struct eMatrix* m, double x, double y, double z){

  if(m->p < m->size){
    m->data[m->p][POINT_X] = x;
    m->data[m->p][POINT_Y] = y;
    m->data[m->p][POINT_Z] = z;
    m->data[m->p][POINT_MYSTERY] = 1;
    m->p++;
  }
}

void addPair(struct eMatrix* m, double x1, double y1, double z1, double x2, double y2, double z2);

void setPoint(struct eMatrix* m, short pos, double x, double y, double z){
  if(pos < m->size){
    m->data[pos][POINT_X] = x;
    m->data[pos][POINT_Y] = y;
    m->data[pos][POINT_Z] = z;
    m->data[pos][POINT_MYSTERY] = 1;
  }
}

void setVal(struct eMatrix* m, short pos, short row, double val){
  if(pos < m->size && row < DIMENSIONS){
    m->data[pos][row] = val;
  }
}

void rmPoint(struct eMatrix* m, short pos){
  if(pos < m->size){
    m->data[pos][POINT_X] = -1;
    m->data[pos][POINT_Y] = -1;
    m->data[pos][POINT_Z] = -1;
    m->data[pos][POINT_MYSTERY] = -1;
  }
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
