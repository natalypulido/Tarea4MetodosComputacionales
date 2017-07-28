#Tarea4.mk

PuntoNemo.pdf: Plots.py
	python Plots.py
Resultados.txt: PuntoGeographic.x
	./PuntoGeographic.x
PuntoGeographic.x: PuntoGeographic.c
	cc PuntoGeographic.c -lm -o PuntoGeographic.x
PuntoGeographic.c: map_data.txt
	cc PuntoGeographic.c -lm -o PuntoGeographic.x
