#define DIMENSIONS 4
#define POINT_X 0
#define POINT_Y 1
#define POINT_Z 2
#define POINT_MYSTERY 3

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

struct eMatrix{
  short size;
  short p;
  double** data;
};

struct eMatrix* createMatrix(short size);
void freeMatrix(struct eMatrix* m);
void addPoint(struct eMatrix* m, double x, double y, double z);
void addPair(struct eMatrix* m, double x1, double y1, double z1, double x2, double y2, double z2);
void setPoint(struct eMatrix* m, short pos, double x, double y, double z);
void setVal(struct eMatrix* m, short pos, short row, double val);
void rmPoint(struct eMatrix* m, short pos);
void popPoint(struct eMatrix* m);

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void drawLinePoint(struct pic* p, struct point p1, struct point p2, struct color c);
struct color makeColor(unsigned char r, unsigned char g, unsigned char b);
void writePic(struct pic* p, char* fileName, int width, int height);
