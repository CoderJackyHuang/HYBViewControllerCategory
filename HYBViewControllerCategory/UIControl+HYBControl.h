//
//  UIControl+HYBControl.h
//  Demo
//
//  Created by huangyibiao on 15/9/7.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import <UIKit/UIKit.h>

//
// 值改变时的回调block
//
typedef void(^HYBSwitchValueChangedBlock)(UISwitch *sender);
typedef void(^HYBValueChangedBlock)(id sender);
typedef void(^HYBButtonBlock)(UIButton *sender);

/**
 *  UIControl扩展，用于实现block版本的点击回调
 *
 *  @author huangyibiao
 *  @email  huangyibiao520@163.com
 *  @github https://github.com/632840804
 *  @blog   http://www.hybblog.com/
 *
 *  @note Make friends with me：
 *        QQ:(632840804)
 *        Please tell me your real name when you send message to me.3Q.
 *
 *  @since v0.1
 */
@interface UIControl (HYBControl)

/**
 *  按钮按下事件回调
 */
@property (nonatomic, copy) HYBButtonBlock hyb_touchDown;

/**
 *  按钮松开事件回调
 */
@property (nonatomic, copy) HYBButtonBlock hyb_touchUp;

/**
 *  值改变时的回调block
 */
@property (nonatomic, copy) HYBValueChangedBlock hyb_valueChangedBlock;

@end
