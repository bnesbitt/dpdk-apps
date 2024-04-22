#include <rte_eal.h>
#include <rte_common.h>
#include <rte_ethdev.h>
#include <rte_log.h>
#include <rte_mbuf.h>
#include <rte_udp.h>
#include <rte_tcp.h>
#include <rte_ip.h>
#include <rte_ether.h>

#include <cstdlib>
#include <cstdio>

static int
lcore_hello(__rte_unused void *arg)
{
    unsigned lcore_id;
    lcore_id = rte_lcore_id();
    printf("hello from core %u\n", lcore_id);
    return 0;
}

int main(int argc, char* argv[]) {
    auto ret = rte_eal_init(argc, argv);
    if (ret < 0) {
        rte_exit(EXIT_FAILURE, "EAL Init failed\n");
    }

    printf("DPDK initialized\n");


    unsigned int lcode_id;
    RTE_LCORE_FOREACH_WORKER(lcode_id) {
        /* Simpler equivalent. 8< */
        rte_eal_remote_launch(lcore_hello, nullptr, lcode_id);
        /* >8 End of simpler equivalent. */
    }

    lcore_hello(nullptr);
    rte_eal_mp_wait_lcore();

    argc -= ret;
    argv += ret;

    /* Check that there is an even number of ports to send/receive on. */
    auto nb_ports = rte_eth_dev_count_avail();
    if (nb_ports < 2 || (nb_ports & 1)) {
        printf("Number of ports = %d\n", nb_ports);
        rte_exit(EXIT_FAILURE, "Error: number of ports must be even\n");
    }

    printf("Number of ports available = %d\n", nb_ports);

    rte_eal_cleanup();
}

