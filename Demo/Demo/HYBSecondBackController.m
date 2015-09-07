//
//  HYBSecondBackController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBSecondBackController.h"
#import "UIViewController+HYBCagetory.h"
#import "HYBSecondBarImageController.h"
#import "HYBNavigationController.h"

@implementation HYBSecondBackController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.view.backgroundColor = [UIColor whiteColor];
  [self hyb_navWithLeftTitle:@"返回" title:@"第二种" rightTitle:@"下一步" leftClicked:^(UIButton *sender) {
    [self dismissViewControllerAnimated:YES completion:nil];
  } rightClicked:^(UIButton *sender) {
    HYBSecondBarImageController *sb = [[HYBSecondBarImageController alloc] init];
    HYBNavigationController *nav = [[HYBNavigationController alloc] initWithRootViewController:sb];
    [self presentViewController:nav animated:YES completion:^{
      
    }];
  }];
}

@end
