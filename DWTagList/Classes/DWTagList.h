//
//  DWTagList.h
//
//  Created by Dominic Wroblewski on 07/07/2012.
//  Copyright (c) 2012 Terracoding LTD. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DWTagView;
@class DWTagAppearance;

@protocol DWTagListDelegate <NSObject>

@required

- (void)selectedTag:(NSString*)tagName;

@end

@interface DWTagList : UIScrollView
{
    UIView      *view;
    NSArray     *textArray;
    CGSize      sizeFit;
    UIColor     *lblBackgroundColor;
}

@property (nonatomic) BOOL viewOnly;
@property (nonatomic, strong) UIView *view;
@property (nonatomic, strong) NSArray *textArray;
@property (nonatomic, weak) id<DWTagListDelegate> tagDelegate;
@property (nonatomic, strong) UIColor *highlightedBackgroundColor;
@property (nonatomic) BOOL automaticResize;
@property (nonatomic, retain) UIFont *font;
@property (nonatomic, assign) CGFloat labelMargin;
@property (nonatomic, assign) CGFloat bottomMargin;
@property (nonatomic, assign) CGFloat horizontalPadding;
@property (nonatomic, assign) CGFloat verticalPadding;
@property (nonatomic, assign) CGFloat minimumWidth;
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) CGColorRef borderColor;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, assign) UIColor *textColor;
@property (nonatomic, assign) UIColor *textShadowColor;
@property (nonatomic, assign) CGSize textShadowOffset;

- (void)setTagBackgroundColor:(UIColor *)color;
- (void)setTagHighlightColor:(UIColor *)color;
- (void)setTags:(NSArray *)array;
- (void)setTags:(NSArray *)array selectedTags:(NSArray*) selectedTags;
- (void)display;
- (CGSize)fittedSize;


@end

@interface DWTagAppearance : NSObject

@property(nonatomic, assign) CGColorRef borderColor;
@property(nonatomic, strong) UIColor *textShadowColor;
@property(nonatomic, strong) UIColor *textColor;
@property(nonatomic, strong) UIColor *backgroundColor;
@property(nonatomic, assign) BOOL selected;

@end


@interface DWTagView : UIView

@property (nonatomic, strong) UIButton      *button;
@property (nonatomic, strong) UILabel       *label;

- (void)updateWithString:(NSString*)text
                    font:(UIFont*)font
      constrainedToWidth:(CGFloat)maxWidth
                 padding:(CGSize)padding
            minimumWidth:(CGFloat)minimumWidth;

- (void)setLabelText:(NSString*)text;
- (void)setCornerRadius:(CGFloat)cornerRadius;
- (void)setBorderColor:(CGColorRef)borderColor;
- (void)setBorderWidth:(CGFloat)borderWidth;
- (void)setTextColor:(UIColor*)textColor;
- (void)setTextShadowColor:(UIColor*)textShadowColor;
- (void)setTextShadowOffset:(CGSize)textShadowOffset;

@end
