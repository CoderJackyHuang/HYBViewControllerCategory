//
//  HYBFirstBackController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBFirstBackController.h"
#import "UIViewController+HYBCagetory.h"
#import "HYBImagesController.h"

@implementation HYBFirstBackController

- (void)viewDidLoad {
  [super viewDidLoad];
  
   self.view.backgroundColor = [UIColor whiteColor];
  [self hyb_navWithTitle:@"右侧图片按钮" rightImage:@"clock" rightClicked:^(UIButton *sender) {
    HYBImagesController *ic = [[HYBImagesController alloc] init];
    ic.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:ic animated:YES];
  }];
}

@end
