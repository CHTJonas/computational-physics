#!/usr/bin/python3

import matplotlib
matplotlib.use('Agg')
import math
import numpy
import matplotlib.pyplot

# Total number of Monte Carlo steps
steps = 100
# The dimensions of the NxN lattice
N = 25
# Array of random spins
spins = numpy.empty(shape=(N,N))
for (x,y), value in numpy.ndenumerate(spins):
  rand = numpy.random.random()
  if rand > 0.5:
    spins[x,y] = 1
  else:
# The exchange energy
J = 1.0
    spins[x,y] = -1
# The magnetic moment
mu = 2.0;
# The applied magnetic field
H = 0.0;
# Boltzmann Constant (J/K)
kB = 1.38064852 * 10**(-23)
# Temperature (K)
T = 273

def sweep( temp ):
  for (x,y), value in numpy.ndenumerate(spins):
    # Flip the spin and calculate the energy difference
    E1 = energy()
#    print("Initial energy: ", E1)
    spins[x,y] = -spins[x,y]
    E2 = energy()
#    print("Final energy: ", E2)
    Edelta = E1 - E2
#    print("Energy delta: ", Edelta)

    if Edelta < 0:
      # Spin is already flipped
      spins[x,y] = spins[x,y]
    else:
      p = numpy.random.random()
      if prob(Edelta) > p:
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

def prob(deltaE):
  p = numpy.exp( -deltaE / kB / T)
  return p;

energies = numpy.empty(shape=(steps))

for n in range(steps):
  energies[n] = energy()
  sweep()
matplotlib.pyplot.plot(energies,label="Energy")
matplotlib.pyplot.legend()
matplotlib.pyplot.savefig("ising-model.png", dpi=150, bbox_inches="tight")
