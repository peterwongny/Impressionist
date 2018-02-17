// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image
	int		swapImage();

	int     clearCanvas();                  // called by the UI to clear the drawing canvas
	void	setBrushType(int type);			// called by the UI to set the brushType
	int		getSize();						// get the UI size
	void	setSize(int size);				// set the UI size
	int		getWidth();
	int		getAngle();
	int		getBrushDirection();
	float	getAlpha();
	void	setBrushDirection(int type);
	void	updateBrushDirection(const Point source, const Point target, bool start = false);
	void	setMovementDirection(const Point target, bool start = false);
	void	setGradientDirection(const Point source);

	void	autoPaint();

	char*	getImageName();					// get the current image name

	void	deleteFilterKernel();
	void	normalizeKernel();
	void	blurringKernel();
	void	sharpeningKernel();
	void	applyKernel(int row, int col, int** filter);
	

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting.
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;


	// The current active brush.
	ImpBrush*			m_pCurrentBrush;	
	// Size of the brush.
	int				m_nSize;					
	int				m_pCurrentBrushDirection;
	Point			previousPoint;
	float			movementAngle;
	float			gradientAngle;

	bool			colorPicked;
	GLubyte			Pickedcolor[3];
	float**			filterKernel;
	int				filterKernelRow;
	int				filterKernelCol;

	ImpressionistUI*	m_pUI;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );  


private:
	char			m_imageName[256];
};

extern void MessageBox(char *message);

#endif
