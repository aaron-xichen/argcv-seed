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

bool key_value_printer(const std::string& k, const std::string& v, void* data) {
    int* _offset = (int*)data;
    printf("%d key: %s \t value: %s \n", (*_offset)++, k.c_str(), v.c_str());
    return true;  //(*_offset) < 2;
}

int main(int argc, char* argv[]) {
    const char* ddir = "leveldb.data";
    ldb_wrapper lw(ddir, 0, true);
    lw.conn();
    lw.put("a", "00");
    lw.put("a01", "01");
    lw.put("a02", "02");
    // lw.put("a03", "03");
    printf("destroy status : %d \n", ldb_wrapper::destroy(ddir));
    lw.put("a04", "04");
    lw.put("b01", "04");
    lw.put("b03", "05");
    printf("exist a? %d \n", lw.exist("a") ? 1 : 0);

    lw.rm("a02");
    int i = 0;
    lw.start_with("a", key_value_printer, &i);

    lw.close();
    printf("destroy status : %d \n", ldb_wrapper::destroy(ddir));

    printf("is closed ? %d \n", lw.is_closed() ? 1 : 0);

    return 0;
}
