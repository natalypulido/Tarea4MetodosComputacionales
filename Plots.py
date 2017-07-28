import numpy as np
import matplotlib.pyplot as plt

data= np.loadtxt("map_data.txt")
res = np.loadtxt("resultados.txt")

fig = plt.gcf()
ax = fig.gca()
c = plt.Circle((res[1],res[0]), res[2], fill = False)
plt.scatter([res[1]],[res[0]], color = 'g')
ax.add_artist(c)
imgplot = plt.imshow(data)
plt.xlabel("Latitud")
plt.ylabel("Longitud")
fig.suptitle("Mapa Continentes", fontsize=20)
plt.savefig("PuntoNemo.pdf")
plt.close()
