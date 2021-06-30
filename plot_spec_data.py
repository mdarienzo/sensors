import numpy as np
import matplotlib.pyplot as plt

xvis = np.array([450, 500, 550, 570, 600, 650])
yvis_a = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_b = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_c = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_d = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_e = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis = (yvis_a + yvis_b + yvis_c + yvis_d + yvis_e) / 5

xnir = np.array([610, 680, 730, 760, 810, 860])
ynir_a = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_b = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_c = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_d = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_e = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir = (ynir_a + ynir_b + ynir_c + ynir_d + ynir_e) / 5

def pltcolor(lst):
    colorsvis=[]
    for l in lst:
        if l==450:
            colorsvis.append('darkviolet')
        elif l==500:
            colorsvis.append('blue')
        elif l==550:
            colorsvis.append('green')
        elif l==570:
            colorsvis.append('yellow')
        elif l==600:
            colorsvis.append('orange')
        elif l==650:
            colorsvis.append('red')
        else:
            colorsvis.append('black')
    return colorsvis
colorsvis=pltcolor(xvis)

def pltcolor(lst):
    colorsnir=[]
    for l in lst:
        if l==610:
            colorsnir.append('crimson')
        elif l==680:
            colorsnir.append('firebrick')
        elif l==730:
            colorsnir.append('maroon')
        elif l==760:
            colorsnir.append('lightgray')
        elif l==810:
            colorsnir.append('darkgray')
        elif l==860:
            colorsnir.append('gray')
        else:
            colorsnir.append('black')
    return colorsnir
colorsnir=pltcolor(xnir)

plt.ylim(0,30)
    
plt.scatter(x=xvis,y=yvis,c=colorsvis, zorder=4)
plt.scatter(x=xnir,y=ynir,c=colorsnir,zorder=3)

plt.plot(xvis,yvis,color='black',zorder=2)
plt.plot(xnir,ynir,color='black',zorder=1)

plt.title("Maple Leaf Spectrum")
plt.xlabel("Wavelength (nm)")
plt.ylabel("Reflectance")

plt.show()