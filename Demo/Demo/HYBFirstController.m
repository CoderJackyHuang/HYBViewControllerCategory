//
//  HYBFirstController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBFirstController.h"
#import "UIViewController+HYBCagetory.h"
#import "HYBFirstBackController.h"

@implementation HYBFirstController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.view.backgroundColor = [UIColor whiteColor];
  [self hyb_navWithTitle:@"第一个" rightTitle:@"下一步" rightClicked:^(UIButton *sender) {
    HYBFirstBackController *fb = [[HYBFirstBackController alloc] init];
    fb.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:fb animated:YES];
  }];
}

@end
