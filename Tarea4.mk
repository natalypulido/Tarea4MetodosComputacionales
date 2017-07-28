#Tarea4.mk

PuntoNemo.pdf: Plots.py
	python Plots.py
resultados.txt: PuntoGeographicPoint.x
	./PuntoGeographicPoint.x
PuntoGeographicPoint.x: PuntoGeographicPoint.c
	cc PuntoGeographicPoint.c -lm -o PuntoGeographicPoint.x
PuntoGeographicPoint.c: map_data.txt
	cc PuntoGeographicPoint.c -lm -o PuntoGeographicPoint.x
