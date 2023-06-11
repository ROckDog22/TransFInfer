#include <gtest/gtest.h>
#include <glog/logging.h>
#include <armadillo>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging("TransFInfer");
    FLAGS_log_dir = "./log";
    FLAGS_alsologtostderr = true;
    LOG(INFO) << "Start test ... \n";
    return RUN_ALL_TESTS();
}