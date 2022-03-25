#!/bin/bash
#SBATCH --job-name="roms"

# %j=job_number and %N gives nodelist output="wec_real.%j.%N.out"
#SBATCH --output="expanse_test_log.%j.%N.run.out"
#SBATCH --partition=shared

# Can only use a max of 2 nodes on 'debug' partition:
#SBATCH --nodes=1

# Expanse has 128 cores per node:
#SBATCH --ntasks-per-node=6
#SBATCH --account=cla119
#SBATCH --export=ALL

# Max run time on 'debug' is 30 minutes:
#SBATCH -t 00:08:00

# Flags needed for mvapich2:
export MV2_USE_RDMA_CM=0
export MV2_IBA_HCA=mlx5_2
export MV2 DEFAULT PORT=1

module purge
module load slurm
module load cpu/0.15.4  intel/19.1.1.217  mvapich2/2.3.4
module load netcdf-c/4.7.4
module load netcdf-fortran/4.5.3

./do_test_all.sh expanse


