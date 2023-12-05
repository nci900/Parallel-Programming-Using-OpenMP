#!/usr/bin/env bash
#PBS -N mytestRun
#PBS -l walltime=00:05:00
#PBS -q normal
#PBS -P vp91
#PBS -l ncpus=48
#PBS -l mem=192GB

echo $HOSTNAME
echo $USER
