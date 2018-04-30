#!/usr/bin/python3

import matplotlib
matplotlib.use('Agg')
import math
import numpy as np
import matplotlib.pyplot as plt
import sys

# Total number of Monte Carlo steps
steps = 100
# The dimensions of the NxN lattice
N = int(sys.argv[2])
# Array of spin-up atoms
spins = np.empty(shape=(N,N))
for (x,y), value in np.ndenumerate(spins):
  spins[x,y] = 1.0
# The magnetic moment
mu = 1.0
# The applied magnetic field
H = float(sys.argv[3])
# J is the exchange energy
J = 1.0
# kB is the Boltzmann constant
kB = 1.0
# So we measure temperature in units of J/kB

def sweep( temp ):
  for (x,y), value in np.ndenumerate(spins):
    # Flip the spin and calculate the energy difference
    E1 = energy()
    spins[x,y] = -spins[x,y]
    E2 = energy()
    Edelta = E1 - E2

    if Edelta < 0:
      # Spin is already flipped
      spins[x,y] = spins[x,y]
    else:
      p = np.random.random()
      if prob(Edelta, temp) > p:
        # Spin is already flipped
        spins[x,y] = spins[x,y]
      else:
        # Flip the spin back so overall we do nothing
        spins[x,y] = -spins[x,y]
  return;

def energy():
  E = 0.0
  for (x,y), value in np.ndenumerate(spins):
    # Periodic boundary conditions
    # Imagine the lattice on a torus
    E -= float(J) * float( spins[x-1,y]*spins[x,y] + spins[x,y-1]*spins[x,y] + spins[x,(y+1)%N]*spins[x,y] + spins[(x+1)%N,y]*spins[x,y] )
    E -= float(mu) * float(H) * float(spins[x,y])
  return E;

def magnetisation():
  M = 0.0
  for (x,y), value in np.ndenumerate(spins):
    M += float(spins[x,y])
  M = float(M) / float(N)
  return M;

def prob( deltaE, temp ):
  p = np.exp( -float(deltaE) / float(kB) / float(temp) )
  return p;

energies = np.empty(shape=(steps))
magnetisations = np.empty(shape=(steps))
calcE = 0.0

temp = sys.argv[1]
for n in range(steps):
  energies[n] = energy()
  if n>=20:
    calcE += energies[n]
  magnetisations[n] = abs(magnetisation())
  sweep(float(temp))
calcE = calcE / (steps - 20)
print(str(H) + "," + str(calcE))

f, axarr = plt.subplots(2, sharex=True)
axarr[0].plot(energies, color="red")
axarr[0].set(xlabel="Monte Carlo Step", ylabel="Energy")
axarr[1].plot(magnetisations, color="blue")
axarr[1].set(xlabel="Monte Carlo Step", ylabel="Mean Magnetisation")
# Bring subplots close to each other.
f.subplots_adjust(hspace=0)
# Hide x labels and tick labels for all but bottom plot.
for ax in axarr:
    ax.label_outer()
f.tight_layout()
plt.savefig("ising-temp" + temp + "-N" + str(N) + "-H" + str(H) + ".png", dpi=150, bbox_inches="tight")
