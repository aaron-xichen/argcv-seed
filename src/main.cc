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


using namespace argcv::net;
void echo_server() {
    co_lacus pool(9527, 200000);
    size_t sz_min_sleep = 50000;
    size_t sz_max_sleep = 300000;
    size_t sz_sleep = sz_min_sleep;
    if (pool._error_no() != 0) {
        printf("pool establish failed .. %d \n", pool._error_no());
    } else {
        printf("pool established .. %d \n", pool._error_no());
        size_t loop = 0;
        for (;;) {
            int id = pool.poll(0);
            if (id != -1) {
                sz_sleep = sz_max_sleep;
                printf("#### id: %d\n", id);
                co_lacus::conn &c = pool[id];
                bool st = pool.pull(id, 1);
                if (st) {
                    // printf("data:[%s] %lu \n",c.to_str().c_str(), c.to_str().length());
                    std::string s = c.to_str();
                    for (size_t i = 0; i < c.to_str().length(); i++) {
                        printf("%lu %d %c\n", i, c.to_str()[i], c.to_str()[i]);
                    }
                    // sleep(3);
                    c.write(c.to_str(), c.to_str().length());
                } else {
                    if (c.closed()) {
                        printf("is closed .. \n");
                    } else {
                        printf("unknown error ? \n status : %hhu\n", c._status());
                    }
                }
                c.flush();
            } else{
                printf("sleep ...%lu\n",loop++);
                fflush(NULL);
                sz_sleep *= 2;
                if(sz_sleep > sz_max_sleep){
                    sz_sleep = sz_max_sleep;
                }
                usleep(sz_sleep);
            }
        }
    }
}


int main(int argc, char* argv[]) {
    for(int i = 0 ; i < 10 ; i ++ ) {
        printf("next ...\n");
        fflush(NULL);
        //usleep(1000000);
    }
    echo_server();
    return 0;
}
