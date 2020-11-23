![Darknet Logo](http://pjreddie.com/media/files/darknet-black-small.png)

# Darknet #
Darknet is an open source neural network framework written in C and CUDA. It is fast, easy to install, and supports CPU and GPU computation.



On U250:
set FPGA=1 SOC=0 TF=0

On ZCU102:
set FPGA=1 SOC=1 TF=0

make libgen: to generate opencl library

make all: to generate host program

make runsim: generate emulation xclbin by merlin

make bitgen: generate on board xclbin by merlin

make run: to run for emulation

RUN Tensor Flow:

set FPGA=1 SOC=1 TF=0

conda info

conda create --name py37 python=3.7.9

conda activate py37

pip install tensorflow==1.15.2

pip install opencv-python

python python/tf_demo.py path --batch 5 --img_path /local/hanhu/darknet_yolo3_q/image_in --out_path /local/hanhu/darknet_yolo3_q/image_out

conda deactivate

Current performance:

1. U250: 109ms

2. ZCU: 170ms

Todo:
1. Support Double Pump DSP

2. Solve timing issue
