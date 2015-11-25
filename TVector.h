/******************************
* AUTHOR : GUSTAVO MARTINS
* USE AS YOU WISH
* DATE : 11/25/2015
* LANG : ANSI C
* DESCR : A VERY SIMPLE
* 3D VECTOR LIBRARY
******************************/

#ifndef TVECTOR_H
#define TVECTOR_H

typedef struct SVector *TVector;

TVector createVector(double x, double y, double z);
TVector createNullVector();
void freeVector(TVector vec);

double getX(TVector vec);
double getY(TVector vec);
double getZ(TVector vec);

void setX(TVector vec, double x);
void setY(TVector vec, double y);
void setZ(TVector vec, double z);

double getLength(TVector vec);
void normalizeVector(TVector vec);

TVector doDotProduct(TVector vec, double scalar);
TVector doCrossProduct(TVector vecA, TVector vecB);
TVector doNormalize(TVector vec);

TVector createCopyVector(TVector vec);

#endif