//
//  HYBSecondBarImageController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBSecondBarImageController.h"
#import "UIViewController+HYBCagetory.h"

@implementation HYBSecondBarImageController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.view.backgroundColor = [UIColor whiteColor];
  [self hyb_navWithLeftImage:@"back" title:@"图片形式" rightImages:@[@"warning", @"clock"] leftClicked:^(UIButton *sender) {
    [self dismissViewControllerAnimated:YES completion:nil];
  } rightClicked:^(NSUInteger atIndex, UIButton *sender) {
    NSLog(@"atIndex: %d", (int)atIndex);
  }];
}

@end
