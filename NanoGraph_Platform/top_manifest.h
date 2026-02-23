/* ----------------------------------------------------------------------
 * top_manifest.h
 * -------------------------------------------------------------------- */

#define PLATFORM_ARCH_32BIT
//#define PLATFORM_ARCH_64BIT

#define GRAPH_FROM_PLATFORM             /* the graph comes from the platform (internal), otherwise from the application  */
#define STREAM_FLOAT_ALLOWED            /* selection of integer processing with float_t and double_t */

#define MULTIPROCESSING                 /* enable memory flush conditional codes */

#define CACHE_LINE_BYTE_LENGTH 0        /* 0 for Cortex-M armv6/v7/v8-m */
//#define CACHE_LINE_BYTE_LENGTH 32       /* 32Bytes (CM7/CM55) and set 64bytes for Cortex-A armv8/v9 */

