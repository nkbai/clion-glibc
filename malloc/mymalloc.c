//
// Created by 白 on 2020/9/9.
//

#include <stddef.h>   /* for size_t */
#include <stdlib.h>   /* for getenv(), abort() */
#include <unistd.h>   /* for __libc_enable_secure */




#include <atomic.h>

#include <bits/wordsize.h>
#include <sys/sysinfo.h>


#include <unistd.h>
#include <stdio.h>    /* needed for malloc_stats */
#include <errno.h>

#include <shlib-compat.h>

/* For uintptr_t.  */
#include <stdint.h>

/* For va_arg, va_start, va_end.  */
#include <stdarg.h>

/* For MIN, MAX, powerof2.  */
#include <sys/param.h>

/* For ALIGN_UP et. al.  */
#include <libc-internal.h>


void *__libc_malloc2(size_t bytes);

void __libc_free2(void *mem);

char malloc_buf[1024 * 1024];
typedef struct _mallocInfo {
    size_t size;
    void *address;
} MallocInfo;
#define MYLEN_MALLOC 1024
MallocInfo minfos[MYLEN_MALLOC];
size_t minfo_cnt = 0;
size_t finfo_cnt = 0;
void *finfos[MYLEN_MALLOC];


//gdb时候调用
void clean_mymalloc(void){
    finfo_cnt=0;
    minfo_cnt=0;
}
//gdb时候调用
void print_mymalloc(void){
    size_t i=0;
    printf("malloc_info:\n");
    for(i=0;i<minfo_cnt;i++){
        printf("i=%d,size= %d,malloc address= %p\n",i,minfos[i].size,minfos[i].address);
    }
    printf("free_info:\n");
    for(i=0;i<finfo_cnt;i++){
        printf("i=%d,free address= %p\n",i,finfos[i]);
    }
}