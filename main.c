/*
 Grupo 4
 Alexandre Braga Saldanha - 408484
 Helio Ossamu Nakayama - 408395
 Fernando Trevisan Donati - 489948
 Renan Lordello de Aguiar - 489867
 Renan Ferreira de Almeida - 489581
 */
#include "cglib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readLine(Line *l) {
	printf("p1(x,y): ");
	scanf("%f", &(l->p1.x));
	scanf("%f", &(l->p1.y));
	printf("p2(x,y): ");
	scanf("%f", &(l->p2.x));
	scanf("%f", &(l->p2.y));
}

int main() {
	ViewPort *vp;
	// Line line;
	int i, j;
	Point pMin, pMax;
	Universe u;
	ColorMap* cm;
	// printf("0 ^ 0 = %d\n", pow(0, 0));

	pMin.x = -20;
	pMin.y = -20;
	pMax.x = 10;
	pMax.y = 15;

	u.pMin = pMin;
	u.pMax = pMax;

	vp = createViewPort(newPoint(-8.0, -7.0), newPoint(5, 5), &u);
	if (vp == NULL) {
		printf("Erro de alocacao do veiwport\n");
		exit(0);
	}

	if (!allocateViewPortBuffer(vp, MAXIMOX, MAXIMOY)) {
		printf("Erro de alocacao do buffer do viewport\n");
		exit(0);
	}

	cm = createColorMap();
	if (cm == NULL) {
		printf("[ERRO] mapa de cores nao pode ser criado\n");
		exit(0);
	}

	if (!addColor(cm, 0, 255, 255, 255, 0)) {
		printf("[ERRO] cor '0' nao pode ser inserida no mapa de cores\n");
		exit(0);
	}

	if (!addColor(cm, 1, 0, 0, 0, 0)) {
		printf("[ERRO] cor '1' nao pode ser inserida no mapa de cores\n");
		exit(0);
	}

	if (!addColor(cm, 2, 255, 0, 0, 0)) {
		printf("[ERRO] cor '2' nao pode ser inserida no mapa de cores\n");
		exit(0);
	}

	if (!addColor(cm, 3, 0, 0, 255, 0)) {
		printf("[ERRO] cor '3' nao pode ser inserida no mapa de cores\n");
		exit(0);
	}


	int polylineCount = 2;
	Polyline polylines[polylineCount];

	polylines[0] = newRectangle(newPoint(-6, -6), newPoint(-1, -2));
	polylines[1] = newPolyline(5, true);
	polylines[1].points[0] = newPoint(-7.0,-3.0);
	polylines[1].points[1] = newPoint(-4.0,-4.0);
	polylines[1].points[2] = newPoint(-3.0,-6.0);
	polylines[1].points[3] = newPoint(-6.0,-9.0);
	polylines[1].points[4] = newPoint(-9.0,-8.0);


	for (j = 0; j < polylineCount; j++) {
		for (i = 0; i < polylines[j].pointCount; i++) {
			polylines[j].points[i] = sru2srn(polylines[j].points[i], vp->pMin, vp->pMax);
		}
		for (i = 0; i < polylines[j].pointCount; i++) {
			polylines[j].points[i] = srn2srd(polylines[j].points[i], MAXIMOX, MAXIMOY);
		}	
	}
	drawPolyLine(polylines[0], vp, 3);
	drawPolyLine(polylines[1], vp, 2);

	show(vp, cm);

	return 0;
}
