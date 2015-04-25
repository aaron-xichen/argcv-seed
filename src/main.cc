// Copyright 2014 Yu Jing<yujing5b5d@gmail.com>
#include <cstdio>

#include <vector>
#include <string>

#include "argcv/argcv.hh"
#include "argcv/alg/alg.hh"
#include "argcv/ml/corpus/corpus.hh"
#include "argcv/ml/corpus/ds.hh"
#include "argcv/random/random.hh"
#include "argcv/string/string.hh"
#include "argcv/string/hash.hh"
#include "argcv/string/uuid.hh"

using argcv::argcv_info;

using argcv::string::blz_hasher;

using argcv::ml::corpus::tf_idf;
using argcv::ml::corpus::dataset_d;

using namespace argcv::string;

int main(int argc, char * argv[]) {
    uuid u1(0x33);
    uuid u2(0x33);
    for(int i = 0 ; i < 8; i ++ ) {
        printf("%c",u1.hex()[i]);
    }
    printf("-");
    for(int i = 8 ; i < 12; i ++ ) {
        printf("%c",u1.hex()[i]);
    }
    printf("-");
    for(int i = 12; i < 16; i ++ ) {
        printf("%c",u1.hex()[i]);
    }
    printf("-");
    for(int i = 16; i < 20; i ++ ) {
        printf("%c",u1.hex()[i]);
    }
    printf("-");
    for(int i = 20; i < 32; i ++ ) {
        printf("%c",u1.hex()[i]);
    }
    printf("\n");
    std::pair<uint64_t,uint64_t> p = u1.pair();
    printf("%s # %llx %llx\n",u1.hex().c_str(),p.first,p.second);
    
    p = u2.pair();
    printf("%s # %llx %llx\n",u2.hex().c_str(),p.first,p.second);
    
    return 0;
}





