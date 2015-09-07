//
//  UIViewController+HYBCagetory.h
//  Demo
//
//  Created by huangyibiao on 15/9/6.
//  Copyright © 2015年 huangyibiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIControl+HYBControl.h"

/**
 * 数组按钮点击时的block
 *
 * @param atIndex 点击的按钮在数组中的索引
 * @param sender  被点击的按钮对象
 */
typedef void(^HYBButtonArrayBlock)(NSUInteger atIndex, UIButton *sender);

/**
 *  UIViewController的常用扩展，包括导航配置API和TabbarItem配置API
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
@interface UIViewController (HYBCagetory)

#pragma mark - 全局配置导航按钮样式
/**
 * 配置导航中的按钮的样式，不要求每个都传
 * 如果不传，表示不需要，则使用默认
 * 如果cornerRadius为0.0，则表示不添加圆角；如果borderColor为nil，表示不添加边框颜色
 * 此方法可以在AppDelegate中调用，只需要调用一次
 */
+ (void)hyb_navButtonStyleWithTextColor:(UIColor *)textColor
                        backgroundColor:(UIColor *)backgroundColor
                                   font:(UIFont *)font
                            borderColor:(UIColor *)borderColor
                           cornerRadius:(CGFloat)cornerRadius;

#pragma mark - UINavigationBar全局配置
/**
 * 配置导航条样式，适配iOS6.0
 *
 * @param backImage 左侧返回按钮的图片名称或者图片对象，也可以传nil；若传nil，表示不替换
 * @param shadowImage 导航的shadowImage，可传nil
 * @param tintColor 左侧返回按钮的箭头颜色
 * @param barTintColor 与tintColor对应
 * @param titleColor 导航标题颜色
 * @param titleFont 导航标题字体
 * @param hideBackTitle 是否隐藏左侧返回按钮的文字
 *
 * @note 此API仅对直接或者间接继承于UINavigationController的控制器才有效
 */
- (void)hyb_configNavBarWithBackImage:(id)backImage
                          shadowImage:(id)shadowImage
                            tintColor:(UIColor *)tintColor
                         barTintColor:(UIColor *)barTintColor
                           titleColor:(UIColor *)titleColor
                            titleFont:(UIFont *)titleFont
                        hideBackTitle:(BOOL)hideBackTitle;

#pragma mark - UITabBarItem
/**
 * 创建一个UITabBarItem对象，并赋值给controller。使用场景：一般是导航控制器类调用。
 * 此API适配了IOS6.0及其以上版本
 *
 * @param title 标题
 * @param selectedImage 选中时的图片名称或者图片对象
 * @param unSelectedImage 普通状态下的图片名称或者图片对象
 * @param selectedTextColor 选中时的标题颜色
 * @param unSelectedTextColor 普通状态下的标题颜色
 */
- (void)hyb_setTabBarItemWithTitle:(NSString *)title
                     selectedImage:(id)selectedImage
                   unSelectedImage:(id)unSelectedImage
                 selectedTextColor:(UIColor *)selectedTextColor
               unSelectedTextColor:(UIColor *)unSelectedTextColor;

/**
 * 创建一个UITabBarItem对象，并赋值给controller。使用场景：一般是导航控制器类调用。
 * 此API适配了IOS6.0及其以上版本
 *
 * @param title 标题
 * @param selectedImage 选中时的图片名称或者图片对象
 * @param unSelectedImage 普通状态下的图片名称或者图片对象
 * @param selectedTextColor 选中时的标题颜色
 * @param unSelectedTextColor 普通状态下的标题颜色
 * @param selectedFont 选中时的标题字体
 * @param unSelectedFont 普通状态下的标题字体
 */
- (void)hyb_setTabBarItemWithTitle:(NSString *)title
                     selectedImage:(id)selectedImage
                   unSelectedImage:(id)unSelectedImage
                 selectedTextColor:(UIColor *)selectedTextColor
               unSelectedTextColor:(UIColor *)unSelectedTextColor
                      selectedFont:(UIFont *)selectedFont
                    unSelectedFont:(UIFont *)unSelectedFont;

#pragma mark - UINavigationBar or UINavigationItem
/**
 * 系统导航配置，只显示标题
 *
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 */
- (void)hyb_navWithTitle:(id)title;

/**
 * 系统导航配置，只显示标题和右标题按钮
 *
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitle 右按钮标题
 * @param rightClicked 右按钮点击回调
 */
