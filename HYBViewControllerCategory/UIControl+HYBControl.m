//
//  UIControl+HYBControl.m
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import "UIControl+HYBControl.h"
#import <objc/runtime.h>

// TouchDown/TouchUp事件的key
static const void *s_HYBButtonTouchDownKey = "s_HYBButtonTouchDownKey";
static const void *s_HYBButtonTouchUpKey = "s_HYBButtonTouchUpKey";
static const void *s_HYBValueChangedKey = "s_HYBValueChangedKey";

@implementation UIControl (HYBControl)

- (void)setHyb_touchDown:(HYBButtonBlock)touchDown {
  objc_setAssociatedObject(self, s_HYBButtonTouchDownKey, touchDown, OBJC_ASSOCIATION_COPY);
  
  [self removeTarget:self action:@selector(onTouchDown:) forControlEvents:UIControlEventTouchDown];
  
  if (touchDown) {
    [self addTarget:self action:@selector(onTouchDown:) forControlEvents:UIControlEventTouchDown];
  }
}

- (HYBButtonBlock)hyb_touchDown {
  HYBButtonBlock downBlock = objc_getAssociatedObject(self, s_HYBButtonTouchDownKey);
  return downBlock;
}

- (void)setHyb_touchUp:(HYBButtonBlock)touchUp {
  objc_setAssociatedObject(self, s_HYBButtonTouchUpKey, touchUp, OBJC_ASSOCIATION_COPY);
  
  [self removeTarget:self action:@selector(onTouchUp:) forControlEvents:UIControlEventTouchUpInside];
  
  if (touchUp) {
    [self addTarget:self action:@selector(onTouchUp:) forControlEvents:UIControlEventTouchUpInside];
  }
}

- (HYBButtonBlock)hyb_touchUp {
  HYBButtonBlock upBlock = objc_getAssociatedObject(self, s_HYBButtonTouchUpKey);
  return upBlock;
}

- (void)setHyb_valueChangedBlock:(HYBValueChangedBlock)valueChangedBlock {
  objc_setAssociatedObject(self, s_HYBValueChangedKey, valueChangedBlock, OBJC_ASSOCIATION_COPY);
  
  [self removeTarget:self action:@selector(onValueChanged:) forControlEvents:UIControlEventTouchUpInside];
  
  if (valueChangedBlock) {
    [self addTarget:self action:@selector(onValueChanged:) forControlEvents:UIControlEventValueChanged];
  }
}

- (HYBValueChangedBlock)hyb_valueChangedBlock {
  HYBValueChangedBlock block = objc_getAssociatedObject(self, s_HYBValueChangedKey);
  return block;
}

- (void)onValueChanged:(id)sender {
  HYBValueChangedBlock block = [self hyb_valueChangedBlock];
  
  if (block) {
    block(sender);
  }
}

- (void)onTouchUp:(UIButton *)sender {
  HYBButtonBlock touchUp = [self hyb_touchUp];
  
  if (touchUp) {
    touchUp(sender);
  }
}

- (void)onTouchDown:(UIButton *)sender {
  HYBButtonBlock touchDown = [self hyb_touchDown];
  
  if (touchDown) {
    touchDown(sender);
  }
}

@end
