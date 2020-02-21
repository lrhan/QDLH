# QDLH
 This is a demo of QDLH
We fork the repository from [Caffe](https://github.com/BVLC/caffe) and make our modifications. 
## Environment
* caffe
* python 2.7

## Data Preparation

You can download the data set and labels from [UCMerced-4](https://pan.baidu.com/s/1JpSDMr0isMpj-0ZRfsfLCw). The password is `ti2v`. The train label file and test label file is `train_label.txt` and `test_label.txt`, respectively.

After download the data set, you will change the data set path in label files. 

For example, the path in my train label file is `/home/lrh/dataset/UCdataset-4/agricultural00.jpg 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0` where `1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0` is `agricultural00.jpg`'s label, and you need to replace the path of the data set with your path `your path/UCdataset-4/agricultural00.jpg 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0`.
   
## Test the model
We take Res18-Q as an example.
You can download the pretrained Res18-Q model [here](https://pan.baidu.com/s/1BvHSAGNjAbesBTrl82Q2yw). The password is `oege`. You need to put the trained model `Res18UCMD32.caffemodel` in `./examples/res18-hwgq-3ne-clip-poly-320k/models/`. 

In `./examples/res18-hwgq-3ne-clip-poly-320k/predict/`, we give a test python file `predict_parallel.py` to show how to evaluate the trained QDLH model. You still need to change the path of the data set.

`python predict_parallel.py`