- (void)hyb_navWithTitle:(id)title rightTitle:(id)rightTitle rightClicked:(HYBButtonBlock)rightBlock;

/**
 * 系统导航配置，只显示标题和右标题数组按钮
 *
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitles 右按钮标题数组，显示顺序按数组顺序的索引，由小到大
 * @param rightClicked 右按钮点击回调
 */
- (void)hyb_navWithTitle:(id)title rightTitles:(NSArray *)rightTitles rightClicked:(HYBButtonArrayBlock)rightBlock;

/**
 * 系统导航配置，只显示标题和右图片按钮
 *
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImage 右按钮图片，可以是UIImage类型，也可以是图片名称（NSString类型）
 * @param rightClicked 右按钮点击回调
 */
- (void)hyb_navWithTitle:(id)title rightImage:(id)rightImage rightClicked:(HYBButtonBlock)rightBlock;

/**
 * 系统导航配置，只显示标题和右标题按钮
 *
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImages 右按钮图片数组，显示顺序按数组顺序的索引，由小到大，可以是UIImage类型，也可以是
 *                    图片名称（NSString类型），但是数组的类型要求一致
 * @param rightClicked 右按钮点击回调
 */
- (void)hyb_navWithTitle:(id)title rightImages:(NSArray *)rightImages rightClicked:(HYBButtonArrayBlock)rightBlock;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftTitle 左侧返回按钮标题
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param leftClicked 点击左侧返回按钮的回调
 */
- (void)hyb_navWithLeftTitle:(id)leftTitle title:(id)title leftClicked:(HYBButtonBlock)leftClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftImage 左侧返回按钮图片，可以是图片对象，也可以是图片名称
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param leftClicked 点击左侧返回按钮的回调
 */
- (void)hyb_navWithLeftImage:(id)leftImage title:(id)title leftClicked:(HYBButtonBlock)leftClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftTitle 左侧返回按钮标题
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitle 右标题按钮，如“确定”或者“保存”
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftTitle:(id)leftTitle
                       title:(id)title
                  rightTitle:(id)rightTitle
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftTitle 左侧返回按钮标题
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitle 右标题按钮，如“确定”或者“保存”
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftTitle:(id)leftTitle
                       title:(id)title
                 rightTitles:(NSArray *)rightTitles
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonArrayBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftImage 左侧返回按钮图片，可以是图片对象，也可以是图片名称
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitle 右标题按钮，如“确定”或者“保存”
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftImage:(id)leftImage
                       title:(id)title
                  rightTitle:(id)rightTitle
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftImage 左侧返回按钮图片，可以是图片对象，也可以是图片名称
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightTitles 右标题数组按钮，如“确定”或者“保存”
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftImage:(id)leftImage
                       title:(id)title
                 rightTitles:(id)rightTitles
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonArrayBlock)rightClicked;


/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftTitle 左侧返回按钮标题
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImage 右图片按钮，可以传UIImage对象，也可以传图片名称
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftTitle:(id)leftTitle
                       title:(id)title
                  rightImage:(id)rightImage
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftTitle 左侧返回按钮标题
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImages 右图片数组按钮，可以传UIImage对象，也可以传图片名称
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftTitle:(id)leftTitle
                       title:(id)title
                 rightImages:(NSArray *)rightImages
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonArrayBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftImage 左侧返回图片按钮
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImage 右图片按钮，可以传UIImage对象，也可以传图片名称
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftImage:(id)leftImage
                       title:(id)title
                  rightImage:(id)rightImage
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonBlock)rightClicked;

/**
 * 系统导航配置，只显示标题和返回按钮，此API用于定制非默认返回按钮，通常是用模态呈现方式呈现的界面导航，需要点击“取消“
 *
 * @param leftImage 左侧返回图片按钮
 * @param title 可以是UIView类型，也可以是NSString类型，导航的标题
 * @param rightImages 右图片数组按钮，可以传UIImage对象，也可以传图片名称
 * @param leftClicked 点击左侧返回按钮的回调
 * @param rightClicked 点击右侧按钮的回调
 */
- (void)hyb_navWithLeftImage:(id)leftImage
                       title:(id)title
                 rightImages:(NSArray *)rightImages
                 leftClicked:(HYBButtonBlock)leftClicked
                rightClicked:(HYBButtonArrayBlock)rightClicked;

/**
 * 更新导航标题
 *
 * @param title 导航标题，可以是名称，也可以是UIView控件
 */
- (void)updateTitle:(id)title;

@end
