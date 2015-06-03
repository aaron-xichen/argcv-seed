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
#include "argcv/ir/index/analyzer/util.hh"
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
#include "argcv/thread/th_lacus.hh"

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

using namespace argcv::thread;

void data_printer(int* v) {
    printf("[start] : %d \n", *v);
    // usleep(1000000);
    printf("[ end ] : %d \n", *v);
}

int main(int argc, char* argv[]) {
    thread_lacus<int> thlacus(data_printer);
    int vals[100];
    for (int v = 0; v < 100; v++) {
        vals[v] = v;
        thlacus.add_task(&vals[v]);
    }
    thlacus.join();
    return 0;
}
