cmake_minimum_required(VERSION 3.27)

project(detect-pkts)
set(CMAKE_CXX_STANDARD 17)

add_executable(detect-pkts detect_pkts.cpp)

target_include_directories(detect-pkts PUBLIC "/usr/include/dpdk")

target_link_libraries(detect-pkts PUBLIC
                      -lrte_node
                      -lrte_graph
                      -lrte_flow_classify
                      -lrte_pipeline
                      -lrte_table
                      -lrte_pdump
                      -lrte_port
                      -lrte_fib
                      -lrte_ipsec
                      -lrte_vhost
                      -lrte_stack
                      -lrte_security
                      -lrte_sched
                      -lrte_reorder
                      -lrte_rib
                      -lrte_dmadev
                      -lrte_regexdev
                      -lrte_rawdev
                      -lrte_pcapng
                      -lrte_member
                      -lrte_lpm
                      -lrte_latencystats
                      -lrte_ip_frag
                      -lrte_gso
                      -lrte_gro
                      -lrte_eventdev
                      -lrte_efd
                      -lrte_distributor
                      -lrte_cryptodev
                      -lrte_compressdev
                      -lrte_cfgfile
                      -lrte_bpf
                      -lrte_bitratestats
                      -lrte_bbdev
                      -lrte_acl
                      -lrte_timer
                      -lrte_hash
                      -lrte_metrics
                      -lrte_cmdline
                      -lrte_pci
                      -lrte_ethdev
                      -lrte_meter
                      -lrte_net
                      -lrte_mbuf
                      -lrte_mempool
                      -lrte_rcu
                      -lrte_ring
                      -lrte_eal
                      -lrte_telemetry
                      -lrte_kvargs)

target_compile_options(detect-pkts PUBLIC -O3 -ggdb3 -Wall -Werror)

