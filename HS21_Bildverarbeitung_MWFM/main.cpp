#include <stdio.h>
#include "image-io.h"
#include "operarations.h"
#include "utils.h"
#include "menu.h"

void main() {
	int chosen_option;
	unsigned char image[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char out[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char mask[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char temp[MAXXDIM][MAXYDIM];
	int _result;
	int count;
	int has_file = 0;
	int h_e[256];

	reset_matrix(out);

	do {
		chosen_option = menu();

		switch (chosen_option) {
			case readImage:
				_result = readImage_ppm(image); //Bild auswählen und in den Buffer laden

				if (_result == 0) {
					printf("Bild erfolgreich eingelesen.\n");
					has_file = 1;
				}

				else {
					printf("Fehler beim einlesen");
				}

				break;

			case copyImage:
				printf("Welches Bild ist zu kopieren? \n");
				readImage_ppm(image);
				printf("Neuer Dateiname:\n");
				_result = writeImage_ppm(image, MAXXDIM, MAXYDIM);
				break;

			case viewImage:
				viewImage_ppm();
				break;

			case dilateImage:
				if (!has_file) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else {
					dilate(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}
				break;

			case erodeImage:
				if (!has_file) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					erode(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}				
				break;

			case countPixels: //Pixel zählen
				readImage_ppm(image);
				count = count_pixels(image);
				printf("Anzahl der Pixel: %d\n", count);
				break;

			case openOp: //Open Function
				if (!has_file) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					open_operation(image);
				}
				break;

			case closeOp:
				if (!has_file) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					close_operation(image);
				}
				break;

			case grassFire:
				count = grassfire(image, mask);
				printf("Es gibt %d Objekte\n", count);
						break;

			case histogramCase:
				histogram(h_e, image);
				normalize_h(h_e);
				visualize_h(h_e, out);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			case lineDiag:
				line_profile(125, h_e, image, out, 1);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			case scaleHistOpt:
				lin_gwscale(5, 250, image, out);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			case flattenOpt:
				printf("Wie viele Buckets sollen entstehen");
				scanf("%d", &count);
				
				balance_hist(count, image, out);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			case sovol:
				_result = readImage_ppm(image); //Bild auswählen und in den Buffer laden

				if (_result == 0) {
					printf("Bild erfolgreich eingelesen.\n");
					has_file = 1;
				}

				else {
					printf("Fehler beim einlesen");
				}

				sovol_edges(image, out);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			case laplace:
				_result = readImage_ppm(image); //Bild auswählen und in den Buffer laden

				if (_result == 0) {
					printf("Bild erfolgreich eingelesen.\n");
					has_file = 1;
				}

				else {
					printf("Fehler beim einlesen");
				}

				laplace_edges(image, out);
				_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				break;

			default:
				break;
		}

	} while (chosen_option != quit);
}
