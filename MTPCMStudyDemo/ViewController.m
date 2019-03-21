//
//  ViewController.m
//  MTPCMStudyDemo
//
//  Created by Ternence on 2019/3/21.
//  Copyright © 2019 Ternence. All rights reserved.
//

#import "ViewController.h"
#import "pcm16le_splite.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *pcm = @"NocturneNo2inEflat_44.1k_s16le.pcm";
    
    //将PCM16LE双声道数据中左声道和右声道的数据分离成两个文件
    simplest_pcm16le_splite((char *)pcm.UTF8String);
}

@end
