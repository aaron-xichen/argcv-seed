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
#include "argcv/ml/aprf.hh"
#include "argcv/ml/naive_bayes.hh" // 
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

using namespace argcv::random;
using namespace argcv::net;
using namespace argcv::ml;

using namespace std;

bool y(std::vector<double> x) {
    // printf("%f \n",x[0] * 0.2 + x[1] * 0.8 + x[2] * 0.3);
    return (x[0] * 0.1 * x[1] * 0.8 - x[2] * 0.3 - x[3] * 0.1 + x[4] * 0.2 + 0.2 > 0.5);
}

std::pair<std::vector<std::string>,std::string> get_pair(const std::string & x1,
                    const std::string & x2, const std::string & y) {
    std::vector<std::string> x = {x1,x2};
    return std::make_pair(x,y);
}

int main(int argc, char* argv[]) {
    naive_bayes nb;
    nb.add(get_pair("1","S","-1"));
    nb.add(get_pair("1","M","-1"));
    nb.add(get_pair("1","M","1"));
    nb.add(get_pair("1","S","1"));
    nb.add(get_pair("1","S","-1"));
    
    nb.add(get_pair("2","S","-1"));
    nb.add(get_pair("2","M","-1"));
    nb.add(get_pair("2","M","1"));
    nb.add(get_pair("2","L","1"));
    nb.add(get_pair("2","L","1"));
    
    nb.add(get_pair("3","L","1"));
    nb.add(get_pair("3","M","1"));
    nb.add(get_pair("3","M","1"));
    nb.add(get_pair("3","L","1"));
    nb.add(get_pair("3","L","-1"));

    nb.learn();

    return 0;
}
