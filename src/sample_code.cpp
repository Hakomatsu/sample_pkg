#include <iostream>
#include <ros/ros.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
class SampleCode{
public:
  SampleCode();
  ~SampleCode();
  void LoadParams();
  void ShowImage();

private:
  string image_path_;

protected:
  ros::NodeHandle nh_;
};

SampleCode::SampleCode() :nh_(){
  cout << "SampleCode class was called." << endl;
  LoadParams();
}

SampleCode::~SampleCode(){
  cout << "SampleCode class was deleted." << endl;
}

void SampleCode::LoadParams(){
  XmlRpc::XmlRpcValue path_params;
  nh_.getParam("/sample_code/image_file", path_params);
  image_path_ = static_cast<string>(path_params["path"]);
  cout << image_path_ << endl;
  ShowImage();
}

void SampleCode::ShowImage(){
  cv::Mat image = cv::imread(image_path_);
  if(!image.empty()){
    cv::imshow("sample_image", image);
    cv::waitKey(0);
  }
  else{
    cout << "File not found" << endl;
  }
}

int main(int argc, char* argv[]){
  ros::init(argc, argv, "sample_code");
  SampleCode sc_;
  ros::spin();
  return 0;
}
