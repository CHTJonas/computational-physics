#!/usr/bin/python3

import matplotlib
matplotlib.use('Agg')
import math
import numpy
import matplotlib.pyplot
import sys

# Total number of Monte Carlo steps
steps = 100
# The dimensions of the NxN lattice
N = 15
# Array of spin-up atoms
spins = numpy.empty(shape=(N,N))
for (x,y), value in numpy.ndenumerate(spins):
  spins[x,y] = 1.0
# The magnetic moment
mu = 1.0;
# The applied magnetic field
H = 0.0;
# J is the exchange energy
J = 1.0
# kB is the Boltzmann constant
kB = 1.0
# So we measure temperature in units of J/kB

def sweep( temp ):
  for (x,y), value in numpy.ndenumerate(spins):
    # Flip the spin and calculate the energy difference
    E1 = energy()
    spins[x,y] = -spins[x,y]
    E2 = energy()
    Edelta = E1 - E2

    if Edelta < 0:
      # Spin is already flipped
      spins[x,y] = spins[x,y]
    else:
      p = numpy.random.random()
      if prob(Edelta, temp) > p:
        # Spin is already flipped
        spins[x,y] = spins[x,y]
      else:
        # Flip the spin back
        spins[x,y] = -spins[x,y]
  return;

def energy():
  E = 0
  for (x,y), value in numpy.ndenumerate(spins):
    # Periodic boundary conditions
    # Imagine the lattice on a torus
    E -= J * ( spins[x-1,y]*spins[x,y] + spins[x,y-1]*spins[x,y] + spins[x,(y+1)%N]*spins[x,y] + spins[(x+1)%N,y]*spins[x,y] )
    E -= mu * H * spins[x,y]
  return E;

def magnetisation():
  M = 0.0
  for (x,y), value in numpy.ndenumerate(spins):
    M += float(spins[x,y])
  M = float(M) / float(N)
  return M;

def prob( deltaE, temp ):
  p = numpy.exp( -float(deltaE) / float(kB) / float(temp) )
  return p;

magnetisations = numpy.empty(shape=(steps))

temp = sys.argv[1]
for n in range(steps):
  magnetisations[n] = abs(magnetisation())
  sweep(float(temp))
matplotlib.pyplot.plot(magnetisations,label="Temp: " + temp)
matplotlib.pyplot.legend(loc='upper right')
matplotlib.pyplot.savefig("ising-model-" + temp + ".png", dpi=150, bbox_inches="tight")
