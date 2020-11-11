![Darknet Logo](http://pjreddie.com/media/files/darknet-black-small.png)

# Darknet #
Darknet is an open source neural network framework written in C and CUDA. It is fast, easy to install, and supports CPU and GPU computation.

## YOLOv4:

* **paper:** https://arxiv.org/abs/2004.10934

* **source code:** https://github.com/AlexeyAB/darknet

* **Wiki:** https://github.com/AlexeyAB/darknet/wiki

* **useful links:** https://medium.com/@alexeyab84/yolov4-the-most-accurate-real-time-neural-network-on-ms-coco-dataset-73adfd3602fe?source=friends_link&sk=6039748846bbcf1d960c3061542591d7

For more information see the [Darknet project website](http://pjreddie.com/darknet).

For questions or issues please use the [Google Group](https://groups.google.com/forum/#!forum/darknet).


![YOLOv4Tiny](https://user-images.githubusercontent.com/4096485/85734112-6e366700-b705-11ea-95d1-fcba0de76d72.png)

----

![YOLOv4](https://user-images.githubusercontent.com/4096485/90338826-06114c80-dff5-11ea-9ba2-8eb63a7409b3.png)


----

![OpenCV_TRT](https://user-images.githubusercontent.com/4096485/90338805-e5e18d80-dff4-11ea-8a68-5710956256ff.png)



On U250:
set FPGA=1 SOC=0 TF=0
On ZCU102:
set FPGA=1 SOC=1 TF=0

make libgen: to generate opencl library
make all: to generate host program
make runsim: generate emulation xclbin by merlin
make bitgen: generate on board xclbin by merlin
make run: to run for emulatoin

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
