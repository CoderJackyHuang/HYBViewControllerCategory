//
//  HYBNavigationController.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "HYBNavigationController.h"
#import "UIViewController+HYBCagetory.h"

@implementation HYBNavigationController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  [self hyb_configNavBarWithBackImage:@"back"
                          shadowImage:nil
                            tintColor:[UIColor blueColor]
                         barTintColor:[UIColor greenColor]
                           titleColor:[UIColor blackColor]
                            titleFont:[UIFont systemFontOfSize:17]
                        hideBackTitle:YES];
}

@end
