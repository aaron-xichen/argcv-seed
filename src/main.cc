// Copyright 2014 Yu Jing<yujing5b5d@gmail.com>
#include <cstdio>

#include <syslog.h> // syslog

#include <vector>
#include <string>

#include "argcv/argcv.hh"
#include "argcv/alg/alg.hh"
#include "argcv/ml/corpus/corpus.hh"
#include "argcv/ml/corpus/ds.hh"
#include "argcv/net/co_lacus.hh"
#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/string/hash.hh"
#include "argcv/string/uuid.hh"
#include "argcv/sys/daemon.h"
#include "argcv/timer/timer.hh"

using argcv::argcv_info;

using argcv::string::blz_hasher;

using argcv::ml::corpus::tf_idf;
using argcv::ml::corpus::dataset_d;

using namespace argcv::string;

using namespace argcv::net;

int main(int argc, char* argv[]) {
    //argcv::timer::timer t;
    //printf("argcv_seed .... \n");
    //printf("up to : %f ms\n", t.all());
    memcpy(proj_work_dir,"/tmp",5);
    daemon_init("argcv_seed");
    syslog(LOG_INFO,"hello .. said by argcv_seed ... \n");
    daemon_destroy();
    return 0;
}
