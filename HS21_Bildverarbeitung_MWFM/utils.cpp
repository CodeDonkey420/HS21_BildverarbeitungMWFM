#include "utils.h"
#include <string.h>

pixel_l* get_gwordered_pixels(unsigned char in[MAXXDIM][MAXYDIM]) {
  pixel_l *slices[256];

  for (int i = 0; i < 256; i++) {
    slices[i] = NULL;
  }

	pixel_l *start = (pixel_l*) malloc(sizeof(pixel_l));
  start = NULL;

  for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
      int val = in[x][y];

			pixel_l *curr = (pixel_l*) malloc(sizeof(pixel_l));
      curr->x = x;
      curr->y = y;
      curr->next = NULL;

      if (slices[val] != NULL) {
        curr->next = slices[val];
        slices[val] = curr;
      }
      else{
        slices[val] = curr;
      }
		}
	}

  for (int i = 255; i >= 0; i--) {
    if (slices[i]) {
      pixel_l *end = slices[i];

      while (end->next) {
        end = end->next;
      }

      end->next = start;
      start = slices[i];
    }
  }

  return start;
}

void reset_matrix(unsigned char in[MAXXDIM][MAXYDIM]) {
	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			in[x][y] = 0;
		}
	}
}

int count_pixels(unsigned char input[MAXXDIM][MAXYDIM]) {
	int Zähler = 0; //Varaibale für das Zählen von nicht schwarzen Pixeln
	int x, y;

	for (x = 0; x < MAXXDIM; x++){
		for (y = 0; y < MAXYDIM; y++){
			Zähler += input[x][y] != 0;
		}

	}
	return Zähler;
}

int grassfire_step(int x, int y, unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]) {

  if (x != 0) {
    if (in[x-1][y] == 255 && mask[x-1][y] != 255) {
      mask[x-1][y] = 255;
      grassfire_step(x-1, y, in, mask);
    }
  }

  if (y != 0) {
    if (in[x][y-1] == 255 && mask[x][y-1] != 255) {
      mask[x][y-1] = 255;
      grassfire_step(x, y-1, in, mask);
    }
  }

  if (x != MAXXDIM - 1) {
    if (in[x+1][y] == 255 && mask[x+1][y] != 255) {
      mask[x+1][y] = 255;
      grassfire_step(x+1, y, in, mask);
    }
  }

  if (y != MAXYDIM - 1) {
    if (in[x][y+1] == 255 && mask[x][y+1] != 255) {
      mask[x][y+1] = 255;
      grassfire_step(x, y+1, in, mask);
    }
  }

  return 0;
}

void matrix_xor(unsigned char in1[MAXXDIM][MAXYDIM], unsigned char in2[MAXXDIM][MAXYDIM]) {
  unsigned char out[MAXXDIM][MAXYDIM];

	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			out[x][y] = ((in1[x][y] == 255) ^ (in2[x][y] == 255)) * 255;
		}
	}

  memcpy(in1, out, MAXXDIM * MAXYDIM);
}

void histogram(int h_e[256], unsigned char in[MAXXDIM][MAXYDIM]) {
  for (int i = 0; i < 256; i++) {
    h_e[i] = 0;
  }

	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			h_e[in[x][y]]++;
		}
	}
}

void normalize_h(int h_e[256]) {
  int max = 0;

  for (int i = 0; i < 256; i++) {
    if (h_e[i] > max) {
      max = h_e[i];
    }
  }

  for (int i = 0; i < 256; i++) {
    h_e[i] = (int) (h_e[i] * 255 / max);
  }
}

void visualize_h (int h_e[256], unsigned char out[MAXXDIM][MAXYDIM]) {
  reset_matrix(out);

  for (int i = 0; i < MAXXDIM; i++) {
    for (int h = 0; h < h_e[i]; h++) {
      out[255-h][i] = 255;
    }
  }
}

void line_profile (int row, int h_e[256], unsigned char in[MAXXDIM][MAXYDIM],  unsigned char out[MAXXDIM][MAXYDIM], bool column) {
  if (!column) {
    for (int i = 0; i < MAXXDIM; i++) {
      h_e[i] = in[row][i];
    }
  }
  else {
    for (int i = 0; i < MAXXDIM; i++) {
      h_e[i] = in[i][row];
    }
  }
  reset_matrix(out);

  for (int i = 0; i < MAXXDIM; i++) {
    out[h_e[i]][i] = 255;
  }
}

