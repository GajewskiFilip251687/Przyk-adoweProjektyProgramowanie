# -*- coding: utf-8 -*-
"""ProjectDominik.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1G1m_duBLO1EmXOXSKx7aGiQmR0slrJwe
"""

import numpy as np
import matplotlib.pyplot as plt

# Definicja funkcji x(t) i y(t)
def x(t):
    return np.cos(t)

def y(t):
    return np.sin(t) * t ** 3

# Pochodne funkcji x(t) i y(t)
def dx_dt(t):
    return -np.sin(t)

def dy_dt(t):
    return 3 * t * 2 * np.sin(t) + np.cos(t) * t * 3

# Funkcje podcałkowe dla długości i pola powierzchni
def integrand_length(t):
    return np.sqrt(dx_dt(t) ** 2 + dy_dt(t) ** 2)

def integrand_area(t):
    return x(t) * dy_dt(t)

# Implementacja metody Simpsona z oszacowaniem błędu
def simpson(f, a, b, n):
#"""
#    h = (b - a) / 2*n
#    x = np.linspace(a, b, 2*n + 1)
#    fx = f(x)
#    result = fx[0] + fx[-1] + 4 * np.sum(fx[1:2*n:2]) + 2 * np.sum(fx[2:2*n-1:2])
#    simpson_integral = (h / 3) * result
#"""
    result = (b-a)/6*n

    sum =

    # Estymacja błędu
    d4f = fourth_derivative_length(f, x, h)
    max_d4f = np.max(np.abs(d4f))
    error_estimate = ((b - a) * h**4) / 180 * max_d4f

    b-a/6n (f(x0) + 2SUM f(x2j) +4 SUM f(x2j-1) +f(x2n))

    result *= sum

    return simpson_integral, error_estimate

# Długość krzywej
def dlugosc_krzywej(a, b, n):
    return simpson(integrand_length, a, b, n)

# Pole powierzchni
def pole_powierzchni(a, b, n):
    return np.abs(simpson(integrand_area, a, b, n))

# Przybliżenie czwartej pochodnej integrand_length
def fourth_derivative_length(f, x, h):
    n = len(x)
    d4f = np.zeros(n)
    for i in range(2, n-2):
        d4f[i] = (f(x[i-2]) - 4*f(x[i-1]) + 6*f(x[i]) - 4*f(x[i+1]) + f(x[i+2])) / h**4
    return d4f


# Parametry
left = 0
right = 2 * np.pi
N = 500

# Obliczenia
dlugosc, blad_dlugosci = dlugosc_krzywej(left, right, N)
pole, blad_pola = pole_powierzchni(left, right, N)

# Wyniki
print(f"Przybliżona długość krzywej C: {dlugosc}")
print(f"Przybliżona wartość pola powierzchni D: {pole}")
print(f"Przybliżone oszacowanie błędu dla pola powierzchni: {blad_pola}")

# Wykres
t = np.linspace(left, right, N)
x_vals = x(t)
y_vals = y(t)/max(abs(y(t)))

plt.plot(x_vals, y_vals, label='Krzywa C')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Wykres krzywej C w kartezjańskim układzie współrzędnych')
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()