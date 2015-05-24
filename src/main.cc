// Copyright 2014 Yu Jing<yujing5b5d@gmail.com>
#include <cstdio>

#include <syslog.h>  // syslog

#include <vector>
#include <string>

#include <map>
#include <set>

#include "argcv/argcv.hh"
#include "argcv/alg/alg.hh"
#include "argcv/ir/ir.hh"
#include "argcv/ir/index/index.hh"
#include "argcv/ir/index/analyzer/basic_analyzer.hh"
#include "argcv/ir/index/analyzer/basic_tokenlizer.hh"
#include "argcv/ml/ml.hh"
#include "argcv/ml/perceptron.hh"
#include "argcv/ml/aprf.hh"
#include "argcv/ml/naive_bayes.hh"  //
#include "argcv/net/co_lacus.hh"
#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/string/hash.hh"
#include "argcv/string/uuid.hh"
#include "argcv/sys/daemon.h"
#include "argcv/timer/timer.hh"

#include "argcv/wrapper/leveldb_wr.hh"

using argcv::argcv_info;

using argcv::string::blz_hasher;

using argcv::ir::tf_idf;
using argcv::ml::dataset_d;

using namespace argcv::string;

using namespace argcv::random;
using namespace argcv::net;
using namespace argcv::ml;

using namespace std;

using namespace argcv::wrapper::leveldb;

using namespace argcv::ir::index::analyzer;


int main(int argc, char* argv[]) {
    for(int i = 0 ; i < 10 ; i ++ ) {
        printf("next ...\n");
        fflush(NULL);
        //usleep(1000000);
    }
    echo_server();
    return 0;
}
