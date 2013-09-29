//
//  RCDirectionalPanRecognizer.h
//
//  Created by Ruiwen Chua on 6/23/12.
//  Copyright (c) 2012 thoughtmonkeys. 
//

// Reference taken from http://stackoverflow.com/a/7149691

#import <UIKit/UIKit.h>
#import <UIKit/UIGestureRecognizerSubclass.h>


typedef enum {
    RCPanGestureRecognizerVertical,
    RCPanGestureRecognizerHorizontal
} RCPanGestureRecognizerDirection;


@interface RCDirectionalPanGestureRecognizer : UIPanGestureRecognizer {
	int _moveX;
	int _moveY;
	RCPanGestureRecognizerDirection _direction;
}

@property (nonatomic, assign) RCPanGestureRecognizerDirection direction;

@end
