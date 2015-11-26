/******************************
* AUTHOR : GUSTAVO MARTINS
* USE AS YOU WISH
* DATE : 11/25/2015
* LANG : ANSI C
* DESCR : A VERY SIMPLE
* 3D VECTOR LIBRARY
******************************/

#include <stdlib.h>
#include <math.h>
#include "TVector.h"

struct SVector {
	double x;
	double y;
	double z;
};

TVector createVector(double x, double y, double z) {
	TVector vec = (TVector)malloc(sizeof(struct SVector));

	if (vec == NULL)
		return NULL;

	vec->x = x;
	vec->y = y;
	vec->z = z;

	return vec;
}
TVector createNullVector() {
	return createVector(0, 0, 0);
}
void freeVector(TVector vec) {
	free(vec);
}

double getX(TVector vec) {
	return vec->x;
}
double getY(TVector vec) {
	return vec->y;
}
double getZ(TVector vec) {
	return vec->z;
}

void setX(TVector vec, double x) {
	vec->x = x;
}
void setY(TVector vec, double y) {
	vec->y = y;
}
void setZ(TVector vec, double z) {
	vec->y = z;
}

double getLength(TVector vec) {
	return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}
void normalizeVector(TVector vec) {
	double length = getLength(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

TVector doScalarProduct(TVector vec, double scalar) {
	TVector nvec = createVector(vec->x * scalar, vec->y * scalar, vec->z * scalar);
	return nvec;
}
double doDotProduct(TVector vecA, TVector vecB, double angle) {
	double lenA, lenB, cosAngle;

	lenA = getLength(vecA);
	lenB = getLength(vecB);
	cosAngle = cos(angle);

	return lenA * lenB * cosAngle;
}
TVector doCrossProduct(TVector vecA, TVector vecB) {
	TVector vec = createVector(0, 0, 0);
	double x, y, z;

	if (vec == NULL)
		return NULL;

	x = vecA->y * vecB->z - vecA->z * vecB->y;
	y = vecA->x * vecB->z - vecA->z * vecB->x;
	z = vecA->x * vecB->y - vecA->y * vecB->x;

	vec->x = x;
	vec->y = y;
	vec->z = z;

	return vec;
}
TVector doSum(TVector vecA, TVector vecB) {
	TVector vec = createVector(vecA->x + vecB->x,
		vecA->y + vecB->y,
		vecA->z + vecB->z);
	return vec;
}
TVector doSub(TVector vecA, TVector vecB) {
	TVector vec = createVector(vecA->x - vecB->x,
		vecA->y - vecB->y,
		vecA->z - vecB->z);
	return vec;
}

TVector doNormalize(TVector vec) {
	TVector copy = createCopyVector(vec);

	if (copy == NULL)
		return NULL;

	normalizeVector(copy);
	return copy;
}

TVector createCopyVector(TVector vec) {
	TVector copy = createVector(vec->x, vec->y, vec->z);
	return copy;
}