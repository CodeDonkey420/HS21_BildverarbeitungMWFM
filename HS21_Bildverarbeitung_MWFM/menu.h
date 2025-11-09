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
  laplace,
  sovol,
	
} menuOpts;

extern int menu();
