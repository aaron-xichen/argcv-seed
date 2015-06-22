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
#include "argcv/ml/svm.hh"  //
#include "argcv/net/tcp_listen.hh"
#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/string/hash.hh"
#include "argcv/string/uuid.hh"
#include "argcv/sys/daemon.h"
#include "argcv/timer/timer.hh"
#include "argcv/thread/threads.hh"

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



void cop(){
    int test_count = 10000000;
    int max_v = -1;
    double max_s = -1;
    for (int v = 7; v < 50; v++) {
        int* x = new int[v];
        int count = 0;
        for (int i = 0; i < test_count; i++) {
            memset(x,0,v * sizeof(int));
            int v2 = 0;
            int v1 = 0;
            for (int l = 0; l < 10; l++) x[random_int() % v]++;
            for(int iv = 0 ; iv < v ; iv  ++) {
                if(x[iv] == 2) v2 ++;
                if(x[iv] == 1) v1 ++;
            }
            if(v2 == 3 && v1 == 4) count ++;
        }
        delete[] x;
        double score = (double)count / test_count;
        if(score > max_s) {
            max_v = v;
            max_s = score;
        }
        printf("v: %d s: %f -- max : v: %d , s: %f\n",v,score,max_v,max_s);
    }

}


int main(int argc, char* argv[]) {
    std::vector<std::string> elems = utf8split("abcd\u00A0你好世界123\n");
    for(size_t i =  0 ; i < elems.size(); i ++ ) {
        printf("%zu [%s]:%lu\n",i,elems[i].c_str(),elems[i].length());
    }
    return 0;
}
