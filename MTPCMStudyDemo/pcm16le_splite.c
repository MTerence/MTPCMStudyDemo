//
//  pcm16le_splite.c
//  MTPCMStudyDemo
//
//  Created by Ternence on 2019/3/21.
//  Copyright © 2019 Ternence. All rights reserved.
//

#include "pcm16le_splite.h"
#include <stdlib.h>

//函数可以将PCM16LE双声道数据中左声道和右声道的数据分离成两个文件

/**
 从代码可以看出，PCM16LE双声道数据中左声道和右声道的采样值是间隔存储的。每个采样值占用2Byte空间。代码运行后，会把NocturneNo2inEflat_44.1k_s16le.pcm的PCM16LE格式的数据分离为两个单声道数据：
 
 output_l.pcm：左声道数据。
 output_r.pcm：右声道数据。
 */
int simplest_pcm16le_splite(char *url)
{
    
    /**
     c语言中在当前目录下打开一个文件
     
      url 被打开的文件名
     "rb+" 使用文件方式 rb+表示打开一个二进制文件，文件必须存在，允许读写
     "wb+" 新建一个二进制文件，已存在的文件将被删除，允许读写
     
     文件使用方式由r,w,a,t,b，+六个字符拼成，各字符的含义是：
     r(read): 只读
     w(write): 只写
     a(append): 追加
     t(text): 文本文件，可省略不写
     b(binary): 二进制文件
     +: 读和写
     */
    
    FILE *fp  = fopen("NocturneNo2inEflat_44.1k_s16le.pcm", "rb+");
    FILE *fp1 = fopen("output_l.pcm", "wb+");
    FILE *fp2 = fopen("output_r.pcm", "wb+");
    
    /**
     该函数分配了4个字节，并返回了指向这块内存的指针。如果分配失败，则返回一个空指针（NULL）。
     在 C 语言中，程序中 malloc 等内存分配函数的使用次数一定要和 free 相等，并一一配对使用
     */
    unsigned char *sample= (unsigned char *)malloc(sizeof(4));
    
    
    /**
     fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 从给定流 stream 读取数据到 ptr 所指向的数组中。
     fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) 把 ptr 所指向的数组中的数据写入到给定流 stream 中
     ptr -- 这是指向带有最小尺寸 size*nmemb 字节的内存块的指针。
     size -- 这是要读取的每个元素的大小，以字节为单位。
     nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
     stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输入流。
     */
    while (!feof(fp)) {
        
        fread(sample, 1, 4, fp);
        fwrite(sample, 1, 2, fp1);
        fwrite(sample+2, 1, 2, fp2);
    }
    
    /**
    void free(void *ptr) 释放之前调用 calloc、malloc 或 realloc 所分配的内存空间。
    ptr -- 指针指向一个要释放内存的内存块，该内存块之前是通过调用 malloc、calloc 或 realloc 进行分配内存的。如果传递的参数是一个空指针，则不会执行任何动作。
     
    fclose(FILE *stream) 关闭流 stream。刷新所有的缓冲区。
    stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了要被关闭的流
    如果流成功关闭，则该方法返回零。如果失败，则返回 EOF
     */
    free(sample);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
