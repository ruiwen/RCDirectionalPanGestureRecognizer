////  RCDirectionalPanRecognizer.m
//
//  Created by Ruiwen Chua on 6/23/12.
//  Copyright (c) 2012 thoughtmonkeys. 
//

// Reference taken from http://stackoverflow.com/a/7149691

#import "RCDirectionalPanGestureRecognizer.h"


int const static kDirectionPanThreshold = 5;

@implementation RCDirectionalPanGestureRecognizer

@synthesize direction = _direction;

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	
	NSLog(@"touchesMoved");
	
	CGPoint nowPoint = [[touches anyObject] locationInView:self.view];
	CGPoint prevPoint = [[touches anyObject] previousLocationInView:self.view];

	_moveX += prevPoint.x - nowPoint.x;
	_moveY += prevPoint.y - nowPoint.y;	  
	
	if(self.state == UIGestureRecognizerStatePossible ) {
		if (
			(self.direction == RCPanGestureRecognizerVertical && abs(_moveX) > kDirectionPanThreshold)
			||
			(self.direction == RCPanGestureRecognizerHorizontal && abs(_moveY) > kDirectionPanThreshold)) {

			self.state = UIGestureRecognizerStateCancelled;
			
			_moveX = 0;
			_moveY = 0;
		}
	}
	
	if(self.state == UIGestureRecognizerStateBegan) {
		NSLog(@"State BEGAN");
		_moveX = 0;
		_moveY = 0;
	}

	[super touchesMoved:touches withEvent:event];

	
}

- (void)reset {
    [super reset];
    _moveX = 0;
}


@end
