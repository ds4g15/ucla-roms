'''
Parameters for grid, initial and boundary conditions
'''
sim_name = 'Front1'
###########################
#Parameters
##########################
#Grid Paramters
dx = 100 #meters
dy = 100 #meters
Lx = 10000 
Ly = 600 
N = 128
theta_s = 6.
theta_b = 6.
hc = 10.

#Bathymetry Paramters
H = 250 #total tdepth

#below 3 don't matter for flat bottom
# but leave in in case want to do slope
s_h = 0 #bathymetric slope
Ld = 8e3 #length of flat shelf
hmin = 2. #minimum depth

#Other grid parameters
f0 = 7.81e-5 #coriolis parameters
grid_ang = 0. #grid rotation (default=0-->xi=east)


####################################
#Initial Condition Parameters
'''
version of idealized filament
from  McWilliams 2017 (JFM)
'''
####################################
#Density structure
#structure = 'front'
structure = 'fil'
#structure = None


#Choose initial velocity
# either TTW or geostrophic
flow = 'TTW'
#flow = 'geostrophic'
#flow=None


##########################
#buoyancy constant (ms^-2)
b0 = 6.4e-3 
#Fractional reduction of surface stratification relative to interior
B =0.025
#Vertical scale transition from surface to interior (m)
lambda_inv = 3 
#Background stratification (s^-2)
Nb =  1e-7
#interior stratification (s^-2)
N0 = 3.4e-5 

#half width of filament
L_fil = 750. 
#base surface boundary layer depth (m)
h0 = 60
#deviation of surface boundary layer at front or filament (m)
dh = 15


#Vertical Mixing Formulation
sig0 = 5e-3
K0 = 0.01
K_bak = 1e-6 #background diffusivity


#Constant Salinity
S0 = 32
