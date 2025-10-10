#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "image-io.h"


extern void dilate(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
extern void erode(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
extern void open_operation(unsigned char in[MAXXDIM][MAXYDIM]);
extern void close_operation(unsigned char in[MAXXDIM][MAXYDIM]);
extern int grassfire(unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]);
extern void lin_gwscale(int a1, int ak, unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
extern void balance_hist (int bucket_size, unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
