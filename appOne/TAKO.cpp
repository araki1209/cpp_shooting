#include "TAKO.h"
#include"libOne.h"
void TAKO::setImage(int img){
	Img = img;
}
void TAKO::init(){
	Px = random() % (int)width;
	Py = random() % (int)height;
	Angle = 0;
}
void TAKO::move(){
	Angle += 0.01f;
}
void TAKO::draw(){
	image(Img, Px, Py, Angle);
}
