//
//  ViewController.m
//  Demo
//
//  Created by huangyibiao on 15/9/6.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "ViewController.h"
#import "UIViewController+HYBCagetory.h"
#import "HYBFirstController.h"
#import "HYBSecondController.h"
#import "HYBNavigationController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  HYBFirstController *first = [[HYBFirstController alloc] init];
  HYBNavigationController *firstNav = [[HYBNavigationController alloc] initWithRootViewController:first];
  [firstNav hyb_setTabBarItemWithTitle:@"第一个" selectedImage:nil unSelectedImage:@"warning" selectedTextColor:[UIColor redColor] unSelectedTextColor:nil];
  
  HYBSecondController *second = [[HYBSecondController alloc] init];
  HYBNavigationController *secNav = [[HYBNavigationController alloc] initWithRootViewController:second];
  [secNav hyb_setTabBarItemWithTitle:@"第二个" selectedImage:nil unSelectedImage:@"clock" selectedTextColor:[UIColor redColor] unSelectedTextColor:nil];

  self.viewControllers = @[firstNav, secNav];
}

@end
