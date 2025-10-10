#pragma once

enum MenuOpts {
	quit,
	readImage,
	copyImage,
	viewImage,
	dilateImage,
	erodeImage,
	countPixels,
	openOp,
	closeOp,
	grassFire,
  histogramCase,
  lineDiag,
  scaleHistOpt,
  flattenOpt,
	
} menuOpts;

extern int menu();
