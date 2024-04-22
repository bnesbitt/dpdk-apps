# Setup

## Hugepages
Refer to: https://edc.intel.com/content/www/us/en/design/products/ethernet/config-guide-e810-dpdk/hugepages-setup/

Add the following to the grub config: `/etc/default/grub`

```shell
default_hugepagesz=1G hugepagesz=1G hugepages=4 iommu=on
```

and then:
```shell
grub2-mkconfig -o /boot/grub2/grub.cfg
```

## NICs

Disable the NICs using `ifconfig` so that they are free to be used by DPDK. For example:
```shell
sudo ifconfig ens161 down
sudo ifconfig ens256 down
```

After they have been released, DPDK will list them as other network devices:
```shell
$ dpdk-devbind.py -s

Network devices using kernel driver
===================================
0000:03:00.0 'VMXNET3 Ethernet Controller 07b0' if=ens160 drv=vmxnet3 unused=vfio-pci *Active*

Other Network devices
=====================
0000:04:00.0 'VMXNET3 Ethernet Controller 07b0' unused=vmxnet3,vfio-pci
0000:1b:00.0 'VMXNET3 Ethernet Controller 07b0' unused=vmxnet3,vfio-pci

```

Give them to DPDK:
```shell
$ dpdk-devbind.py -b vfio-pci 0000:04:00.0 0000:1b:00.0
```
Note that we used the one command to bind two devices using the *vfio-pci* driver.

DPDK will now report the following status:
```shell
$ dpdk-devbind.py -s

Network devices using DPDK-compatible driver
============================================
0000:04:00.0 'VMXNET3 Ethernet Controller 07b0' drv=vfio-pci unused=vmxnet3
0000:1b:00.0 'VMXNET3 Ethernet Controller 07b0' drv=vfio-pci unused=vmxnet3

Network devices using kernel driver
===================================
0000:03:00.0 'VMXNET3 Ethernet Controller 07b0' if=ens160 drv=vmxnet3 unused=vfio-pci *Active*
```
