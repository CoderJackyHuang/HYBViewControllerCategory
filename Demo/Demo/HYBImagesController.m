//
//  HYBImagesController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBImagesController.h"
#import "UIViewController+HYBCagetory.h"

@implementation HYBImagesController

- (void)viewDidLoad {
  [super viewDidLoad];
  
   self.view.backgroundColor = [UIColor whiteColor];
  [self hyb_navWithTitle:@"图片数组" rightImages:@[@"warning", @"clock"] rightClicked:^(NSUInteger atIndex, UIButton *sender) {
    NSLog(@"atIndex: %d", (int)atIndex);
  }];
}

@end
