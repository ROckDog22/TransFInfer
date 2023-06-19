//
// Created by fss on 23-4-25.
//

#include <glog/logging.h>
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging("Matrix test");
  FLAGS_log_dir = "./test_log";
  FLAGS_alsologtostderr = true;

  LOG(INFO) << "Start test...\n";
  return RUN_ALL_TESTS();
}