// Copyright 2014 Yu Jing<yujing5b5d@gmail.com>
#include <cstdio>

#include <syslog.h>  // syslog

#include <vector>
#include <string>

#include "argcv/argcv.hh"
#include "argcv/alg/alg.hh"
#include "argcv/ir/ir.hh"
#include "argcv/ml/ml.hh"
#include "argcv/ml/perceptron.hh"
#include "argcv/net/co_lacus.hh"
#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/string/hash.hh"
#include "argcv/string/uuid.hh"
#include "argcv/sys/daemon.h"
#include "argcv/timer/timer.hh"

using argcv::argcv_info;

using argcv::string::blz_hasher;

using argcv::ir::tf_idf;
using argcv::ml::dataset_d;

using namespace argcv::string;

using namespace argcv::net;
using namespace argcv::ml;

int main(int argc, char* argv[]) {
    perceptron mml(10);
    mml.learn();
    std::vector<double> x1 = {0, 0, 1};
    std::vector<double> x2 = {1, 0, 0};
    std::vector<double> x3 = {0, 1, 1};
    std::vector<double> x4 = {1, 1, 0};
    mml.add(x1, 0);
    mml.add(x2, 0);
    mml.add(x3, 1);
    mml.add(x4, 1);
    mml.learn();
    printf("predict: %d \n", mml.predict(x3));
    return 0;
}
