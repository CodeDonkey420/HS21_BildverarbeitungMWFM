#pragma once
#include "image-io.h"

typedef struct Pixel {
  int x;
  int y;
  struct Pixel *next;
} pixel_l;


extern void reset_matrix(unsigned char in[MAXXDIM][MAXYDIM]);
extern int count_pixels(unsigned char input[MAXXDIM][MAXYDIM]);
extern int grassfire_step(int x, int y, unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]);
extern void matrix_xor(unsigned char in1[MAXXDIM][MAXYDIM], unsigned char in2[MAXXDIM][MAXYDIM]);
extern void histogram(int h_e[256], unsigned char in[MAXXDIM][MAXYDIM]);
extern void normalize_h(int h_e[256]);
extern void visualize_h (int h_e[256], unsigned char out[MAXXDIM][MAXYDIM]);
extern void line_profile (int row, int h_e[256], unsigned char in[MAXXDIM][MAXYDIM],  unsigned char out[MAXXDIM][MAXYDIM], bool column);
extern pixel_l* get_gwordered_pixels(unsigned char in[MAXXDIM][MAXYDIM]);

