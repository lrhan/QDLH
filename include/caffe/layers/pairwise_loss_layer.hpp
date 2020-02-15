#ifndef CAFFE_PAIRWISE_LOSS_LAYER_HPP_
#define CAFFE_PAIRWISE_LOSS_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

#include "caffe/layers/loss_layer.hpp"

namespace caffe {

template <typename Dtype>
class PairwiseLossLayer : public LossLayer<Dtype> {
 public:
  explicit PairwiseLossLayer(const LayerParameter& param)
      : LossLayer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom, 
          const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
          const vector<Blob<Dtype>*>& top);
  
  virtual inline const char* type() const { return "PairwiseLoss"; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
  virtual inline int ExactNumBottomBlobs() const { return 4; }

protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  
  Blob<Dtype> product_;
  Blob<Dtype> loss_;
  Blob<Dtype> count_;
  Blob<Dtype> own_similarity_;
  int pairwise_axis_, outer_num_, inner_num_, label_dim_;
  Dtype l_threshold_, q_threshold_, l_lambda_, q_gamma_;
  Dtype class_num_;
  Dtype sigmoid_param_;
  bool continous_similarity_;
};

}  // namespace caffe

#endif  // CAFFE_PAIRWISE_LOSS_LAYER_HPP_
