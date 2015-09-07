//
//  HYBSecondController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBSecondController.h"
#import "HYBSecondBackController.h"
#import "UIViewController+HYBCagetory.h"
#import "HYBNavigationController.h"

@implementation HYBSecondController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.view.backgroundColor = [UIColor whiteColor];
[self hyb_navWithTitle:@"第二个" rightTitle:@"下一步" rightClicked:^(UIButton *sender) {
  HYBSecondBackController *sb = [[HYBSecondBackController alloc] init];
  HYBNavigationController *nav = [[HYBNavigationController alloc] initWithRootViewController:sb];
  [self presentViewController:nav animated:YES completion:nil];
}];
  
  
}

@end
