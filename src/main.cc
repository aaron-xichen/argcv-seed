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

int y(std::vector<double> x) {
    // printf("%f \n",x[0] * 0.2 + x[1] * 0.8 + x[2] * 0.3);
    if (x[0] * 0.1 + x[1] * 0.8 - x[2] * 0.3 - x[3] * 0.1 + x[4] * 0.2 + 0.2 > 0.5) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char* argv[]) {
    perceptron mml;
    for (int i = 0; i < 2600; i++) {
        double x1 = (random_int() % 100) + 0.0001;
        double x2 = (random_int() % 100) + 0.0001;
        double x3 = (random_int() % 100) + 0.0001;
        double x4 = (random_int() % 100) + 0.0001;
        double x5 = (random_int() % 100) + 0.0001;
        std::vector<double> x
            = {(2.0 / x1) - 1, (2.0 / x2) - 1, (2.0 / x3) - 1, (2.0 / x4) - 1, (2.0 / x5) - 1};
        // printf("## %f - %f - %f \n",(2.0 / random_int()) - 1, (2.0 / random_int()) - 1, (2.0 /
        // random_int()) - 1);
        mml.add(x, y(x));
    }

    mml.learn();
    mml.dump();

    aprf f;
    size_t sz = 0;
    bool listed = false;

    for (double i = -1; i < 1; i += 0.1) {
        for (double j = -1; j < 1; j += 0.1) {
            for (double k = -1; k < 1; k += 0.1) {
                for (double m = -1; m < 1; m += 0.1) {
                    for (double n = -1; n < 1; n += 0.1) {
                        std::vector<double> x = {i, j, k, m, n};
                        f.add(mml.predict(x) > 0, y(x) > 0);
                        if (!listed && ((mml.predict(x) > 0) != (y(x) > 0))) {
                            // printf("%f - %f - %f \n", i, j, k);
                            listed = true;
                        }
                        sz++;
                    }
                }
            }
        }
    }

    printf("result :  sz : %zu pre : %f rec : %f ac : %f , f1 : %f \n", sz, f.precision(), f.recall(),
           f.accuracy(), f.f1());

    return 0;
}
