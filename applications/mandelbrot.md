# Finding Mandelbrot Set Using Monte Carlo Sampling

![](../figs/mandelbrot.png)

Mandelbrot set generates a list of complex numbers using the formulae

$z_{n} = z^{2}_{n-1} + c$ 

where

$z_{0} = c$ 

If the values of the complex numbers generated gets larger and larger then the choice of $c$ is not in the Mandelbrot set. To plot an image the points inside the Mandelbrot set is given a particular colour and all other points are given a different colour based on the iteration required to determine they are outside the Mandelbrot set.

In the Monte Carlo meothod, we generate psuedo random points in the complex plane, and then these points are tested if they are in the general Mandelbrot set or not. As can be imagined, for different $c$ the calculatiin required to determine whether $c$ is part of the Mandelbrot set is going to be different. We can use this properry of Mandelbrot set to demonstrate some features of OpenMP.