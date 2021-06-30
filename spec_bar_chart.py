import numpy as np
import matplotlib.pyplot as plt

yvis_a = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_b = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_c = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_d = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis_e = np.array([1.2, 0.8, 2.5, 4.1, 2.2, 3.1])
yvis = (yvis_a + yvis_b + yvis_c + yvis_d + yvis_e) / 5

ynir_a = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_b = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_c = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_d = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir_e = np.array([1.4, 4.0, 2.8, 2.7, 3.9, 17.0])
ynir = (ynir_a + ynir_b + ynir_c + ynir_d + ynir_e) / 5

reflectance = np.concatenate((yvis,ynir))
reflectance[5],reflectance[6]=reflectance[6],reflectance[5]

wavelengths = np.array([450,500,550,570,600,610,650,680,730,760,810,860])
x_pos = np.arange(len(wavelengths))

plt.bar(x_pos,reflectance,
        color=['darkviolet','blue','green','yellow',
               'orange','crimson','red','firebrick',
               'maroon','lightgray','darkgray','gray'],
        edgecolor='black')

plt.xticks(x_pos,wavelengths)
plt.axis([None,None,0,30])

plt.title("Maple Leaf Spectrum")
plt.ylabel("Reflectance")
plt.xlabel("Wavelength (nm)")

plt.show()