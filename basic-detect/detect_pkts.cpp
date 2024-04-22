#include <rte_eal.h>
#include <rte_common.h>

#include <cstdlib>
#include <cstdio>

int main(int argc, char* argv[]) {
    auto ret = rte_eal_init(argc, argv);
    if (ret < 0) {
        rte_exit(EXIT_FAILURE, "EAL Init failed\n");
    }

    printf("DPDK initialized\n");

    exit(0);
}

