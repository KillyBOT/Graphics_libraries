struct color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

struct pic{
  struct color data[2048][2048];
};

struct point{
  unsigned short x;
  unsigned short y;
};

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void drawLinePoint(struct pic* p, struct point p1, struct point p2, struct color c);
struct color makeColor(unsigned char r, unsigned char g, unsigned char b);
void writePic(struct pic* p, char* fileName, int width, int height);
