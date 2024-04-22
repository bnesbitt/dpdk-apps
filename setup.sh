#!/bin/bash

export RTE_TARGET=x86_64-native-linuxapp-gcc

# Load kernel drivers.
sudo modprobe uio
sudo sudo modprobe vfio-pci
modprobe vfio enable_unsafe_noiommu_mode=1
sudo modprobe vfio-pci
echo 1 | sudo tee -a /sys/module/vfio/parameters/enable_unsafe_noiommu_mode

# Use hugepages
sudo dpdk-hugepages.py -p 1G --setup 4G

# Disable the kernal managed NIC
sudo ifconfig ens256 down

dpdk-devbind.py -s
