#include <stdio.h>

int menu() {
	int i;
	printf("--------------Menu---------------\n");
	printf("1. Bild einlesen\n");
	printf("2. Kopie erstellen\n");
	printf("3. Orginalbild anzeigen lassen\n");
	printf("4. Dilate\n");
	printf("5. Erosion\n");
	printf("6. Pixel zaehlen\n");
	printf("7. Oeffnen\n");
	printf("8. Schliessen\n");
	printf("9. Grassfire\n");
	printf("10. Hist\n");
	printf("11. LineDiag\n");
	printf("12. Lineare GW skalierung\n");
	printf("13. Histogramm ebnen\n");
	printf("0. Ende\n");
	printf("Wahl : ");
	scanf("%i", &i);
	getchar();
	return i;
}
